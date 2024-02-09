#include "person.h"

Person::Person(const std::string & ln, const char * fn)
{
  lname = ln;
  strcpy(fname, fn);
}
void Person::Show() const
{
  std::cout << "\nThe person: " << fname << ", " << lname;
}

void Person::FormalShow() const
{
  std::cout << "\nThe person: " << lname << ", " << fname;
}


