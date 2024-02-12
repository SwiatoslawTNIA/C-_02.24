#include <iostream>
#include <cstring>
#include <cctype>

#ifndef _TIME
#define _TIME
class Time
{
private:
  int hours;
  int minutes;
public:
  Time();
  ~Time();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);
  Time operator+(const Time & t) const;
  void Show(void) const;
  Time operator-(const Time & t) const;
  //creating a friend member func:
  friend Time operator*(const double num, Time & t);
  friend std::ostream & operator<<(std::ostream & out,const Time & t);
};
#endif


