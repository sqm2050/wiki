/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "server.h"

const char* program_name;

int verbose;

void* xmalloc (size_t size)
{
  void* ptr = malloc (size);
  /* Abort if the allocation failed.  */
  if (ptr == NULL)
    abort ();
  else
    return ptr;
}

void* xrealloc (void* ptr, size_t size)
{
  ptr = realloc (ptr, size);
  /* Abort if the allocation failed.  */
  if (ptr == NULL)
    abort ();
  else
    return ptr;
}

char* xstrdup (const char* s)
{
  char* copy = strdup (s);
  /* Abort if the allocation failed.  */
  if (copy == NULL)
    abort ();
  else
    return copy;
}

void system_error (const char* operation)
{
  /* Generate an error message for errno.  */
  error (operation, strerror (errno));
}

void error (const char* cause, const char* message)
{
  /* Print an error message to stderr.  */
  fprintf (stderr, "%s: error: (%s) %s\n", program_name, cause, message);
  /* End the program.  */
  exit (1);
}

char* get_self_executable_directory ()
{
  int rval;
  char link_target[1024];
  char* last_slash;
  size_t result_length;
  char* result;

  /* Read the target of the symbolic link /proc/self/exe.  */
  rval = readlink ("/proc/self/exe", link_target, sizeof (link_target) - 1);
  if (rval == -1)
    /* The call to readlink failed, so bail.  */
    abort ();
  else
    /* NUL-terminate the target.  */
    link_target[rval] = '\0';
  /* We want to trim the name of the executable file, to obtain the
     directory that contains it.  Find the rightmost slash.  */
  last_slash = strrchr (link_target, '/');
  if (last_slash == NULL || last_slash == link_target)
    /* Something stange is going on.  */
    abort ();
  /* Allocate a buffer to hold the resulting path.  */
  result_length = last_slash - link_target;
  result = (char*) xmalloc (result_length + 1);
  /* Copy the result.  */
  strncpy (result, link_target, result_length);
  result[result_length] = '\0';
  return result;
}
