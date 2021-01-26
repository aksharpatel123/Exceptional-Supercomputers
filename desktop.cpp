#include "desktop.h"

Desktop::Desktop() {}

void Desktop::add_option(Options& option) {
	options.push_back(&option);
}

double Desktop::price() {
    double prc = 0.0;
    for(auto o : options) prc += o->cost();
    return prc;
}

Desktop::Desktop(std::istream& ist) {
	int temp;
	ist >> temp; ist.ignore(32767, '\n');
    while(temp--) {
    	options.push_back(new Options{ist});
    }
}

void Desktop::save(std::ostream& ost) {
	ost << options.size() << '\n';
	for(auto st : options){
		st->save(ost);
	}
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}
