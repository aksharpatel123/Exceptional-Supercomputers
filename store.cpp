#include "store.h"

// Store Class here

Store::Store() {}

Store::Store(std::istream& ist) {

    std::string str;
    int vsize;

    std::getline(ist, str);
    if(str != ELSA_NAME) throw std::runtime_error{"Not supported"};
    std::getline(ist, str);
    if(str != ELSA_FILE_VERSION) throw std::runtime_error{"Wrong version"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) customers.push_back(Customer{ist});
    if(!ist) throw std::runtime_error{"Bad Customer Content"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) options.push_back(new Options{ist});
    if(!ist) throw std::runtime_error{"Bad Options Content"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) desktops.push_back(Desktop{ist});
    if(!ist) throw std::runtime_error{"Bad Product Content"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) orders.push_back(Order{ist});
    if(!ist) throw std::runtime_error{"Bad Order Content"};
}

void Store::save(std::ostream& ost) {

	ost << ELSA_NAME << "\n";
    ost << ELSA_FILE_VERSION << "\n";

    ost << customers.size() << '\n';
	for(auto text : customers){
		text.save(ost);
	}
	
	ost << options.size() << '\n';
	for(auto text : options){
		text->save(ost);
	}

	ost << desktops.size() << '\n';
	for(auto text : desktops){
		text.save(ost);
	}

	ost << orders.size() << '\n';
	for(auto text : orders){
		text.save(ost);
	}

}


void Store::add_customer(Customer& customer) {
	customers.push_back(customer);
}

int Store::num_customers() {
	return customers.size();
}

Customer& Store::customer(int index) {
	return customers.at(index);
}


void Store::add_option(Options& option) {
	// options.push_back(option);
	options.push_back(new Options{option});

}

int Store::num_options() {
	return (options.size());
}

Options& Store::option(int index) {
	return (*options.at(index));
}

int Store::new_desktop() {
	// Desktop newDesktop;
	desktops.push_back(Desktop{});
	return (desktops.size() - 1);
}

void Store::add_option(int option, int desktop) {
	desktops.at(desktop).add_option(*options.at(option));
}

int Store::num_desktops() {
	return (desktops.size());
}


Desktop& Store::desktop(int index) {
	return desktops.at(index);
}
	

int Store::new_order(int customer) {
	// Order newOrder(customer);
	// orders.push_back(newOrder);
	orders.push_back(Order{customers.at(customer)});
	return (orders.size() - 1);
}
		

void Store::add_desktop(int desktop, int order) {
	// desktops[desktop].add_option(options[option]);
	orders.at(order).add_product(desktops.at(desktop));
}


int Store::num_orders() {
	return (orders.size());
}


Order& Store::order(int index) {
	return orders.at(index);
}
