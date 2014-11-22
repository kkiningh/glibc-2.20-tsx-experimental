/* Implement futimesat for MicroBlaze.
   Copyright (C) 2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* MicroBlaze always had the utimensat syscall but gained the
   futimesat syscall later, so use the linux-generic implementation of
   futimesat in terms of the utimensat syscall unless the futimesat
   syscall is known to be available.  */

#include <kernel-features.h>

#ifdef __ASSUME_FUTIMESAT
# include <sysdeps/unix/sysv/linux/futimesat.c>
#else
# include <sysdeps/unix/sysv/linux/generic/futimesat.c>
#endif
