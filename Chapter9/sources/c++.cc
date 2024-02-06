#include "c++.h"
#include "namespaces.h"
// using namespace std;
#define ARR_LENGTH 10
//!TOPIC: MEMORY MODELS AND NAMESPACES:
//define external linkage:
// int MONTHS = 12;//initialization
// // static int bays = 25;
// void computeLen(const char *arr);
// //change the existing namespace:

// unsigned long long int b = 55;//external linkage
// // static unsigned long long int c = -0;//has internal linkage
// const unsigned long long int size = 4;//the var has internal linkage
// extern const unsigned long long int days = 4;//the var has external linkage

// //example:using the const var:
// const long double var = 74.32234234;

// extern char *pointer;//using the pointer from another file
//an experiment:

//an alternative to using static vars:
// static bool cherish = true;
// namespace 
// {
//   bool cherish_c = true;//internal linkage, static storage duration
// }
// char a;
int main(void)
{
  double x;
  std::cout << "Enter value: ";
  while (! (std::cin >> x) )
  {
    std::cout << "Bad input. Please enter a number: ";
    std::cin.clear();
    while (std::cin.get() != '\n')
      continue;
  }
  std::cout << "Value = " << x << std::endl;
  // cout << Experiment::var;
  // checkP();
  // examine();
  // cout << "Checking out:" << endl;
  // using namespace Experiment;
  // cout << ::a << endl;
  // double a = 0;
  // cout << "Local overwrites global(or namespace)" << a << endl;
  // cin >> a;//write the value into local9(3)
  // cin.get();
  // cin >> ::a;//write the value into global(4)
  // cin >> Experiment::a;//(5)
  // cout << "/Das Ergebnis: " << a << ", ::a: " << ::a << ", Experiment::a: " << Experiment::a; 
  // p();
  // cout << "Everything works alright.";
  // p();
  // char line[10], c;//the buffer for the input
  // // cout << "Bays: " << bays;
  // // exp_01();
  // cout << "Start typing:";
  // cin.get(line, ARR_LENGTH);
  // while(cin)//if cin.get(is not a new_line)
  // {
  //   cout << "The line: " << line << endl;
  //   computeLen(line);
  //   cin.get(c);//get the next character
  //   if(c != '\n')
  //   {
  //     line[0] = c;
  //     cin.get(&line[1], ARR_LENGTH - 1);
  //     cout << "The line: " << line << endl;
  //     computeLen(line);
  //     while(cin)
  //     {
  //       cout << line << endl;
  //       cin.get(line, ARR_LENGTH);
  //       computeLen(line);
  //     }
  //     cin.get();//here we get the new_line
  //   }
  //   else
  //     return 0;
  //   //reset the cin:
  //   cin.clear();
  //   cout << "\nType again, emtpy line to quit:" << endl;
  // }
  // cout << "\nTrying to access the value of the pointer in another file: ";
  // cout << pointer;
  // //delete the memory of the pointer:
  // delete pointer;
  // pointer = NULL;
  // checkP();
  return 0;
}
void computeLen(const char *arr)
{
  static int total = 0;
  while(*arr++)
    total++;
  fprintf(stdout, "Total length: %d, text:", total);
}
// void exp_01(void)
// {
//   int a = 0;
//   cout << a << endl;//0
//   {
//     cout << a << endl;//0
//     int a = 24;
//     cout << a << endl;//24
//   }
//   cout << a << endl;//0
// }
//linkage:
// int amount = 10;//external linkage
// static int value = 55;//internal linkage
// void exp_02(void)
// {
//   static int c = -44;//no linkage(valid only for a single function)
// }
