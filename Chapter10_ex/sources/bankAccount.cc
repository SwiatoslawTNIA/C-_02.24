#include <c++.h>
#include <cstring>
BankAccount::BankAccount(const char *custom_name, const char *account_number, const double bal)
{
  strcpy(name, custom_name);
  strcpy(acc_num, account_number);
  this->balance = bal;//the same as balance = bal
}
BankAccount::~BankAccount()
{
  std::cout << "Destructor called.";
}
void BankAccount::display(void) const
{
  using namespace std;
  cout << "Bankaccount of " << name << ":" << endl;
  cout << "Account number: \t" << acc_num << endl;
  cout << "Balance: \t" << balance << endl;
}

bool BankAccount::deposit(double money)
{
  if(money >= 0.0)
  {
    balance += money;
    return true;
  }
  else return false;
}
void BankAccount::withdraw(double money)
{
  if(balance - money >= 0)
  {
    balance -= money;
    
  }
  else 
  {
    std::cout << "\n\tSorry, insufficient ammount of money.\n";
    std::cout << "Current account balance: " << this->balance;
  }
}
// void BankAccount::del_acc(void)
// {
  
// }
