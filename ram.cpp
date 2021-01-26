#include "ram.h"

Ram::Ram(std::string name, double cost, int gb) : Options::Options(std::istream&) {
	_name = name;
	_cost = cost;
	_gb = gb;
}

Ram::~Ram() {}

Ram::Ram(std::istream& ist) : Options::Options(std::istream&) {
	std::getline(ist, _gb);
    ist >> _gb; 
    ist.ignore(32767, '\n');
}

std::string Ram::to_string() const override {
	return _name + " gb : " + _gb + " ($" + std::to_string(_cost) + ")";
}

void Ram::save(std::ostream& ost) : Options::save(std::ostream&) {
	ost << _name << '\n' << _gb << '\n' << _cost << '\n';
}
