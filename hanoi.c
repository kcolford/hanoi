/* Routines to solve the Towers of Hanoi puzzle.

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

#include "hanoi.h"

#ifdef han_tower
# undef han_tower
#endif

#include <assert.h> /* assert */

#define swap(a, b)				\
  do 						\
    {						\
      typeof (a) _tmp = (a);			\
      (a) = (b);				\
      (b) = _tmp;				\
    }						\
  while (0)

int
_han_tower (struct _han_tower_args *args)
{
  int ret = 1;

  /* Make sure that the impossible doesn't happen. */
  assert (args->k > 0 || args->n == 1);

  if (args->n > 1)
    {
      register int fi = 1, i;

      /* Break the input n into a smaller piece that minimizes the
	 running time. */
      for (i = 1; fi * (i + args->k) / i <= args->n; i++)
	fi = fi * (i + args->k) / i;
      fi = fi * args->k / (i + args->k - 1);

      args->n -= fi;

      /* Recursively proceed. */
      swap (args->inter, args->end);
      ret  = _han_tower (args);
      swap (args->inter, args->end);

      i = args->inter;
      args->inter = args->nxt;

      swap (args->n, fi);
      args->nxt += 1;
      args->k -= 1;
      ret += _han_tower (args);
      args->k += 1;
      args->nxt -= 1;
      swap (args->n, fi);
      
      args->inter = i;

      swap (args->inter, args->start);
      ret += _han_tower (args);
      swap (args->inter, args->start);

      args->n += fi;
    }
  else
    args->callback (args->start, args->end);
  return ret;
}

int 
han_tower (int n, int k, han_echo_ptr callback)
{
  struct _han_tower_args args = { n, k, 1, 2, 3, 4, callback };
  return _han_tower (&args);
}

