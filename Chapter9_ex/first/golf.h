#include <iostream>
#include <cstring>
#include <cctype>

const int Len = 40;
struct golf
{
  char fullname[Len];
  int handicap;
};
struct chaff
{
  char dross[20];
  int slag;
};
// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc);
// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g);
// function resets handicap to new value
void handicap(golf & g, int hc);
// function displays contents of golf structure
void showgolf(const golf & g);
//exercise 2
void ans(int answer);
void secondary(void);
