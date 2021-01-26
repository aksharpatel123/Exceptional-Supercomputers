#include "order.h"

// Order Class here

Order::Order(Customer& customer) : _customer{customer} {}

Order::~Order() {
	// Destructor
}

int Order::add_product(Desktop& desktop) {
	_products.push_back(&desktop);
	return _products.size() - 1;
}


double Order::price() const {
	double y = 0.0;
	for(auto p : _products){
		y += p->price();
	}
	return y;
}

Order::Order(std::istream& ist) {
	_customer = new Customer{ist};
    int vsize;
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) {
    	_products.push_back(new Desktop{ist});
    }
}

void Order::save(std::ostream& ost) {
	_customer->save(ost);
    ost << _products.size() << '\n';
    for (auto p : _products) {
    	p->save(ost);
    }
}

std::ostream& operator<<(std::ostream& ost, const Order& order) {
    
    ost << "Customer: " << *order._customer;

    for (auto p : order._products){
    	ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
    }
	
	ost << "\nTotal price(in $): $ " << order.price() << '\n';

    return ost;
}
