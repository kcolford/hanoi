/* Print out the solution to the Towers of Hanoi puzzle.

   Copyright (C) 2013 Kieran Colford

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see
   <http://www.gnu.org/licenses/>.

   The copyright holder can be contacted at <colfordk@gmail.com>

*/

#include "config.h"

/* Standard C headers. */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define tower(n, k) (_tower ((n), (k), 1, (k) + 2, 2, 3))

static void
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
    printf ("Move the top disk of tower %d to tower %d.\n", start, end);
}

#if HAVE_ARGP_H

/* Non-Standard header for option processing. */
#include <argp.h>

const char *argp_program_version = VERSION;
const char *argp_program_bug_address = PACKAGE_BUGREPORT;

static error_t 
parse (int key, char *arg, struct argp_state *state)
{
  int *input = state->input;
  switch (key)
    {
    case ARGP_KEY_ARG:
      if (state->arg_num > 2)
	argp_usage (state);
      input[state->arg_num] = atoi (arg);
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}  

static struct argp argp = { 0, parse, "[ARG1 [ARG2]]", 
			    "Print the solution to the Towers of Hanoi "
			    "puzzle for ARG1 disks (default 8) and ARG2 "
			    "towers (default 2).\v"
			    "For more information, see the home page at\n\n" 
			    PACKAGE_URL };

#else

/* If we don't have access to argp.h, then we have to hide the
   definition of argp_parse using C99 variadic macros. */
#define argp_parse(...) (0)

#endif /* HAVE_ARGP_H */

int main (int argc, char *argv[])
{
  int args[] = { 8, 2 };
  argp_parse (&argp, argc, argv, 0, 0, args);
  tower (args[0], args[1]);
  return 0;
}
