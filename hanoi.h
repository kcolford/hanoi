/* Main header file for libhanoi.a

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

   The copyright holder can be contacted at <colfordk@gmail.com>.  */

#ifndef HAN_HANOI_H
#define HAN_HANOI_H

typedef void(*han_echo_ptr)(int,int);

extern int han_tower (int, int, han_echo_ptr);

struct _han_tower_args
{
  int n;
  int k;
  int start;
  int end;
  int inter;
  int nxt;
  han_echo_ptr callback;
};

# ifdef __GNUC__

extern int _han_tower (struct _han_tower_args *);

#  define han_tower(n, k, c)						\
  ({									\
    struct _han_tower_args _args = { (n), (k), 1, 2, 3, 4, (c) };	\
    _han_tower (&_args);						\
  })

# endif /* __GNUC__ */

#endif /* not HAN_HANOI_H */
