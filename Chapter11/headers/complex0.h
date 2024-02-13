#include <iostream>
#ifndef complex_
#define complex_
class complex
{
  double imag_p;
  double real_p;
public:
  complex(void);
  complex(double val);
  complex(double real, double imaginary);
  ~complex(void);
  // complex add(const complex  & n1,const complex  & n2);
  // complex subtract(const complex  & n1,const complex  & n2);
  // complex multiply(const complex  & n1,const complex  & n2);
  
  friend complex operator+(const complex  & n1, const complex  & n2);
  // friend complex operator-(const complex  & n1, const complex  & n2);
  complex operator-(double value);
  friend std::istream & operator>>(std::istream & is, complex & s1);//we don't want to mess with the 
  //obj class istream.
  friend complex operator-(double val, const complex & n1);
  friend complex operator-(const complex & n1, const complex & n2);
  friend complex operator*(const complex  & n1, const complex  & n2);
  // friend complex operator*(double n, const complex & n1);
  friend complex operator~(complex & n1);
  friend std::ostream & operator<<(std::ostream & os, const complex & s1);
};
#endif
