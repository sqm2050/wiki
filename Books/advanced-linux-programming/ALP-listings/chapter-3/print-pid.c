/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <stdio.h>
#include <unistd.h>

int main ()
{
  printf ("The process id is %d\n", (int) getpid ());
  printf ("The parent process id is %d\n", (int) getppid ());
  return 0;
}
