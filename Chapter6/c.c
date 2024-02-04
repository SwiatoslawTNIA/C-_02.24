#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
  char c = getchar();
  while(1)
  {
    if(c == EOF)
    {
      system("./c");
    }
    fprintf(stdout, "%c", c);
  }
  return 0;
}
