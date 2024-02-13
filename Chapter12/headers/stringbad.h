#include <iostream> 
#ifndef STRINGBAD_
#define STRINGBAD_
class StringBad
{
private:
  char *str;//to hold the value
  size_t len;//the length of the array
  static int num_strings;//the number of objects
public:
  StringBad(const char *s);
  StringBad(void);
  ~StringBad();
  StringBad(const StringBad &);//a copy constructor;
  //the problem is also in the assignment operator, which is provided by default, it uses a shallow copying, 
  //so the value of the pointer is not copied, so we must provide our own version of the assignment operator:
  StringBad & operator=(const StringBad & st);
  
  //friend function:
  friend std::ostream  & operator<<(std::ostream & os, const StringBad & s);
};
#endif
