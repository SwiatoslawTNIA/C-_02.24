#include "golf.h"
// const int Len = 40;
// struct golf
// {
//   char fullname[Len];
//   int handicap;
// };
// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc)
{
  strcpy(g.fullname,name);
  g.handicap = hc;
}
// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g)
{
  using namespace std;
  char buffer[Len];
  cout << "\nEnter the name: ";
  cin.getline(buffer, Len);
  strcpy(g.fullname, buffer);
  cout << "\nEnter the handicap: ";
  int handicap = 0;
  while(!(cin >> handicap))
  {
    cin.clear();
    cout << "\nPlease enter the correct value.";
    while(cin.get() != '\n')
      continue;
  }
  g.handicap = handicap;
  if(strlen(buffer) > 0)
    return 1;
  else 
    return 0;
}

// function resets handicap to new value
void handicap(golf & g, int hc)
{
  g.handicap = hc;
}
// function displays contents of golf structure
void showgolf(const golf & g)
{
  using std::cout;
  using std::endl;
  cout << "\nDisplaying the current golf structure: " << endl;
  cout << "Name: " << g.fullname << ", handicap: " << g.handicap;
}


