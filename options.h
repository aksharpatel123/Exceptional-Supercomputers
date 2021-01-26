#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <iostream>

class Options{
	
	protected:
		std::string _name;
		double _cost;

	public:
		Options(std::string name, double cost);
		virtual ~Options();
		double cost();
		virtual std::string to_string() const;

		Options(std::istream& ist);
		virtual void save(std::ostream& ost);

		friend std::ostream& operator<<(std::ostream& ost, const Options& options);
};

#endif
