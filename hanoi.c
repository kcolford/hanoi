/* Print out the solution to the Towers of Hanoi puzzle. */

#include <stdio.h>
#include <assert.h>

void
_tower (int n,     /* The number of disks that we have to move. */
	int k,     /* The number of extra towers that we have. */
	int start, /* The tower that we are moving disks from. */
	int end,   /* The tower that we are moving disks to. */
	int inter, /* The tower that we are using for an
		      intermediate. */
	int nxt    /* The next tower in the queue that can be selected
		      for an intermediate. */
	)
{

  /* Make sure that the impossible doesn't happen. */
  assert (k > 0 || n == 1);

  if (n > 1)
    {
      int fi = 1, i;

      /* Break the input n into a smaller piece that minimizes the
	 running time. */
      for (i = 1; fi * (i + k) / i <= n; i++)
	fi = fi * (i + k) / i;
      fi = fi * k / (i + k - 1);

      /* Recursively proceed. */
      _tower (n - fi, k, start, inter, end, nxt);
      _tower (fi, k - 1, start, end, nxt, nxt + 1);
      _tower (n - fi, k, inter, end, start, nxt);
    }
  else
    printf ("Move %d to %d.\n", start, end);
}

/* Set up a frontend to the recursion. */
#define tower(n, k) (_tower ((n), (k), 1, (k) + 2, 2, 3))

int main ()
{
  tower (8, 2);
  return 0;
}
