/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
  int fd;
  struct iovec* vec;
  struct iovec* vec_next;
  int i;
  /* We'll need a "buffer" containing a newline character.  Use an
     ordinary char variable for this.  */
  char newline = '\n';
  /* The first command-line argument is the output filename.  */
  char* filename = argv[1];
  /* Skip past the first two elements of the argument list.  Element
     zero is the name of this program, and element one is the output
     filename.  */
  argc -= 2;
  argv += 2;

  /* Allocate an array of iovec elements.  We'll need two for each
     element of the argument list, one for the text itself and one for
     a newline.  */
  vec = (struct iovec*) malloc (2 * argc * sizeof (struct iovec));

  /* Loop over the argument list, building the iovec entries.  */
  vec_next = vec;
  for (i = 0; i < argc; ++i) {
    /* The first element is the text of the argument itself.  */
    vec_next->iov_base = argv[i];
    vec_next->iov_len = strlen (argv[i]);
    ++vec_next;
    /* The second element is a single newline character.  It's OK for
       multiple elements of the struct iovec array to point to the
       same region of memory.  */
    vec_next->iov_base = &newline;
    vec_next->iov_len = 1;
    ++vec_next;
  }

  /* Write the arguments to a file.  */
  fd = open (filename, O_WRONLY | O_CREAT);
  writev (fd, vec, 2 * argc);
  close (fd);

  free (vec);
  return 0;
}
