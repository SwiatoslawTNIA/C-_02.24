#ifndef STOCK_
#define STOCK_
#include <iostream>

class Stock
{
private:
  std::string company;
  long shares;
  double share_val;
  double total_val;
  // int value = 14;//if the var is declared here, it cannot be accessed through it's object
  void set_tot(void) { total_val = shares * share_val;}
public:
  //constructors:(func overloading)
  Stock(const std::string & co, long n = 0, double pr = 0.0);
  Stock(void);
  //destructors:
  ~Stock(void);
  //public functions:
  // void acquire(const std::string & co, long n, double pr);
  void sell(long num, double price);
  void update(double price);
  void buy(long num, double price);
  void show(void) const;
};//semicolon at the end
#endif
