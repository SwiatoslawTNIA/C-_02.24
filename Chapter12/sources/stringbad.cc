#include "stringbad.h"
#include <cstring>
#include <cctype>
using std::cout;
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s)
{
  len = std::strlen(s);
  str = new char[len + 1];//the string is a pointer to the alloced memory.
  std::strcpy(str, s);
  num_strings++;
  cout << num_strings << ": \"" << str << "\" object created\n";
}
StringBad::StringBad(void)
{
  len = 4;
  str = new char[4];
  std::strcpy(str, "C++");
  num_strings++;
  cout << num_strings << ": \"" << str << "\" default object created";
}
StringBad::~StringBad(void)
{
  cout << "\"" << str << "\"object deleted, ";
  --num_strings;
  cout << num_strings << " left\n";
  delete [] str;//required
}
std::ostream & operator<<(std::ostream & os, const StringBad & s)
{
  os << s.str;
  return os;
}
//a copy constructor:
StringBad::StringBad(const StringBad & old_s)
{
  num_strings++;
  this->len = strlen(old_s.str);
  this->str = new char[len + 1];//length + \0
  strcpy(str, old_s.str);
  cout << num_strings << ": \"" << str << "object created.\n";//For my info
  //important things follow below...
}
StringBad & StringBad::operator=(const StringBad & st)
{
  num_strings++;
// {
  if(this ==  &st)//if we assign the object to itself
    return *this;//return the reference to the object itself.
  delete [] str;
  len = strlen(st.str);
  str = new char [len + 1];//allocate a new space on the heap
  if(str == nullptr)
  {
    fprintf(stderr, "Not enough RAM");
    exit(EXIT_FAILURE);
  }
  std::strcpy(str, st.str);
  return *this;//return a reference to itself
  // //trying to use another approach:
  // StringBad new_string;
  // new_string.len = strlen(st.str);
  // new_string.str = new char[new_string.len + 1];
  // if(new_string.str == NULL)
  // {
  //   fprintf(stdout, "Error, unable to allocate memory.");
  //   exit(EXIT_FAILURE);
  // }
  //the approach above doesn't work:
  //because: 1. we create a new object, and return it, but the memory is never freed for the 
  //object that we create directly here.
  //2. we have to operate on the object passed as *this, and not on another object, because the 
  //this is actually the value we have to assign the modified assignment operation to.

  //we have to manually free the memory from the passed arg, because the destructor is not gonna be called for it:
  // ~StringBad();desctructor takes no args, so it can't be used with the string, so my own solution isn't working,
  //for it to work, we must manually call the destructor for 
  // return new_string; 
}


