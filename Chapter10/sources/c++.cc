#include "c++.h"
#include "stock.cc"
//!Chapter 10 : Classes
int main(void)
{
  using namespace std;
  // std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  // // Stock sally;
  // //using the sally object of class type Stock:
  // // sally.acquire("NanoSmart", 20, 12.50);
  // // sally.show();
  // // sally.buy(15, 18.125);
  // // sally.show();
  // // sally.sell(400, 20.0);
  // // sally.show();
  // // sally.buy(300000, 40.125);
  // // sally.show();
  // // sally.sell(300000, 0.125);
  // // sally.show();
  // Stock sally;//using a default own contructor
  // sally.show();
  //experimenting with constructors/desctructors:
  {
    cout << "Using constructors to create new objects.\n";
    Stock stock1 = Stock("Boffo Objects", 3, 3.0);//first syntax
    stock1.show();
    Stock stock2("Nanosmart", 12, 20.0);//second syntax
    stock2.show();
    cout << "Assigning stock1 to stock2:\n";
    stock1 = stock2;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();
    cout << "Using a constructor to reset an object:\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "\nDone.";
  }//perhaps to see extra destructors, na, the output is the same as with constructors.

  //almost as always.. the const is special:if defined globally, it is of type inline, so we could use it in headers....
  const Stock stock1 = Stock("Turing machines", 342L, 342.32);
  stock1.show();//an error, show doesn't promise to not change the stock1 const object, so we must 
  //change the syntax: void show(void) const;
  return 0;
}