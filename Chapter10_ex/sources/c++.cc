#include "c++.h"
#include "bankAccount.cc"
#include "person.h"
#include "person.cc"
#include "move.cc"
#include "move.h"
#include "plorg.h"
#include "plorg.cc"
#include "list.h"
#include "list.cc"
int main(void)
{
  using namespace std;
  //ex_1:
  // BankAccount bank_acc1 = BankAccount("Jeremy William Johnson", "12312312312", 213.123);
  // BankAccount bank_acc2("Jeremy William Johnson", "12312312312", 4000);
  // //display the information:
  // bank_acc1.display();
  // bank_acc2.display();
  // //deposit from the first bank account:
  // bank_acc1.deposit(200);
  // bank_acc1.display();
  // bank_acc2.withdraw(5000);
  // Person one;
  // Person two("Smythecraft");
  // Person three("Dimwiddy", "Sam");
  // one.Show();
  // cout << endl;
  // one.FormalShow();
  // two.Show();
  // two.FormalShow();
  // three.Show();
  // three.FormalShow();
  // cout << "Bye.";
// etc. for two and three
  //ex_6:
  // Move move1;//default constructor
  // move1.showmove();
  // Move move2 = Move(324, 234);
  // Move new_move = move1.add(move2);
  // new_move.showmove();
  // //the implementation of Plorg:
  // Plorg new_plorg = Plorg();//using a default constructor
  // Plorg new_plorg_2 = Plorg("A cooked potato", 22);
  // new_plorg.report_name();
  // new_plorg_2.report_name();
  // new_plorg.change_CI(44);
  // new_plorg.report_name();

  List new_list;
  new_list.add(534);
  new_list.add(32);
  new_list.add(52);
  new_list.add(2);
  new_list.add(-62);

  new_list.display();
  // cout << new_list.isEmpty() << endl;
  // cout << new_list.isFull() << endl;
  // new_list.sum(24, 234, 12, 323, 4324, -12);
  // new_list.display();
  new_list.visit(ACTION::MULTIPLY, 2.3);
  new_list.display();
  return 0;
}