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

extern int _han_tower (int, int, int, int, int, int, han_echo_ptr);

/* Front-end to the _han_tower function.

   Returns the number of moves taken to solve the puzzle while calling
   the callback c for each move with the arguments `from' and `to'.

   The initial start point is on tower 1 and the initial end is tower
   2.
   
   n is the number disks
   k is the number of towers
   c is the callback function
*/
#define han_tower(n, k, c) (_han_tower ((n), (k), 1, 2, 3, 4, (c)))

#endif /* not HAN_HANOI_H */
