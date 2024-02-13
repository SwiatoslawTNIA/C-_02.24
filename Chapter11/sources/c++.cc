//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
// Group: <group name>
//
// Author: <student ID>
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "time.cc"
#include "timing.h"
#include "vector.cc"
#include "vector.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>
#include "stone.h"
#include "stone.cc"
#include "complex0.h"
#include "complex0.cc"
typedef int INT;
typedef int INT;
typedef int INT;
inline int count(int x);
int main(void)
{
  using std::cout, std::cin, std::endl;
  // // using std::cout;
  // // using std::endl;
  // Time planning;
  // Time coding(2, 40);
  
  // Time fixing(5, 55);
  // Time total, total_2, subtracting, m;
  // cout << "planning time = ";
  // planning.Show();
  // cout << endl;
  // cout << "coding time = ";
  // coding.Show();
  // cout << endl;
  // cout << "fixing time = ";
  // fixing.Show();

  // cout << endl;
  // total = coding.operator+(fixing);
  // //an another way:
  // total_2 = coding + fixing;
  // cout << "\ncoding.Sum(fixing) = ";
  // total.Show();
  // cout << "\ncoding.Sum(fixing) = ";
  // total_2.Show();
  // cout << endl;
  // cout << endl << "Subtracting: " << endl;
  // subtracting = total - total_2;
  // subtracting.Show();
  // // cout << "A very long text input, that takes several lines." << endl << "A new line of a very long input";
  // // cout << endl << "The similar situation where it could be done" << endl << "Another situation\b\r";
  // m = 12 * total;
  // m.Show();
  // cout << m;
  // cout << total;

  // {
  //   using namespace VECTOR;
  //   Vector new_vec(20.0, 30.0, VECTOR::Vector::REC);
  //   cout << new_vec;
  //   Vector new_vec_2(30.0, 43.0, VECTOR::Vector::POL);
  //   cout << new_vec_2;
  // }
  
  // using VECTOR::Vector;
  // srand(time(0));
  // double direction = 0;
  // Vector step;
  // Vector result(0.0, 0.0);
  // unsigned long steps = 0;
  // double target = 0, dstep = 0;
  // cout << "Enter the target's distance: ";
  // while(cin >> target)  
  // {
  //   cout << "Enter step length: ";
  //   if(!(cin >> dstep))
  //     break;
    
  //   while(result.magVal() < target)
  //   {
  //     direction = rand() % 360;
  //     step.reset(dstep, direction, Vector::POL);
  //     result = result + step;//cannot use += because those are two vectors
  //     steps++;
  //   }
  //   cout << "After " << steps << "the subject has the following location: " << result << endl;
  //   result.polarMode();
  //   cout << "or: " << result << endl;
  //   cout << "Average outward distance for a step: " << result.magVal() / steps << endl;
  //   steps = 0;
  //   cout << "Enter target distance (q to quit): ";
  // }
  // cout << "Bye!\n";
  // cin.clear();
  // while(cin.get() != '\n')
  //   continue;
  // {
  //   using namespace VECTOR;

  //   Vector new_vector;
  //   double res = new_vector;
  //   printf("The new_vector res: %lf", res);
  // }
  // using namespace STONEWT;
  // Stonewt new_stone;
  // new_stone = Stonewt(14.3);//the destructor comes before the 
  // // new_stone = Stonewt(19.8);
  //there were some other types to type into, including the main part, where everything was set up


  // new_stone.show_lbs();
  // // new_stone.show_stn();
  // //test the implicit conversion:
  // Stonewt st_1 = Stonewt(9, 34.3);
  // //implicit conversion:
  // double pounds = st_1;
  // printf("The pounds: %.3lf", pounds);
  // //conversion of Stonewt to double:
  // double value = new_stone;
  // int val_2 = new_stone;
  // printf("\nThe values of the conversion: %lf - double, %d - val_2", value, val_2);
  // Stonewt st_2(34.234);//create a new st_1 obj
  // // Stonewt st_3 = -1.1;//impossible, the Stonewt constructor doesn't do any implicit conversion.
  // //testing the multiplication:
  // Stonewt m_1(4324.23), m_2;
  // Stonewt res = m_1 * 2.0;  
  // res.show_lbs();
  
  //it is also possible, even though we have explicit

  complex a(3.0, 4.0);
// initialize to (3,4i)
  complex c;
  cout << "Enter a complex number (q to quit):\n";
  while 
  
  (cin >> c)
  {
    cout << "c is " << c << "\n";
    cout << "complex conjugate is " << ~c << "\n";
    cout << "a is " << a << '\n';
    cout << "a + c is " << a + c << "\n";
    cout << "a - c is " << a - c << "\n";
    cout << "a * c is " << a * c << "\n";
    cout << "2 * c is " << 2 * c << '\n';
    
    cout << "Enter a complex number (q to quit):\n";
  }
  cout << "Done!\n";
  return 0;
}


inline int count(int x)
{
  return x*x;
}


