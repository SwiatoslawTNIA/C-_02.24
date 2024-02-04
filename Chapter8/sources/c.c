#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
  return 0;
}
//A copy function that works undeterminted from the type:
//It's like a template in C++
void swap(void *p1, void *p2, size_t size)
{
  void *temp = malloc(sizeof(size));
  if(temp == NULL)
  {
    fprintf(stderr, "Sorry, out of the memory!!!");
    exit(EXIT_FAILURE);
  }
  memcpy(temp, p1, size);
  memcpy(p1, p2, size);//assuming that the sizes of values the pointer point to are equal
  memcpy(p2, temp, size);
  free(temp);
}