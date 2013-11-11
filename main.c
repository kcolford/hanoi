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
#include "hanoi.h"

#ifndef INITIALMESSAGE
# define INITIALMESSAGE "Move the top disk of tower %d to the top of tower %d."
#endif

static char *message = INITIALMESSAGE "\n";
static int print_moves = 0;
static int print_instruct = 1;

/* The following is basically all just code relating to argument
   processing.  You can generally ignore everything that follows. */

#if HAVE_ARGP_H && HAVE_STDLIB_H /* We need these to process the
				    arguments. */

# include <stdlib.h> /* atoi */
/* Non-Standard header for option processing. */
# include <argp.h>

const char *argp_program_version = PACKAGE_STRING;
const char *argp_program_bug_address = "<" PACKAGE_BUGREPORT ">";

static error_t 
parse (int key, char *arg, struct argp_state *state)
{
  int *input = state->input;
  switch (key)
    {
    case 'p':
      message = arg;
      break;
    case 's':
      print_instruct = 0;
      break;
    case 'm':
      print_moves = 1;
      break;
    case ARGP_KEY_ARG:
      if (state->arg_num > 2)
	argp_usage (state);
      else
	input[state->arg_num] = atoi (arg);
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static struct argp_option opts[] = {
  { "printf", 'p', "STRING", 0, "Use STRING as the template "
    "argument to printf.  The default arguement is \"" INITIALMESSAGE "\"" },
  { "silent", 's', 0, 0, "Don't print solving instructions." },
  { "moves", 'm', 0, 0, "Print the number of moves it takes to solve "
    "the puzzle." },
  { 0 }
};

static struct argp argp = { 
  opts, parse, "[ARG1 [ARG2]]", 
  "Print the solution to the Towers of Hanoi puzzle for ARG1 disks "
  "(default 8) and ARG2 additional towers (default 2).\n"
  "So the total number of towers is ARG2 + 2.\v"
  "Project home page: " PACKAGE_URL
};

#else /* HAVE_ARGP_H && HAVE_STDLIB_H */

/* If we don't have access to argp.h, then we have to hide the
   definition of argp_parse using C99 variadic macros. */
# define argp_parse(...) (0)

#endif /* HAVE_ARGP_H && HAVE_STDLIB_H */

static void
print_instructions (int start, int end)
{
  printf (message, start, end);
}

int main (int argc, char *argv[])
{
  int args[] = { 8, 2 };
  int moves;
  argp_parse (&argp, argc, argv, 0, 0, args);
  moves = han_tower (args[0], args[1], print_instructions);
  if (print_moves)
    printf ("%d\n", moves);
  return 0;
}
