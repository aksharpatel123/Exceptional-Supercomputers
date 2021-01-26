#ifndef __RAM_H
#define __RAM_H

#include "options.h"
#include <ostream>

class Ram : public Options {
  public:
    Ram(std::string name, double cost, int _gb);
    virtual ~Ram();
    Ram(std::istream& ist);

    std::string to_string() const override;
    void save(std::ostream& ost) override;
    //friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
  
  protected:
    int _gb;
};

#endif
