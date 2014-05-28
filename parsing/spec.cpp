#include "spec.h"

namespace parsing {

namespace {

bool computeFirstSet(Production* production) {
	auto n = production->firstSet.size();
	bool empty = true;
	for (size_t i=0; empty && (i < production->symbols.size()); ++i) {
		empty = false;
		auto symbol = production->symbols[i];
		for (auto token : symbol->firstSet) {
			if (token == nullptr) {
				empty = true;
			} else {
				production->firstSet.insert(token);
			}
		}
	}
	return production->firstSet.size() > n;
}

bool computeFirstSet(Rule* rule) {
	auto n = rule->firstSet.size();
	for (auto &production : rule->productions) {
		if (computeFirstSet(production.get())) {
			rule->firstSet.insert(production->firstSet.begin(), production->firstSet.end());
		}
	}
	return rule->firstSet.size() > n;
}

} // anonymous namespace

void Spec::computeFirstSet() {
	for (auto &token : tokens) {
		token->firstSet.insert(token.get());
	}
	bool updated;
	do {
		updated = false;
		for (auto &rule : rules) {
			if (::parsing::computeFirstSet(rule.get())) {
				updated = true;
			}
		}
	} while (updated);
}

void Spec::computeLastTokens() {
	for (const auto &rule : rules) {
		for (const auto &prod : rule->productions) {
			if (prod->lastToken != nullptr) {
				continue;
			}
			auto &symbols = prod->symbols;
			for (auto i=symbols.size()-1; i >= 0; --i) {
				auto token = dynamic_cast<Token*>(symbols[i]);
				if (token != nullptr) {
					prod->lastToken = token;
					break;
				}
			}
		}
	}
}

} // namespace parsing
