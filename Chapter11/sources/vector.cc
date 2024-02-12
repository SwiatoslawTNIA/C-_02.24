#include "vector.h"
#include <cmath>
using std::cout;
using std::cin;
using std::cerr;
using std::cos;
using std::atan;
using std::atan2;
using std::sin;
using std::sqrt;

const double Rad_to_deg = 45.0 / atan(1.0);
//private methods:
namespace VECTOR
{
  void Vector::set_mag(void)
  {
    mag = sqrt(x * x + y * y);
  }
  void Vector::set_ang(void)
  {
    if(x == 0.0 && y == 0.0)
      ang = 0.0;
    else
      ang = atan2(y, x);
  }
  //set coords:
  void Vector::set_x(void)
  {
    x = mag * cos(ang);
  }
  void Vector::set_y(void)
  {
    y = mag * sin(ang);
  }
  //public methods:
  //constructors and desctructors:
  Vector::Vector(void)
  {
    x = y = mag = ang = 0.0;
    mode = REC;
  }
  Vector::Vector(double n1, double n2, Mode form)
  {
    mode = form;
    if(form == REC)//if the vector form is rectangular
    {
      x = n1;
      y = n2;
      set_mag();
      set_ang();
    }
    else if(form == POL)
    {
      mag = n1;
      ang = n2 / Rad_to_deg;
      set_x();
      set_y();
    }
    else
    {
      cout << "Incorrect third arg to Vector -- ";
      cout << "Vector set to 0";
      x = y = mag = ang = 0.0;
      mode = REC;//default mode
    }
  } //reset vector from rect coords if form is REC ( default), else from polar coords if form is POL
  void Vector::reset(double n1, double n2, Mode form)
  {
    mode = form;
    if(form == REC)
    {
      x = n1;
      y = n2;
      set_mag();
      set_ang();
    }
    else if (form == POL)
    {
      mag = n1;
      ang = n2 / Rad_to_deg;
      set_x();
      set_y();
    }
    else
    {
      cout << "Incorrect third arg to a Vector --";
      cout << "vector set to 0\n";
      x = y = mag = ang = 0.0;
      mode = REC;
    }
  }
  //desctructor:
  Vector::~Vector(void)
  {

  }
  void Vector::polarMode(void)
  {
    mode = POL;//set to polar mode
  }
  void Vector::rectMode(void)
  {
    mode = REC;
  }
  //operator overloading:
  //addition:
  Vector Vector::operator+(const Vector & v) const
  {
      return Vector(x + v.x, y + v.y);
  }
  Vector Vector::operator-(const Vector & v) const
  {
      return Vector(x - v.x, y - v.y);//create new vector with the second constructor
  }
  Vector Vector::operator-(void) const
  {
    return Vector(-x, -y);
  }
  //multiply vector by n:
  //the second vector word is responsible for the class scope, the first is the return value, 
  //in addition to that we have to keep track of the namespace
  Vector Vector::operator*(double n) const
  {
    return Vector(x * n, y * n);
  }
  //friend methods:
  Vector operator*(double n,const Vector & v)
  {
    return v * n;//it's gonna go to the func above transforms to the form v.operator*(n)
  }

  std::ostream & operator<<(std::ostream & os, const Vector & v)
  {
    //depending on the mode:
    if(v.mode == Vector::REC)
    {
      os << "(x,y) = (" << v.x << ", " << v.y << ")";
    }
    else if(v.mode == Vector::POL)
    {
      os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
    }
    else 
      os << "Vector object mode is invalid";
    return os;
  }
}



