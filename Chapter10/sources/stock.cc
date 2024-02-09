// Implementing the stock class:
#include "c++.h"
//defining a destructor:

Stock::~Stock(void)
{
  //do nothing, since we haven't use something like new to allocate memory 
  std::cout << "\n<Destructor called>" << company;
}//u can see the code at the end, so it has been called.
//definning a constructor for class Stock: (let's name him Stock())
//the difference is that when an obj of type Stock will be created, the constructor will be called 
//automatically
Stock::Stock(const std::string & co, long n, double pr)
{
  std::cout << "<Constructor called>";
  company = co;
  if(n < 0)
  {
    std::cout << "Number of shares can't be negative. " <<  company << "'s shares set to 0." << std::endl;
    shares = 0;
  }
  else
    shares = n;
  share_val = pr;
  set_tot();
}
//create a constructor overloading:
Stock::Stock(void)
{
  std::cout << "\t\tCalling an empty constructor\n";
  company = "no name";
  share_val = 23;
  shares = 100000;
  total_val = 2000000;
}

// void Stock::acquire(const std::string & co, long n, double pr)
// {
//   company = co;
//   if (n < 0)
//   {
//     std::cout << "Number of shares can't be negative. " <<  company << "'s shares set to 0." << std::endl;
//     shares = 0;
//   }
//   else
//     shares = n;
//   share_val = pr;
//   set_tot();
// }

void Stock::buy(long num, double price)
{
  if(num < 0)
  {
    std::cout << "Number of shares can't be negative." << " Transaction is aborted.\n";
  }
  else
  {
    shares += num;
    share_val= price;
    set_tot();
  }
}

void Stock::sell(long num, double price)
{
  using std::cout;
  if (num < 0)
  {
    std::cout << "Number of shares can't be negative." << " Transaction is aborted.\n";
  }
  else if (num > shares)
  {
    cout << "You can't sell more than you have." << " Transaction is aborted.";
  }
  else
  {
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price)
{
  share_val = price;
  set_tot();
}

void Stock::show(void) const//promises that it won't change the object
{
  std::cout << "Company: " << company << " Shares: " << shares << '\n' << "Share price: $" << share_val
  << " Total Worth: $" << total_val << '\n';
}
//we are writing a function that compares the two objects and returns a bigger one :
const Stock & Stock::topval(const Stock & stock1) const
{
  if(stock1.total_val > total_val)
  {
    return stock1;
  }
  else 
    return *this;//?? What do we return, it turns out there is a this pointer, that points to the current object
    //in each member func, so we can reference that object by using this:
    //since this is an address of the object on which this member function is applied, we need to apply 
    //the dereference operator to get the value of that object
}
