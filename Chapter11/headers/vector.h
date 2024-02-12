#include <iostream>
#ifndef VECTOR_
#define VECTOR_
namespace VECTOR
{
  class Vector
  {
  public:
    enum Mode{REC, POL};
  private:
    double x;
    double y;
    double mag;
    double ang;
    Mode mode;
    //private methods for settings the coords:
    void set_mag(void);
    void set_ang(void);
    void set_x(void);
    void set_y(void);
  public:
  //constructors and destructors:
    Vector(void);
    Vector(double n1, double n2, Mode form = REC);
    void reset(double n1, double n2, Mode form = REC);
    ~Vector(void);
    double xVal(void) const { return x;};//report the values, const must be before the brackets, it belongs
    //to the prototype
    double yVal(void) const { return y;};
    double magVal(void) const { return mag;};
    double angVal(void) const { return ang;};
    void polarMode(void);//change to polar
    void rectMode(void);//change to rect
    //operator overloading:
    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const;
    Vector operator-() const;
    Vector operator*(double n) const;
    //friends:
    friend Vector operator*(double n, const Vector & a);
    friend std::ostream & operator<<(std::ostream & os, const Vector & v);
  };  
}
#endif


