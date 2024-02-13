#include "complex0.h"
complex::complex(void)
{
  this->imag_p = 1.1;
  this->real_p = 1.2;
}
complex::complex(double val)
{
  this->imag_p = val;
  this->real_p = val;
}
complex::complex(double real, double imaginary)
{
  imag_p = imaginary;
  real_p = real;
}
complex::~complex(void)
{
  // printf("\n<DESTRUCTOR>\n");
}
complex operator+(const complex  & n1, const complex  & n2)
{
  complex new_num;
  new_num.imag_p = n1.imag_p + n2.imag_p;
  new_num.real_p = n1.real_p + n2.real_p;
  return new_num;
}

complex complex::operator-(double value)
{
  // this->imag_p -= value;//do not create a new obj, return the current one, but this will violate the 
  // //conformities.
  // this->real_p -= value;
  // return *this;
  complex new_obj;
  new_obj.real_p = this->real_p * value;
  new_obj.imag_p = this->imag_p * value;
  return new_obj;
}

complex operator~(complex & s1)
{
  s1.imag_p = -s1.imag_p;
  s1.real_p = -(s1.real_p);
  return s1;
}
std::ostream & operator<<(std::ostream & os, const complex & s1)
{
  using namespace std;
  os << "(" << s1.real_p << "," << s1.imag_p << "i)";
  return os;
}
complex operator-(double val, const complex & n1)
{
  complex new_obj;
  new_obj.real_p = val * n1.real_p;
  new_obj.imag_p = val * n1.imag_p;
  return new_obj;
}

complex operator-(const complex & n1, const complex & n2)
{
  complex new_obj;
  new_obj.imag_p = n1.imag_p - n2.imag_p;
  new_obj.real_p = n1.real_p - n2.real_p;
  return new_obj;
}

complex operator*(const complex & n1, const complex & n2)
{
  complex new_obj;
  new_obj.real_p = n1.real_p * n2.real_p;
  new_obj.imag_p = n1.imag_p * n2.imag_p;
  return new_obj;
}
std::istream & operator>>(std::istream & intput_stream, complex & s1)
{
  intput_stream >> s1.real_p;
  intput_stream >> s1.imag_p;
  return intput_stream;
}


