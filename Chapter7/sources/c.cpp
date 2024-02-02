#include "cc.h"
#define SIZE 3
#define ARR_SIZE 8
using namespace std;
void display_list(string list[], int size);
void stringToFunc(void);
void show_array(const std::array<double, 4> ar);
void fill_array(std::array<double, 4> *array_pointer);
const int seasons = 4;
const std::array<std::string, seasons> arr_name = {"Summer", "Fall", "Winter", "Spring"};
void countdown(int n);
void exec(void);
void subdivide(char *ruler, int min, int max, int level);
//std const array (sot that it can hold strings), with string obj. elements whose amount is seasons,
// arr_name  is the name of the array
const double *f1(const double ar[], int value);
const double *f2(const double [], int value);

const double *f3(const double *, int value);
void displayArr(const double average, const double arr[], int length);
double calculateAverage(double *arr, int arr_length);
double ex_1(void);
struct applicant {
char name[30];
int credit_ratings[3];
};
//exercise 3
void useBox(void);
void setVolume(struct box *pointer);
void displayBox(const struct box box1);
//exercise 5
int factorial(int integer);

void display(struct applicant applicant1)
{
  cout << "The name of the applicant: " << applicant1.name << endl;
  cout << "The credit ratings are: " << endl;
  for(int i = 0; i < 3;++i)
  {
    cout << "\t" << applicant1.credit_ratings[i] << endl; 
  }
}
void display_copy(const struct applicant *applicant1)
{
  cout << "The name of the applicant: " << applicant1->name << endl;
  cout << "The credit ratings are: " << endl;
  for(int i = 0; i < 3;++i)
  {
    cout << "\t" << applicant1->credit_ratings[i] << endl; 
  }
}
void ex_2(void);
//exercise 6
void reverseArray(double *arr, size_t length);
void showArray(const double *arr, size_t arr_length);//is a const, we don't change the array;
size_t fillArray(double *arr, size_t arr_size);
void manage6(void);
int ex_9();
void process(void);
int main(void)
{
  // stringToFunc();
  // std::array<double, seasons> expenses;
  // fill_array(&expenses);
  // show_array(expenses);
  //let's consider when I want to change to show and display the array:
  // array<double, 4> ar;
  //let's say I want to create a funct that shows it:
  // const int number = 5;
  // int result = factorial(number);
  // cout << "The result of " << number << "! is " << result;
  process();
  return 0;
}
//exercise 10
double add(double x, double y);
double multiply(double x, double y);
double cubic(double x, double y);

double calc(double arg1, double arg2, double (*fp)(double a1, double a2));
void process(void)
{
  int func_count = 3;
  double num1 = 0.0, num2 = 0.0;
  cout << "Enter the numbers to process: ";
  //create an array of pointers to functions:
  double (*arr[func_count])(double a, double b) = {add, multiply, cubic};
  while(cin >> num1 >> num2)
  {
    for(int i = 0; i < func_count;++i)
    {
      cout << "\nThe result of the computation is " << calc(num1, num2, arr[i]);
    }
    cout << "\nEnter the numbers to process: ";
  }
}
double cubic(double x, double y)
{
  return (cbrt(x) + cbrt(y));
}

double add(double x, double y)
{
  return x + y;
}
double multiply(double x, double y)
{
  return x * y;
}

double calc(double arg1, double arg2, double (*fp)(double a1, double a2))
{
  double result =(*fp)(arg1, arg2);
  return result;
}
//exercise 9
const int SLEN = 30;
struct student {
char fullname[SLEN];
char hobby[SLEN];
int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);
int getinfo(struct student students[], int student_count)
{
  int input_students = 0;
  for(int i = 0; i < student_count;++i)
  {
    cout << "Enter the name of the student: " << endl;
    cin.getline(students->fullname, SLEN);
    bool all_spaces = true;
    for(int i = 0; students->fullname[i] != '\0'; ++i)
    {
      if(students->fullname[i] != ' ')
      {
        all_spaces = false;
        break;
      }
    }
    if(all_spaces)
      break;
    cout << "Please enter the hobby of " << students->fullname << ": " << endl;
    cin.getline(students->hobby, SLEN);
    cout << "Please enter the ooplevel of " << students->fullname << ": " << endl;
    while(!(cin >> students->ooplevel))
    {
      cin.clear();
      while(cin.get() != '\n')
        ;
      cout << "Please enter the correct value!!!";
    }
    cin.get();//get the enter 
    students++, input_students++;
  }
  return input_students;
}
// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);
void display1(student st)
{
  cout << "\n\nInformation about a student " << st.fullname << ":\n";
  cout << "Hobbys: " << st.hobby;
  cout << "OOPlevel: " << st.ooplevel;
}
// display2() takes the address of student structure as an
// argument and displays the structure’s contents
void display2(const student * ps);
void display2(const student * st)
{
  cout << "\n\nInformation about a student " << st->fullname << ":\n";
  cout << "Hobbys: " << st->hobby;
  cout << "OOPlevel: " << st->ooplevel;
}
// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);
void display3(const student students[], int student_count)
{
  for(int i = 0; i < student_count;++i)
  {
    cout << "\n\nInformation about a student " << students->fullname << ":\n";
    cout << "Hobbys: " << students->hobby;
    cout << "OOPlevel: " << students->ooplevel;
    students++;//update the students;
  }
}

int ex_9()
{
  cout << "Enter class size: ";
  int class_size;
  cin >> class_size;
  while (cin.get() != '\n')
  continue;
  student * ptr_stu = new student[class_size];
  int entered = getinfo(ptr_stu, class_size);
  for (int i = 0; i < entered; i++)
  {
  display1(ptr_stu[i]);
  display2(&ptr_stu[i]);
  }
  display3(ptr_stu, entered);
  delete [] ptr_stu;
  cout << "Done\n";
  return 0;
}

//exercise 6
void manage6(void)
{
  double arr[ARR_SIZE] = {0};//all elements initialize to 0;
  size_t real_size = fillArray(arr, ARR_SIZE);
  showArray(arr, real_size);
  reverseArray(arr, real_size);
  showArray(arr, real_size);
  reverseArray( arr + 1, real_size - 2);//reverse all but the last elements of the array
  showArray(arr, real_size);
}
void reverseArray(double *arr, size_t length)
{
  double *end = (arr + length - 1), *start = arr;//since it's a double array, it has no NULL
  while(start < end)
  {
    double temp = *end;
    *end = *start;
    *start = temp;//increment the start and decrement the end by one
    start++, end--;
  }
}
void showArray(const double *arr, size_t arr_length)//is a const, we don't change the array
{
  cout << "\nArray:";
  for(size_t i = 0 ;i < arr_length;++i)
  {
    cout << " " << arr[i];
  }
  cout << "\n";
}
size_t fillArray(double *arr, size_t arr_size)
{
  size_t arr_length = 0;
  double value = 0.0;
  while(arr_size > arr_length && (cin >> value))
  {
    arr[arr_length++] = value;
  }
  return arr_length;
}



int factorial(int integer)
{
  if(integer == 1)
    return integer;
  else 
    return integer * factorial(integer - 1);
}
struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};
void useBox(void)
{
  box box1 = {"James Lunatic", 24.0F, 23.0F, 12.0f, 0.0f};
  displayBox(box1);
  setVolume(&box1);
  displayBox(box1);
}
void setVolume(struct box *pointer)
{
  pointer->volume = pointer->height * pointer->width * pointer->length;
}
void displayBox(const struct box box1)
{
  cout << "\nMaker: " << box1.maker;
  cout << "\nHeight: " << box1.height;
  cout << "\nwidth: " << box1.width;
  cout << "\nLength: " << box1.length;
  cout << "\nVolume: " << box1.volume;
}
void ex_2(void)
{
  int scores = 0;
  double arr[10], answer = 0.0;
  while(scores < 10)
  {
    if(scores > 0 && answer == 0)
      break;
    cout << "\nEnter the score:";
    while(!(cin >> answer))
    {
      cin.clear();
      while(cin.get() != '\n')
        ;
      cout << "\nTry again: ";
    }
    arr[scores++] = answer;
  }
  double average = calculateAverage(arr, scores);
  displayArr(average, arr, scores);
}
void displayArr(const double average, const double arr[], int length)
{
  cout << "The array:\n";
  for(int i = 0; i < length;++i)
  {
    cout << arr[i] << " ,";
  }
  cout << " average: " << average;
}
double calculateAverage(double *arr, int arr_length)
{
  double result = 0.0;
  for(int i = 0; i < arr_length; ++i)
  {
    result += *(arr + i);
  }
  result /= arr_length;
  return result;
}
double ex_1(void)
{
  double num1 = 0.0, num2 = 0.0;
  do
  {
    cin.clear();
    while(cin.get() != '\n')
      ;
    cout << "Enter the two harmonic numbers: ";
  } while (!(cin >> num1 >> num2) || (num1 != 0 && num2 != 0));
  double result = ((num1 + num2) * 2) / (num1 + num2);
  return result;
}

double largest(const double *arr, size_t size)
{
  double largest = 0.0;
  for(size_t i = 0; i < size;++i)
  {
    if(largest < arr[i])
      largest = arr[i];
  }
  return largest;
}
void pointer(int *pointer1, int value, int *pointer2)
{
  while(pointer1 < pointer2)
  {
    *pointer1++ = value;
  }
}
void complete( int arr[], int arr_size, int value)
{
  for(int i = 0; i < arr_size;++i)
  {
    arr[i] = value;
  }
}
void hoho(void)
{
  double av[3] = {1112.3, 1542.6, 2227.9};
  // // a pointer to a function:
  // const double *(*p1)(const double ar[], int value) = f1;//and initialize
  // auto p2 = p1;//automatic tp
  // cout << "Using pointers to functions\n";
  // cout << "Address value\n";
  // cout << (*p1)(average,3) << ": " << *(*p1)(average,3) << endl;
  // cout << p2(average, 3) << ": " << *p2(average, 3);
  // //an array of three pointers to func:
  // const double *(*arr_pointers[3])(const double *, int value) = {f1,f2,f3};
  // auto arr_copy = arr_pointers;
  // cout << "Using an array of pointers to functions:\n";
  // cout << "Address value: ";
  // for(int i = 0; i < 3;++i)
  // {
  //   cout << p2[i](average, 3) << ": " << *p1[i](average, 3) << endl;
  // }
  // //a pointer to an array of function pointers:
  // const double *(**p)(const double ar[], int value) = &p1;
  // cout (*p)[0](average, 3) << ": " (*(*p)[0])(average, 3) << endl;
  // return 0;
  // pointer to a function
  const double *(*p1)(const double *, int) = f1;
  auto p2 = f2; // C++11 automatic type deduction
  // pre-C++11 can use the following code instead
  // const double *(*p2)(const double *, int) = f2;
  cout << "Using pointers to functions:\n";
  cout << " Address Value\n";
  cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
  cout << p2(av,3) << ": " << *p2(av,3) << endl;
  // pa an array of pointers
  // auto doesn't work with list initialization
  const double *(*pa[3])(const double *, int) = {f1,f2,f3};
  // but it does work for initializing to a single value
  // pb a pointer to first element of pa
  auto pb = pa;
  // pre-C++11 can use the following code instead
  // const double *(**pb)(const double *, int) = pa;
  cout << "\nUsing an array of pointers to functions:\n";
  cout << " Address Value\n";
  for (int i = 0; i < 3; i++)
  cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
  cout << "\nUsing a pointer to a pointer to a function:\n";
  cout << " Address Value\n";
  for (int i = 0; i < 3; i++)
  cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;
  // what about a pointer to an array of function pointers
  cout << "\nUsing pointers to an array of pointers:\n";
  cout << " Address Value\n";
  // easy way to declare pc
  auto pc = &pa;
  // pre-C++11 can use the following code instead
  // const double *(*(*pc)[3])(const double *, int) = &pa;
  cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
  // hard way to declare pd
  const double *(*(*pd)[3])(const double *, int) = &pa;
  // store return value in pdb
  const double * pdb = (*pd)[1](av,3);
  cout << pdb << ": " << *pdb << endl;
  // alternative notation
  cout << (*(*pd)[2])(av,3) << ": " << *(*(*pd)[2])(av,3) << endl;
}
const double *f1(const double ar[], int value)
{
  return ar;
}
const double *f2(const double ar[], int value)
{
  return ar+1;
}
const double *f3(const double ar[], int value)
{
  return ar+2;
}
void exec(void)
{
  const int Length = 168;
  const int Divs = 10;
  int min = 0, max = Length - 2;//the before last character
  //initialize the ruler 
  char ruler[Length];
  for(int i = 0; i < Length - 2;++i)
  {
    ruler[i] = ' ';
  }
  ruler[min] = ruler[max] = '|';
  ruler[Length - 1] = '\0';
  for(int i = 1; i <= Divs;++i)
  {
    subdivide(ruler, min, max, i);
    std::cout << ruler << std::endl;
    for(int j = 1; j < Length - 2; ++j)
      ruler[j] = ' ';//reset the ruler to blank
  }
}
void subdivide(char *ruler, int min, int max, int level)
{
  if(level == 0)
    return;
  int mid = (min + max) / 2;
  ruler[mid] = '|';
  subdivide(ruler,min, mid, level - 1);
  subdivide(ruler, mid, max, level - 1);
}
void countdown(int n)
{
  cout << "Starting to count down... " << n << endl;
  if(n > 0)
    countdown(n - 1);
  cout << "AHA! " << n << endl;
}
void show_array(const std::array<double, seasons> ar)// a const array pointer of doubles is passed
{
  cout << "Expenses:" << endl;
  for(int i = 0; i < seasons;++i)
  {
    cout << arr_name[i] << " : " << ar[i] << endl;
  }
}
void fill_array(std::array<double, seasons> *array_pointer)//a pointer to an array object of doubles
{
 for(int i = 0; i < seasons;++i)
 {
  cout << "Enter the expenses for " << arr_name[i] << " : ";
  cin >> (*array_pointer)[i];
 }
}
void stringToFunc(void)
{
  string list[SIZE];
  for(int i = 0; i < SIZE;++i)
  {
    cout << "Enter the string to be stored: ";//80 + null
    getline(cin, list[i]);
  }
  display_list(list, SIZE);
}
void display_list(string list[], int size)
{
  cout << "The strings:\n";
  for(int i = 0; i < size;++i)
  {
    cout << list[i] << endl;
  }
}
//working with arrays:

