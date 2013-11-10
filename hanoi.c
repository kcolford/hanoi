/* Print out the solution to the Towers of Hanoi puzzle. */

#include <stdio.h>

void 
_tower3 (int n, int start, int end, int inter)
{
  if (n > 0)
    {
      _tower3 (n - 1, start, inter, end);
      printf ("Move %d to %d.\n", start, end);
      _tower3 (n - 1, inter, end, start);
    }
}

void
tower3 (int n)
{
  _tower3 (n, 1, 3, 2);
}

int main ()
{
  tower3 (8);
  return 0;
}
