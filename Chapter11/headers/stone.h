#include <iostream>
#ifndef STONEWT_
#define STONEWT_
namespace STONEWT
{
  class Stonewt
  {
  private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pnds_left;
    double pounds;
  public:
    //constructors:
    Stonewt(void);
    explicit Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    ~Stonewt(void);
    void show_lbs(void) const;
    void show_stn(void) const;
    //the convertion functions:
    operator int(void) const;//a convertion function, promises the compiler, not to change the original object.
    operator double(void) const;
    //provide addition for the Stonewt class:
    // Stonewt operator+(const Stonewt & s2) const;//we can't use two opearotrs, because plus cannot be 
    //implement the same thing as a friend function:
    friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
    //overloaded with three operands
  };
  Stonewt operator+(const Stonewt &s1, const Stonewt &s2);
}
#endif

