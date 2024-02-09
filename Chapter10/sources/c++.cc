#include "c++.h"
#include "stock.cc"
#include "stack.h"
#include "stack.cc"

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
  // {
  //   cout << "Using constructors to create new objects.\n";
  //   Stock stock1 = Stock("Boffo Objects", 3, 3.0);//first syntax
  //   stock1.show();
  //   Stock stock2("Nanosmart", 12, 20.0);//second syntax
  //   stock2.show();
  //   cout << "Assigning stock1 to stock2:\n";
  //   stock1 = stock2;
  //   cout << "Listing stock1 and stock2:\n";
  //   stock1.show();
  //   stock2.show();
  //   cout << "Using a constructor to reset an object:\n";
  //   stock1 = Stock("Nifty Foods", 10, 50.0);
  //   cout << "Revised stock1:\n";
  //   stock1.show();
  //   cout << "\nDone.";
  // }//perhaps to see extra destructors, na, the output is the same as with constructors.

  //almost as always.. the const is special:if defined globally, it is of type inline, so we could use it in headers....
  // const Stock stock1 = Stock("Turing machines", 342L, 342.32);
  // stock1.show();//an error, show doesn't promise to not change the stock1 const object, so we must 
  // //change the syntax: void show(void) const;
  // Stock s1 = Stock("Anything", 54345L, 0.43);
  // s1.show();
  // Stock s2 = Stock("Almost anything", 4324, 40.34);
  // s2.show();
  // const Stock & bigger = s1.topval(s2);
  // bigger.show();
  // Stock my_stocks[10];//create ten objects of class Stock
  // create an array of initialized objects
  // Stock stocks[4] = {
  //   Stock("NanoSmart", 12, 20.0),
  //   Stock("Boffo Objects", 200, 2.0),
  //   Stock("Monolithic Obelisks", 130, 3.25),
  //   Stock("Fleep Enterprises", 60, 6.5)
  // };
  // const Stock *top = &stocks[0];
  // for(int i = 1; i < 4; ++i)//start from the second el.
  // {
  //   top = &top->topval(stocks[i]);
  //   //topval returns a reference, so essentially that object, some we have to use & to get its address
  //   top->show();//show the contenst of the top
  // }
  // //Trying to update something
  // int i = 10;
  // cout << i;
  // //scoped enumerations:
  // enum class forest {Small, Medium, Big, Enormous};
  // enum class steak {Small = 50, Medium = 100, Big = 150, Enormous = 200};
  // //the enums above are conflicting with each other, so when u use Small, does it take 0 or 50 value? 
  // //the solution is to use scoped enums:
  // forest new_forest = forest::Big;//the big here is 2
  // steak new_steak = steak::Medium;//the medium here is 100



  Stack new_stack;
  char c;
  unsigned long int input = 0UL;
  cout << "Please enter A to add a purchase order, \n" << "P to process a PO, or Q to quit.\n";
  while(cin >> c && toupper(c) != 'Q')
  {
    while(cin.get() != '\n')
    {
      continue;
    }
    if(!isalpha(c))
    {
      cout << '\a';
      continue;
    }
    switch(c)
    {
      case 'A':
      case 'a': cout << "Enter PO number to add: ";
                cin >> input;
                if(new_stack.isFull())
                  cout << "stack already full\n";
                else 
                  new_stack.push(input);
                break;
      case 'P':
      case 'p': if (new_stack.isEmpty())
                  cout << "sorry, the stack is empty.";
                else
                {
                  new_stack.pop(input);
                  cout << "PO #" << input << " popped.\n";
                }
                break;
    }
    cout << "Please enter a to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
  }
  cout << "Bye";
  return 0;
}