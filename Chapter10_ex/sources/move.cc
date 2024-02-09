#include "move.h"



Move::Move(double a, double b)
{
  x = a;
  y = b;
}
void Move::showmove(void) const
{
  std::cout << "The current position: x: " << x << ", y: " << y << std::endl;
}
Move Move::add(const Move & m) const
{
  Move new_move;
  new_move.x = x + m.x;
  new_move.y = y + m.y;
  return new_move;
}
void Move::reset(double a, double b)// resets x,y to a, b
{
  x = a;
  y = b;
}


