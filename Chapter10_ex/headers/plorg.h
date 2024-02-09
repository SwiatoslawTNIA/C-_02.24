#include <iostream>
#include <cstring>
#include <cctype>
#ifndef PLORG_ 
#define PLORG_
class Plorg 
{
private:
  char name[20];
  int contentment_index;
public:
  //constructor + destructor:
  Plorg(const char *n = "Plorga", int plorg_CI = 50);
  ~Plorg(void);
  //funcs:
  void change_CI(int new_CI);
  void report_name(void);

};

#endif

