#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([hanoi], [1.0.0], [colfordk@gmail.com],,
		 [http://github.com/kcolford/hanoi.git])
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])
AC_CONFIG_SRCDIR([hanoi.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_MISSING_PROG([HELP2MAN], [help2man], [$missing_dir])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h argp.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
