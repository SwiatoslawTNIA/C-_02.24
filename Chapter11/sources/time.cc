#include "timing.h"
// class Time
// {
// private:
//   int hours;
//   int minutes;
// public:
//   Time();
//   ~Time();
//   Time(int h, int m = 0);
//   void AddMin(int m);
//   void AddHr(int h);
//   void Reset(int h = 0, int m = 0);
//   Time Sum(const Time & t) const;
//   void Show(void) const;
// };
Time::Time(void)
{
  hours = minutes = 0;
}
Time::~Time(void)
{
  std::cout << "\nthe destructor is coming.";
}
Time::Time(int h, int m)
{
  hours = h;
  minutes = m;
}
void Time::AddMin(int m)//the minutes are in the range from 0 to 59
{
  minutes = (minutes + m) % 60;//the minutes are defined
  hours += (minutes + m) / 60;
}
void Time::AddHr(int h)
{
  hours += h;
}
void Time::Reset(int h, int m)
{
  hours = h;
  minutes = m;
}

Time Time::operator+(const Time & t) const
{
  //create a new Time obj, assigning it the sum of the curr values + the t arg passed as an arg:
  Time new_obj;
  new_obj.minutes = (minutes + t.minutes) % 60;
  new_obj.hours = hours + t.hours + (minutes + t.minutes) / 60;//Since minutes, t.minutes and 60 are of 
  //type int, the fractional part is discarded.
  return new_obj;
}

void Time::Show(void) const
{
  std::cout.precision(3);
  std::cout << "\nThe current time: " << hours << ":" << minutes << std::endl;
}

Time Time::operator-(const Time & t) const
{
  Time new_time;
  int t1 = 0, t2 = 0;
  t1 = t.minutes + t.hours * 60;
  t2 = minutes + hours * 60;
  new_time.hours = +((t1 - t2) / 60);
  new_time.minutes = +((t1 - t2) % 60);
  return new_time;
}
Time operator*(const double num, Time & t)
{
  Time return_time;
  unsigned long int total_m = t.minutes * num + t.hours * 60 * num;
  return_time.hours = total_m / 60;
  return_time.minutes = total_m % 60;
  return return_time;
}
//trying to teach the Time object to use the cout: cout << Time, 
//the operator<< overloading cannot be a Time member func, because then we would have to use Time << cout
//so it must be a friend func:
std::ostream & operator<<(std::ostream  & out,const Time & t)//peform an operator overloading for the exp: cout << t
//where cout is an object of ostream class, that belongs to std namespace
{
  out << "\nHours:" << t.hours << ", minutes: " << t.minutes;
  return out;
}


