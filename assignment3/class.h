
/*
computer
1.cpu
2.ram
3.rom
4.gpu
5.motherboard
6.power
*/

#include <string>

class Base {
public:
  Base();
  Base(std::string d, double p, std::string b);
  virtual ~Base() = default;
  virtual void info() const = 0;
  std::string getdate() const;
  double getprice() const;
  std::string getbrand() const; 
  void resetdate_();
  void setprice(double p);
  void setbrand(std::string b);
private:
  std::string date_;
  double price_;
  std::string brand_;
  void setdate(std::string d);
};

class CPU : public Base{
public:
  CPU(std::string d, double p, std::string b, int c, double f, int cm) :
    Base(std::move(d), p, std::move(b)), cores_(c), freq_(f), cache_(cm) {}

  void info() const override;
private:
  int cores_;
  double freq_;
  int cache_;
};


class Computer : public Base {
public:
  Computer(std::string d, double p, std::string b, CPU cpu) :
    Base(std::move(d), p, std::move(b)), cpu_(std::move(cpu)) {}

  void info() const override;
private:
  CPU cpu_;
};
