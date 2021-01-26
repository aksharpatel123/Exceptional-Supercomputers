#ifndef __STORE_H
#define __STORE_H

#include "customer.h"
#include "options.h"
#include "desktop.h"
#include "order.h"
#include "ram.h"
#include <fstream>
#include <iostream>

const std::string ELSA_NAME = "ELSA";
const std::string ELSA_VERSION = "0.4.0";
const std::string ELSA_FILE_VERSION = "4.0-plain";

class Store{
	
	private:
		std::vector<Customer> customers;
		std::vector<Options*> options;
		std::vector<Desktop> desktops;
		std::vector<Order> orders;

	public:
		Store();
		Store(std::istream& ist);
		void save(std::ostream& ost);

		void add_customer(Customer& customer);
		int num_customers();
		Customer& customer(int index);
		void add_option(Options& option);
		int num_options();
		Options& option(int index);
		
		int new_desktop();
		void add_option(int option, int desktop);
		int num_desktops();
		Desktop& desktop(int index);
		int new_order(int customer);
		void add_desktop(int desktop, int order);
		int num_orders();
		Order& order(int index);
};

#endif
