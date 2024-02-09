#include <iostream>
#include <cctype>
#include <cstring>
#ifndef List_
#define List_
typedef int Arr_Type;
Arr_Type multiply(Arr_Type val1, double number);
Arr_Type divide(Arr_Type val, double number);
enum class ACTION {MULTIPLY,DIVIDE};
class List
{
private:
  enum {MAX = 150};
  int elem_count;
  Arr_Type arr[MAX];
public:
  List(void);
  ~List(void);
  // template <typename T, typename... Args>
  // T sum(T first, Args... rest)
  // {
  //   return first + sum(rest...);
  // } 
  void add(Arr_Type element);
  void display(void) const;
  bool isEmpty(void) const;
  bool isFull(void) const;
  void visit(ACTION action, double number);
};

#endif
