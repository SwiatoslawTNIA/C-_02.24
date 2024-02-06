// #include "c++.h"
// #include "namespaces.h"
// using namespace std;
// extern int MONTHS;
// // int bays = 5;//multiple declarations of bays, error
// int bays = 5;
// //accessing the const var:
// // extern const long double var;//external linkage, static storage duration
// // void examine(void)
// // {
// //   fprintf(stdout, "%Lf", var);
// // }
// // extern const unsigned long long int size;//it has ambiguous meaning
// extern const unsigned long long int days;
// char *pointer = NULL;
// namespace Experiment
// {
//   int var = 14;
// }
// //namespaces:
// namespace Jack
// {
//   double p;
//   void show(void);
//   int i;//be default all vars have external linkage(except for a const);
// }
// namespace Jill
// {
//   // double e(double a, double b) 
//   // {
//   //   //do something
//   //   return a;
//   // }
//   int i;
//   void show(void);
//   double p;
//   namespace Son_of_Jill
//   {
//     void show(void);
//   }
// }
// namespace space
// {
//   namespace space
//   {
//     namespace space{
//       void show(void);
//     }
//   }
// }
// //adding the elements to an existing namespace:
// namespace Jack
// {
//   const int wood_amount = 35;
// }
// void space::space::space::show(void)
// {
//   cout << "This is the coolest thing I've ever experienced.";
// }
// void Jill::Son_of_Jill::show(void)
// {
//   cout << "The Jill's son was here." << endl;
// }
// void Jack::show(void)
// {
//   cout << "The function belongs to the Jack namespace" << endl;
// }
// void Jill::show(void)
// {
//   cout << "The function belongs to the Jill namespace" << endl;
// }
// void p(void)
// {
//   // unsigned int var = 0;
//   // cout << size << endl;
//   // cout << days << endl;
//   // cout << "How big do you want the value to be?";
//   // cin >> var;
//   // cin.get();
//   // pointer = new char[var];
//   // cout << "\nStart typing: ";
//   // cin.get(pointer, var);
//   Jill::show();
//   Jack::show();
//   Jill::Son_of_Jill::show();
//   space::space::space::show();
//   // printf("The global value: %d\n", MONTHS);
//   // fprintf(stdout, "Bays: %d\n", bays);
//   // //define own:
//   // int MONTHS = 44;
//   // printf("The local value: %d\n", MONTHS);
//   // {
//   //   //define another one that is valid only for this block:
//   //   int MONTHS = 50;
//   //   printf("The value inside a block: %d\n", MONTHS);
//   // }
//   //   printf("The value after a block: %d\n", MONTHS);
//   // printf("Some altercation.");
// }
// void checkP(void)
// {
//   using namespace Jack;
//   show();
//   //check the value of the pointer:
//   if(pointer == NULL)
//     fprintf(stdout, "The memory has been freed, checking from another file.");
//   else
//   {
//     fprintf(stdout, "The value after the pointer has been freed: ");
//     cout << pointer;
//   }
// }


