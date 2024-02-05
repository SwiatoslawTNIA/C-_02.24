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
//templates://general template
template <typename AnyType>
void Swap(AnyType &a, AnyType &b);
//a new template: (template overloading)(general template)
template <typename T>
void Swap(T a[], T b[], int n);
//explicit template:
struct job 
{
  char name[40];
  double salary;
  int floor;
};
template <> void Swap<job>(job &, job &);//just a template , not an argument name list

template <typename T> 
void showArray(const T (*)[], size_t n);

template <typename T> 
void showArray(const T [], size_t n);
//exercises:
void printString(const char *string);
void printString(const char *string,const int n);
struct CandyBar
{
  const char *brand_name;
  float weight;
  int calories;
};
void setCandyBar(CandyBar & candy, const char *brand_name, float weight, int calories);
void displayCandyBar(CandyBar & new_candy);
void ex_3(void);
void ex_4(void);
template <class T>
auto max5(T * value) -> T;

template <class T>
auto maxn(T * value, int elem_count) -> T;

template <class T>
const char *maxn(const T **str_arr,const int pointers_count);

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
  
  // left(21523, 3, 2);
  // //?Try this out:
  // cout << "Ints:";
  // int a = 5, b = 6;
  // cout << " a: " << a << ", b: " << b;
  // Swap(a, b);
  // cout << endl << "new: a: " << a << ", b: " << b;
  // cout << "Doubles:";
  // double c = 5.7, d = 6.7;
  // cout << " c: " << c << ", d: " << d;
  // Swap(c, d);
  // cout << endl << "new: c: " << c << ", d: " << d;//!iT works
  // char arr[] = "James";
  // char arr2[] = "Mames";
  // Swap(arr, arr2, 5);
  // cout << arr << ", " << arr2;
  // //using a new template:
  // double a = 2, b = 3;
  // cout << a << ", " << b << endl;
  // cout.precision(12);
  // Swap(a, b);//a general template is used
  // job job1 = {"Melissa", 65000.43, 34};
  // job job2 = {"Molly", 320000.43, 19};
  // Swap(job1, job2);
  // cout << job1.floor << ", salary: " << job1.salary << endl;
  // cout << job2.floor << ", salary: " << job2.salary;
  // //assuming the template 1:
  // char arr[] = "Live you life to the fullest.";
  // char (*p)[] = &arr;
  // showArray(arr, strlen(arr));
  // showArray(&arr, strlen(arr));
  // //s
  // showArray(p, strlen(arr));//here the compiler has chose a template to a pointer to arr
  // // showArray(p, strlen(arr));
  //exercise 1:
  // char str[] = "Some very important message";
  // printString(str);
  // printString("Anything is possible");
  // printString(str, 4);
  // CandyBar new_candy;
  // setCandyBar(new_candy, "Milky Way", 156.7F, 200);
  // displayCandyBar(new_candy);
  // int arr[] = {4,43,2,42,5};
  // decltype(max5(arr)) value = max5(arr);
  // cout << "The result with type int: " << value << endl;
  // double ar[] = {43.4, -124.4, 124, 44, 867};
  // decltype(max5(ar)) val2 = max5(ar);
  // cout << "The result with type double: " << val2;
  //checking the expercise 6:
  int a[] = {1, 2, 3, 45, 6, 7};
  decltype(maxn(a, 6)) res = maxn(a, 6);
  cout << res << endl;
  double b[] = {1.2 ,2.4 ,3.5324, 15.0, 4.5, 6.234, 7.00001};
  decltype(maxn(b, 7)) res2 = maxn(b, 7);
  cout << res2 << endl;
  //the second part:
  const char *array[5] = {"The string number 1", "The string that meas ", "A short one", "Trying to incorporate the most features", "A"};
  const char *address = maxn(array, 5);
  cout << address << endl;
  return 0;
}
unsigned int TIMES = 0;
//exercise 6:
template <class T>
auto maxn(T * value, int elem_count) -> T
{
  T largest = *value;
  for(int i = 1; i < elem_count;++i)
  {
    if(largest < value[i] )
      largest = value[i];
  }
  return largest;
}
//a template overloading:
template <class T>
const char *maxn(const T **str_arr,const int pointers_count)
{
  size_t max_length = 0;//to measure the size
  const char *longest_string = NULL;
  for(size_t i = 0; i < (size_t)pointers_count;++i)
  {
    size_t current_length = 0;
    for(size_t j = 0; str_arr[i][j] != '\0';++j,current_length++)
      ;
    if(current_length > max_length)
    {
      max_length = current_length;
      longest_string = str_arr[i];
    }
  }
  return longest_string;
}
// template <> auto maxn<char>(char * value, int elem_count) -> char
// {

//   //do something..
// }
//exercise 5:
template <class T>
auto max5(T * value) -> T
{
  T var = value[0];
  for(int i = 1; i < 5;++i)
  {
    if(var < value[i])
      var = value[i];
  }
  return var;
}
//exercise 4:
struct stringy {
char * str;
int ct;
};
//a little bit of overloading
void set(stringy & stringy_structure, const char *string);
// void show(const stringy & beany);
void show(const stringy & beany, const int n = 1);
void show(const char *string, int n = 1);
//how I would use two templates instead:

void ex_4(void)
{
  stringy beany;

  char testing[] = "Reality isn't what it used to be.";
  set(beany, testing);
  // first argument is a reference,
  // allocates space to hold copy of testing,
  // sets str member of beany to point to the
  // new block, copies testing to new block,
  // and sets ct member of beany
  //exercise 2 + 3
  show(beany);
  // prints member string once
  show(beany, 2);
  // prints member string twice
  testing[0] = 'D';
  testing[1] = 'u';
  show(testing);
  // prints testing string once
  show(testing, 3); // prints testing string thrice
  show("Done!");
  delete beany.str;
}
void show(const char *string, int n)
{
  if(strcmp("Done!", string) != 0)
  {
   cout << "Printing the contents of the testing: \n";
  }
  for(int i = 0; i < n;++i)
  {
    cout << string << endl;
  }
}
void show(const stringy & beany, const int n)
{
  cout << "Printing the contents of the beany: \n";
  for(int i = 0; i < n;++i)
  {
    cout << beany.str << endl;
  }
}
// void show(const stringy & beany)
// {
//   cout << "Printing the contents of the structure: \n";
//   cout << beany.str;
// }
void set(stringy & stringy_structure, const char *string)
{
  //compute the length:
  unsigned int length = 0;
  const char *p_copy = string;
  while(*p_copy++)
    length++;
  //set the length:
  stringy_structure.ct = length;
  stringy_structure.str = new char[length + 1];//for the NULL terminator
  if(stringy_structure.str == NULL)
  {
    fprintf(stderr, "Sorry, out of memory. Exiting...");
    exit(EXIT_FAILURE);
  }
  //copy the contents to struct:
  unsigned int i = 0;
  for(; i < length;++i)
  {
    stringy_structure.str[i] = *(string + i);
  }
  stringy_structure.str[i] = '\0';//set the last null terminator;
}


void ex_3(void)
{
  char line[80];// a buffer for input
  cout << "Enter a string(q to quit):\n";
  while(cin.getline(line, 80))
  {
    //check if we want to quit:
    unsigned int length = strlen(line);//there is a '\0'
    if(length == 1 && line[0] == 'q')
      break;
    for(unsigned int i = 0; i < length; ++i)
    {
      if(isalpha(line[i]) && islower(line[i]))
        line[i] = toupper(line[i]);
    }
    cout << line << endl;//display the line
    cout << "Next string (q to quit)";
  }
}
void displayCandyBar(CandyBar & new_candy)
{
  cout << "The candy's values: " << endl;
  cout << new_candy.brand_name << " :" << new_candy.calories << " calories, weight: " << new_candy.weight << "\n";
}
void setCandyBar(CandyBar & candy, const char *brand_name, float weight, int calories)
{
  candy.brand_name = brand_name;
  candy.weight = weight;
  candy.calories = calories;
}
//exercise 1: overloading:
void printString(const char *string)
{
  cout << string << endl;
  TIMES++;
}
void printString(const char *string,const int n)
{
  if(n != 0)
  {
    for(unsigned int i = 0; i < TIMES;++i)
    {
      cout << string << endl;
    }
  }
}
template <class T1, class T2>
void ft(T1 elem1, T2 elem2)
{
  typedef decltype(elem1 + elem2) elem1elem2;
  elem1elem2 res = elem1 + elem2;//what type should the result be??????
}
// double h1(int x, int y);
//can be written as:
auto h1(int x, int y) -> double;
// unsigned long long int *func(int value1, double * value2);
auto func(int value1, double * value2) -> unsigned long long int *;
//two template funcs for showing array:
//determite which template is gonna be used:  
template <typename T> 
void showArray(const T (*arr)[], size_t n)
{
  fprintf(stdout, "\nTemplate for char pointer_to_arr\n");
}
template <typename T> 
void showArray(const T arr[], size_t n)
{
  fprintf(stdout, "\nTemplate for char array\n");
}
//explicit template:
template <> void Swap(job & job1, job & job2)//template for type job
{ 
  double temp = job1.salary;
  int floor_temp = job1.floor;
  job1.floor = job2.floor;
  job1.salary = job2.salary;
  job2.floor = floor_temp;
  job2.salary = temp;
} 
//before exercise section:
void iquote(int arg)
{
  cout << "\"" << arg << "\"" << endl;
}
void iquote(double arg)
{
  cout << "\"" << arg << "\"" << endl;
}
void iquote(const char *arg)// string
{
  cout << "\"" << arg << "\"" << endl;
}
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
void displayBox(const box & box_instance)
{
  cout << "Maker: " << box_instance.maker << endl;
  cout << "Height: " << box_instance.height << endl;
  cout << "Width: " << box_instance.width << endl;
  cout << "Length: " << box_instance.length << endl;
  cout << "Volume: " << box_instance.volume << endl;
}
void setBoxVolume(box & box_instance)
{
  box_instance.volume = box_instance.width * box_instance.height * box_instance.length;
}
double mass(const double density,const double volume = 1);
//b- funciton overloading:
void repeat(int n, const char *str);
void repeat(const char *str, int n = 5);
//c - overloading
int average(int a, int b);
double average(double a, double b);
//d
const char *mangle(const char *str);
//7>
template <class A>
A larger(A num1, A num2)
{
  return (num1 > num2 ? num1 : num2);
}
//explicit specialization:
template <> box larger<box>(box box1 , box box2)
{
  return (box1.volume > box2.volume ? box1 : box2);
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