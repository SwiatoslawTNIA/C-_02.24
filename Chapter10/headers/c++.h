#ifndef STOCK_
#define STOCK_
#include <iostream>
#include <cctype>
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
  Stock(void);// a default constructor
  //destructors:
  ~Stock(void);
  const Stock & topval(const Stock & stock1) const;

  //public functions:
  // void acquire(const std::string & co, long n, double pr);
  void sell(long num, double price);
  void update(double price);
  void buy(long num, double price);
  void show(void) const;//show promises not to change the object it refers to
};//semicolon at the end
#endif
