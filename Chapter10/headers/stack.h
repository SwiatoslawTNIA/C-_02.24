#ifndef STACK_
#define STACK_
#include <iostream>
typedef unsigned long Item;
class Stack
{
private:
  enum {MAX = 10};
  Item items[MAX];
  int top;
public:
  Stack();
  ~Stack();
  bool isEmpty(void) const;
  bool isFull() const;
  bool push(const Item & item);//returns false if the stack is full
  bool pop(Item & item);//returns false if the stack is empty
};


#endif

