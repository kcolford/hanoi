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
#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

#define INITIALMESSAGE "Move the top disk of tower %d to the top of tower %d."

void print_version (FILE *, struct argp_state *);
const char *argp_program_version = PACKAGE_STRING;
const char *argp_program_bug_address = PACKAGE_BUGREPORT;
void(*argp_program_version_hook)(FILE *, struct argp_state *) = print_version;

void
print_version (FILE *file, struct argp_state *state)
{
  static char *version[] = {
    PACKAGE_STRING,
    "",
    "Copyright (C) 2013 Kieran Colford.",
    "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.",
    "This is free software: you are free to change and redistribute it.",
    "There is NO WARRANTY, to the extent permitted by law.",
    "",
    "Written by Kieran Colford",
    0 };
  char **p = version;
  
  while (*p)
    fprintf (file, "%s\n", *p++);
}

static char *message = INITIALMESSAGE "\n";
static int print_moves = 0;
static int print_instruct = 1;
static int n = 8;
static int k = 2;

/* The following is basically all just code relating to argument
   processing.  You can generally ignore everything that follows. */

#define HELP								\
  "Print the solution the the Towers of Hanoi puzzle for ARG1 disks "	\
  "(default 8) and ARG2 additional towers (towers excluding the "	\
  "first and last) (default 2)."					\

static const struct argp_option opts[] = {
  { "printf", 'p', "STRING", 0, "use STRING as the format string" },
  { "silent", 's', 0,        0, "don't print out instructions"    },
  { "moves",  'm', 0,        0, "print out the number of moves"   },
  { 0 }
};

error_t
parse (int key, char *arg, struct argp_state *state)
{
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
      if (state->arg_num == 0)
	n = atoi (arg);
      else if (state->arg_num == 1)
	k = atoi (arg);
      else
	argp_usage (state);
      break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static void
print_instructions (int start, int end)
{
  if (print_instruct)
    printf (message, start, end);
}

int main (int argc, char *argv[])
{
  int moves;
  struct argp argument_parser = { opts, parse, "[ARG1 [ARG2]]", HELP };
  argp_parse (&argument_parser, argc, argv, 0, 0, 0);
  moves = han_tower (n, k, print_instructions);
  if (print_moves)
    printf ("%d\n", moves);
  return 0;
}
