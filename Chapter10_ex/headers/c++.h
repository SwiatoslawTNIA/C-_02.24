#include <iostream>
#ifndef BANK_ACCOUNT_
#define BANK_ACCOUNT_
class BankAccount
{
private:
  enum {MAX_LEN = 50};
  char name[MAX_LEN];
  char acc_num[MAX_LEN];
  long double balance;
public:
  BankAccount(const char *name, const char *acc_num, const double balance = 0.0);
  ~BankAccount(void);
  void display(void) const;
  bool deposit(double money);
  void withdraw(double money);
  void del_acc(void);
};
#endif

