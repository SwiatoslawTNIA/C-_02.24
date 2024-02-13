//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// Chapter 12, Dynamic memory allocation and classes
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "stringbad.h"
#include "stringbad.cc"
//function prototypes:
void callme1(StringBad &);
void callme2(StringBad);
// pass by reference
// pass by value
//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//
int main(void)
{
  using std::cout, std::endl;
  StringBad str3("An example");
  StringBad str("An example of a longer, way longer string, for which the memory is still allocated"
  "automatically.");
  {
    cout << "Starting an inner block.\n";
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");
    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    callme1(headline1);
    cout << "headline1: " << headline1 << endl;
    callme2(headline2);//the copy constructor is called once
    cout << "headline2: " << headline2 << endl;
    cout << "Initialize one object to another:\n";
    StringBad sailor = sports;//that means that StringBad sailor = StringBad(sports);
    //in the assignment above the copy constructor is copied another time.
    cout << "sailor: " << sailor << endl;
    cout << "Assign one object to another:\n";
    StringBad knot;
    knot = headline1;//and another time., so there should be -3;
    cout << "knot: " << knot << endl;
    cout << "Exiting the block.\n";


  }
  //created the object, 
  return 0;
}
void callme1(StringBad & s)
{
  std::cout << "String passed by reference: " << s << std::endl;
}
void callme2(StringBad s)
{
  std::cout << "String passed by value: " << s << std::endl;
}
