#include "cc.h"
using namespace std;
void func(char *array);
inline double multiply(double x, double y) { return x * y;}
char *left(const char *str, int n = 1);//specifying the default value in the arg list.
void f1(void);
void swap1(int *p1, int *p2);
void swap2(int & p1, int & p2);
void references(void);
#define ARR_SIZE 81
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
void strings(void);
int left(int integer, const int digits);//references integer by address, creates a temp copy if necessary;
void left(unsigned long int integer, const unsigned int digits, const int amount = 1);
//templates:
template <typename AnyType>
void Swap(AnyType &a, AnyType &b);
//a new template: (template overloading)
template <typename T>
void Swap(T a[], T b[], int n);
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
  
  left(21523, 3, 2);
  //?Try this out:
  cout << "Ints:";
  int a = 5, b = 6;
  cout << " a: " << a << ", b: " << b;
  Swap(a, b);
  cout << endl << "new: a: " << a << ", b: " << b;
  cout << "Doubles:";
  double c = 5.7, d = 6.7;
  cout << " c: " << c << ", d: " << d;
  Swap(c, d);
  cout << endl << "new: c: " << c << ", d: " << d;//!iT works
  char arr[] = "James";
  char arr2[] = "Mames";
  Swap(arr, arr2, 5);
  cout << arr << ", " << arr2;
  return 0;
}
//template overloading:
template <typename T>
void Swap(T a[], T b[], int n)
{
  int count = 0;
  T temp;
  while(count < n)
  {
    temp = a[count];
    a[count] = b[count];
    b[count++] = temp;
  }
}
//using som templates:
template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
  AnyType temp = a;
  a = b;
  b = temp;
}
//string function with default arguments:
void strings(void)  //find out the number of digits:
{
  char input[ARR_SIZE], *result = NULL;
  int number = 0;
  cout << "Please enter a string to change: " << endl;
  cin.getline(input, ARR_SIZE);
  cout << "\nEnter the amount of chars to leave from the left side: " << endl;
  cin >> number;//we don't check for the upper bound on char amount.
  if(number < 0)
    result = left(input);
  else
    result = left(input, number);
  cout << "\nThe  result: " << result;
  delete result;
}
// int left(int & integer, int digits)//references an lvalue of integer
// {

// }
void left(unsigned long int integer, const unsigned int digits,const int amount)
{//print the n digits from the left
  //dissect the digits to an array, and then print the n digits from the back of the array:
  if(integer == 0 || digits == 0)//long nums do not exceed twenty digits in length
  {
    return;
  }
  unsigned long int temp = integer;
  unsigned int nums = 1;
  while(temp / 10)
  {
    nums++;
    temp /= 10; 
  }
  if(digits >= nums)
    return;
  //the range is acceptable now:
  int numbers[20] = {0};
  unsigned int counter = 0;//the max length of the number is 19 digits
  while(integer / 10)
  {
    numbers[counter++] = integer % 10;
    integer = integer / 10;
  }//we store the values of all the elements up to the last one
  numbers[counter++] = integer % 10;
  numbers[counter] = -1;
  //compute the length fo the numbers;
  unsigned short length = 0;
  for(int i = 0; numbers[i] != -1;++i)
    length++;
  for(unsigned int i = 0; i < digits;++i)
  {
    printf("%d", numbers[--length]);
  }
  printf("The amount: %u", amount);
}
int left(int integer, const int digits)//references integer by address, creates a temp copy if necessary
{
  const int Size = 20;//the max length of a number
  int arr[Size], counter = 0;
  if(digits >= 1)
  {
    if(integer < 10)
    {
      return (integer % 10);//the remainder of dividing by 10
    }
    while((integer / 10) && counter < digits - 1)//when we can divide the integer by 10
    {
      arr[counter++] = integer % 10;//the remainder of division by ten is the current digit.
      integer /= 10;
    } //now the remainder is less than ten, so : add something
    arr[counter] = integer % 10;
    //to accomodate for this iteration, we need that counter < digits - 1 , because the operation above 
    //is the last one.
    //the easier would be to then iterate again through the array, selecting the i < digits digits, 
    //starting when i = 0;
    int total = arr[0], base = 10;
    for(int i = 1; i <= counter;++i)//i must be equal to counter
    {
      total += arr[i] * base;
      base *= 10;//increase the base by 10
    }
    return total;
  }
  return -1;
}

char *left(const char *str, int n)
{
  char *left = new char[n + 1];
  for(int i = 0; i < n && str[i] != '\0' ;++i)
  {
    left[i] = *str++;
  }
  left[n] = '\0';
  return left;
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