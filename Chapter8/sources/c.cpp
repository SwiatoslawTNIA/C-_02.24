#include "cc.h"
using namespace std;
void func(char *array);
inline double multiply(double x, double y) { return x * y;}
void f1(void);
void swap1(int *p1, int *p2);
void swap2(int & p1, int & p2);
void references(void);
struct a 
{
  std::string name;
  int made;
  int attempts;
};
void display(const a & object);
a & accumulate( struct a & target, const struct a & source);
void create(void);
string enhance(const string str, const string add);
void convertString(void);
int main(void)
{
  // cout << "can you?" << endl;
  // // const char *arr = "Some array, loki";
  // char arr[] = "Some array, loki";//this is an array of chars, it can be changed
  // cout << arr << endl;
  // func(arr);
  // double result = multiply(12.4, 51.5);
  // cout << "\nThe result of the multiplication: " << result;
  // // func("Jeremy");
  
  convertString();
  return 0;
}
//convert string:
void convertString(void)
{
  cout << "\nEnter the string to convert:";
  string str;
  getline(cin, str);
  cout << "\nYour string as entered: " << str;
  string temp = enhance(str, "AAAA");
  cout << "\nYour string enhanced: " << temp << endl;
}
string enhance(const string str, const string add)
{
  string temp = add + str + add;
  return temp;
}
void create(void)
{
  struct a structure1 {"James Morrison", 17, 33};
  struct a structure2 {"James Harrison", 20, 33};
  // struct a new_combined = accumulate(structure1, structure2);
  display(accumulate(structure1, structure2));
  display(structure1);
  display(structure2);
}
a & accumulate(struct a & target, const struct a & source)
{
  target.attempts += source.attempts;
  target.made += source.made;
  return target;
} 
void display(const a & object)
{
  cout << object.name << ": " << object.attempts << ", made; " << object.made << endl;
}
void references(void)
{
  int value1 = 1, value2 = 2;
  swap1(&value1, &value2);
  cout << "After the first swap with the pointers: " << value1 << ", " << value2 << endl;
  swap2(value1, value2);
  cout << "After the first swap with the reference: " << value1 << ", " << value2 << endl;

}

void swap1(int *p1, int *p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
//using reference:
void swap2(int & p1, int & p2)
{
  int temp = p1;
  p1 = p2;
  p2 = temp;
}
void f1(void)
{
  //references:
  
  int pineapples = 43;
  cout << "pineapples = " << pineapples << ", address: " <<  &pineapples << endl;
  int & pineapples_2 = pineapples;
  cout << "pineapples_2 = " << pineapples_2 << ", address: " <<  &pineapples << endl;
  cout << pineapples_2;
  cout << endl << "Changing alliance: ";
  int rats = 101;
  int & rodents = rats;
  cout << "rats = " << rats;
  cout << ", rodents = " << rodents << endl;
  cout << ", rat's address = " << &rats;
  cout << ", rodent's address = " << &rodents << endl;
  int bunnies = 50;
  rodents = bunnies;
  cout << "bunnies = " << bunnies;
  cout << ", rodents = " << rodents << endl;
  cout << ", bunnies' address = " << &bunnies;
  cout << ", rodent's address = " << &rodents << endl;
}
void func(char *array)
{
  int i = 0;
  // cout << "In";
  while(array[i] != '\0')
  {
    array[i++] = 'j';
  }
  cout << array;

}