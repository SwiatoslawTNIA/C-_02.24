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

Time Time::Sum(const Time & t) const
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
  std::cout << "\nThe current time: " << hours << ":" << minutes << std::endl;
}


