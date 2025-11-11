#include "class.h"
#include <iostream>

Base::Base() {}
Base::Base(std::string d, double p, std::string b) : date_(d), price_(p), brand_(b) {}

void Base::setdate(std::string d) {date_ = d;}
void Base::setprice(double p) {price_ = p;}
void Base::setbrand(std::string b) {brand_ = b;}

std::string Base::getdate() const {return date_;}
double Base::getprice() const {return price_;}
std::string Base::getbrand() const {return brand_;}

void Base::resetdate_() {date_ = "yyyy-mm-dd";}

void CPU::info() const {
  std::cout << "[CPU] " << this->getbrand() << " " << cores_ << "c "
            << freq_ << "GHz " << cache_ << "MB, "
            << "date=" << getdate() << ", price=" << getprice() << "\n";
}

void Computer::info() const {
  std::cout << "[PC ] " << getbrand()
              << ", date=" << getdate()
              << ", price=" << getprice() << "\n";
  cpu_.info();
}

