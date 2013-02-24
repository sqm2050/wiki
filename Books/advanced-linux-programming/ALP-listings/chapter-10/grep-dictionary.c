/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Returns a non-zero value if and only if the WORD appears in
   /usr/dict/words.  */

int grep_for_word (const char* word) 
{
  size_t length;
  char* buffer;
  int exit_code;

  /* Build up the string `grep -x WORD /usr/dict/words'.  Allocate the
     string dynamically to avoid buffer overruns.  */
  length = 
    strlen ("grep -x ") + strlen (word) + strlen (" /usr/dict/words") + 1;
  buffer = (char*) malloc (length);
  sprintf (buffer, "grep -x %s /usr/dict/words", word);

  /* Run the command.  */
  exit_code = system (buffer);
  /* Free the buffer.  */
  free (buffer);
  /* If grep returned zero, then the word was present in the
     dictionary.  */
  return exit_code == 0;
}

