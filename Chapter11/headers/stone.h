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
    Stonewt operator*(double v) const;//the first version obj * double
    // friend Stonewt operator*(Stonewt & s_1, double n);//the second version
    //the convertion functions:
    operator int(void) const;//a convertion function, promises the compiler, not to change the original object.
    operator double(void) const;
    //provide addition for the Stonewt class:
    // Stonewt operator+(const Stonewt & s2) const;//we can't use two opearotrs, because plus cannot be 
    //overloaded with three operands
    //implement the same thing as a friend function:
    friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator*(double val, const Stonewt & stone_obj); // double * obj
    //create a conversion method from Stone to int & to double:
    // operator double(void) const;//to convert Stonewt to double
    // operator int(void) const;//to convert Stonewt to int

    //can we convert Stonewt to double??
    //1. method:
    // friend double operator+(const Stonewt & s1, const Stonewt & s2);
    //the func lets the conversion operator handle the conversion form double to Stonewt:
    //so this is possible: double + Stonewt 
    //and this : Stonewt + double

    //2.method: 
    //overload the +operator further, so that it will add double + Stonewt, 
    //because currently it can only add Stonewt + double, because the methods are applied on the object
    //itself, not the double type:
    // double operator+(double n) const;//add double to Stonewt
    // friend double operator+(double n, const Stonewt & s1);//the problem is that this func
    //and the func above are identical. You have to understand, that this will confuse the compiler.
  };
  Stonewt operator+(const Stonewt &s1, const Stonewt &s2);
  Stonewt operator*(double val, const Stonewt & stone_obj); // double * obj

}
#endif

