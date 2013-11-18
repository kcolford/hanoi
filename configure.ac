#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Hanoi], [1.1], [colfordk@gmail.com],,
		 [http://github.com/kcolford/hanoi.git])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])
AC_CONFIG_SRCDIR([src/hanoi.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
gl_EARLY
gl_INIT
AC_PROG_RANLIB

if test $cross_compiling = no; then
   AM_MISSING_PROG(HELP2MAN, help2man)
else
   HELP2MAN=:
fi

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile lib/Makefile])
AC_OUTPUT
