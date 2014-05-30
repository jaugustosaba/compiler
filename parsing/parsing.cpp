#include "parsing.h"
#include "spec-parser.h"
#include "parser-table.h"
#include "code-generator.h"

namespace parsing {

namespace {

inline
std::ostream& operator<<(std::ostream &out, const Symbol *symbol) {
	auto rule = dynamic_cast<const Rule*>(symbol);
	if (rule != nullptr) {
		out << rule->name;
	} else {
		auto token = dynamic_cast<const Token*>(symbol);
		out << token->name;
	}
	return out;
}

inline
std::ostream& operator<<(std::ostream &out, const Kernel *kernel) {
	const auto &symbols = kernel->production->symbols;
	for (size_t i=0; i<symbols.size(); ++i) {
		if (i == kernel->position) {
			out << ".";
		}
		out << symbols[i];
		if (i + 1 < symbols.size()) {
			out << " ";
		}
	}
	if (kernel->position >= symbols.size()) {
		out << ".";
	}
	return out;
}

} // anonymous namespace

bool Parsing::generate(std::istream &input, std::ostream &output, std::ostream &error) const {
	try {
		auto spec = parse(input);
		spec.computeFirstSet();
		spec.computeLastTokens();
		auto lalr = makeLALR(spec);
		auto table = makeTable(spec, lalr);
		if (table.rrConflicts.size() > 0) {
			error
				<< table.rrConflicts.size()
				<< " reduce-reduce conflicts:" << std::endl << std::endl;
			for (const auto &rr : table.rrConflicts) {
				error
					<< "  " << rr->first << " vs " << rr->second
					<< " for token " << rr->token->name << ": ";
				switch (rr->veredict) {
				case RRVeredict::First:
					error << "first";
					break;
				case RRVeredict::Second:
					error << "second";
					break;
				}
				error << " favored" << std::endl;
			}
			return false;
		}
		if (showSRConflicts) {
			error
				<< table.srConflicts.size()
				<< " shift-reduce conflicts:" << std::endl << std::endl;
			if (showSRConflictItems) {
				for (const auto &sr : table.srConflicts) {
					error << "  " << sr->kernel << " vs " << sr->token->name << ": ";
					switch (sr->veredict) {
					case SRVeredict::Shift:
						error << "shift";
						break;
					case SRVeredict::Reduce:
						error << "reduce";
						break;
					case SRVeredict::Neither:
						error << "neitheir";
						break;
					}
					error << " favored" << std::endl;
				}
			}
		}
		output << CodeGenerator(table, spec);
	} catch (SpecError &e) {
		error
			<< "error parsing spec: '" << e.what() << "'"
			<< " at (" << e.line() << ", " << e.column() << ")" << std::endl;
		return false;
	}
	return true;
}

}



