// typedef long long int List_Type;
// typedef struct 
// {
//   List_Type *next_el;
//   List_Type current_value;
// } List_el;
// class List
// {
// private:
//   List_el list;
//   List_Type *first_element;
//   unsigned long elem_count;
// public:
//   List(void);
//   ~List(void);
// };
// Arr_Type (*fp[2])(Arr_Type var, double number) = {multiply, divide};
#include "list.h"
//with a linked list that would be too tough


Arr_Type multiply(Arr_Type val1, double number)
{
  return (val1 * number);
}

Arr_Type divide(Arr_Type val, double number)
{
  return (val * number);
}

void List::add(Arr_Type element)
{
  if(elem_count == MAX)
    std::cout << "Sorry, max amount of elements reached.";
  else
  {
    arr[elem_count++] = element;
  }
}

List::List(void)
{
  elem_count = 0;
}

List::~List(void)
{
  std::cout << "\nDeconstructing the list";
}

bool List::isEmpty(void) const
{
  return elem_count == 0;
}

bool List::isFull(void) const
{
  return elem_count == MAX;
}

void List::visit(ACTION action, double number)
{ 
  Arr_Type (*fp)(Arr_Type val, double n) = NULL;
  switch(action)
  {
    case(ACTION::DIVIDE):
    {
      fp = divide;
      break;
    }
    case(ACTION::MULTIPLY):
    {
      fp = multiply;
    }
  }
  for(int i = 0;i < elem_count; ++i)
  { 
    arr[i] = (*fp)(arr[i], number);
  }
}
void List::display(void) const
{
  using namespace std;
  cout << "\nElements: [";
  for(int i = 0; i < elem_count;++i)
  {

    cout << arr[i];
    if(i != elem_count - 1)
      cout << ", ";
    else
      cout << ' ';
  }
  cout << "]";
}

