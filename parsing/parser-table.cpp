#include "parser-table.h"

namespace parsing {

ParserTable makeTable(const Spec &spec, const LALR &lalr) {
	ParserTable rs;
    auto tokenCount = spec.tokens.size();
    rs.tokens.resize(tokenCount);
    for (const auto &token : spec.tokens) {
    	rs.tokens[token->id] = token->name;
    }
    auto ruleCount = spec.rules.size();
    rs.rules.resize(ruleCount);
    for (const auto &rule : spec.rules) {
    	rs.rules[rule->id] = rule->name;
    }
    auto stateCount = lalr.states.size();
    rs.actions.resize(stateCount);
    for (size_t state=0; state < stateCount; ++state) {
    	auto &row = rs.actions[state];
    	row.resize(tokenCount);
    	for (auto &action : row) {
    		action = Action{ActionType::Error, 0};
    	}
    }
    rs.gotos.resize(stateCount);
    for (size_t state=0; state<stateCount; ++state) {
    	rs.gotos[state].resize(ruleCount);
    }
    for (const auto &state : lalr.states) {
        for (const auto &pair : state->transitions) {
        	auto symbol = pair.first;
            auto nextState = pair.second;
            if (dynamic_cast<Rule*>(symbol) != nullptr) {
            	auto rule = dynamic_cast<Rule*>(symbol);
            	rs.gotos[state->id][rule->id] = nextState->id;
            } else {
                auto token = dynamic_cast<Token*>(symbol);
                rs.actions[state->id][token->id] = Action{ActionType::Shift, nextState->id};
            }
        }

        std::unordered_map<Production*, size_t> map;
        for (const auto &pair : state->items) {
        	const auto &kernel = pair.first;
            if (kernel.isReduction()) {
                ActionType type;
                size_t value;
                if (kernel.production->rule != nullptr) {
                    type = ActionType::Reduce;
                    auto it = map.find(kernel.production);
                    if (it == map.end()) {
                        auto rule = kernel.production->rule;
                        auto symbolCount = kernel.production->symbols.size();
                        auto action = kernel.production->action;
                        value = rs.reductions.size();
                        Reduction reduction{rule->id, symbolCount, action};
                        rs.reductions.push_back(reduction);
                    } else {
                        value = it->second;
                    }
                } else {
                    type = ActionType::Accept;
                    value = 0;
                }
                for (const auto &token : pair.second) {
                	auto &action = rs.actions[state->id][token->id];
                	switch (action.actionType) {
                	case ActionType::Error:
                		action = Action{type, value};
                		break;
                	case ActionType::Shift: {
                		SRVeredict veredict = SRVeredict::Shift;
                		auto left = kernel.production->lastToken;
                		if (left != nullptr) {
                			if (left->priority > token->priority) {
                				veredict = SRVeredict::Reduce;
                			} else if (left == token) {
                				switch (left->assoc) {
                				case Associativity::Left:
                					veredict = SRVeredict::Reduce;
                					break;
                				case Associativity::Right:
                					veredict = SRVeredict::Shift;
                					break;
                				case Associativity::NoAssoc:
                					veredict = SRVeredict::Neither;
                					break;
                				}
                			}
                		}
                		switch (veredict) {
                		case SRVeredict::Shift:
                			// action already is a shift
                			break;
                		case SRVeredict::Reduce:
                			action = Action{type, value};
                			break;
                		case SRVeredict::Neither:
                			action = Action{ActionType::Error, 0};
                			break;
                		}
                		SRConflictPtr ptr(new SRConflict);
                		ptr->kernel = &kernel;
                		ptr->state = state.get();
                		ptr->token = token;
                		ptr->veredict = veredict;
                		rs.srConflicts.push_back(std::move(ptr));
                		break;
                	}
                	case ActionType::Reduce:
                	case ActionType::Accept: {
                		RRConflictPtr ptr(new RRConflict);
                		auto rule = rs.reductions[action.value].rule;
                		for (const auto &pair : state->items) {
                			const auto &kernel = pair.first;
                			if (kernel.isReduction()
                				&& (kernel.production->rule->id != rule)
                				&& (pair.second.find(token) != pair.second.end()))
                			{
                				ptr->first = &kernel;
                				break;
                			}
                		}
                		ptr->second = &kernel;
                		ptr->state = state.get();
                		ptr->token = token;
                		ptr->veredict = RRVeredict::First;
                		rs.rrConflicts.push_back(std::move(ptr));
                		break;
                	}
                	}
                }
            }
        }
    }

    rs.root = lalr.root->id;
    return rs;
}

} // namespace parsing
