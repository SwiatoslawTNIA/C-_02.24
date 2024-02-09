#include "stack.h"
Stack::Stack(void)
{
  std::cout << "<constructor>";
  top = 0;
}

Stack::~Stack()
{
  std::cout << "<descructor>";
}
bool Stack::isEmpty(void) const
{
  return (top == 0 ? true : false);
}
bool Stack::isFull(void) const
{
  return (top == MAX ? true : false);
}

bool Stack::push(const Item & item)
{
  if(top < MAX)
  {
    items[top++] = item;
    return true;
  }
  else
    return false;
}
bool Stack::pop(Item & item)
{
  if(top > 0)
  {
    item = items[--top];
    return true;
  }
  else
    return false;
} 
