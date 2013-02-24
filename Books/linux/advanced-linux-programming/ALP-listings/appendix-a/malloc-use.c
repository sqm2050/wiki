/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

/* Use C's dynamic memory allocation functions.  */

/* Invoke the program using one command-line argument specifying the
   size of an array.  This array consists of pointers to (possibly)
   allocated arrays.
   
   When the programming is running, select among the following
   commands:

   o allocate memory:	a <index> <memory-size>
   o deallocate memory:	d <index>
   o read from memory:	r <index> <position-within-allocation>
   o write to memory:	w <index> <position-within-allocation>
   o quit:		q

   The user is respond for obeying (or disobeying the rules on dynamic
   memory use.  */

#ifdef MTRACE
#include <mcheck.h>
#endif /* MTRACE */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Allocate memory with the specified size, returning nonzero upon
   success.  */

void allocate (char** array, size_t size)
{
  *array = malloc (size);
}

/* Deallocate memory.  */

void deallocate (char** array)
{
  free ((void*) *array);
}

/* Read from a position in memory.  */

void read_from_memory (char* array, int position)
{
  volatile char character = array[position];
}

/* Write to a position in memory.  */

void write_to_memory (char* array, int position)
{
  array[position] = 'a';
}

int main (int argc, char* argv[])
{
  char** array;
  unsigned array_size;
  char command[32];
  unsigned array_index;
  char command_letter;
  int size_or_position;
  int error = 0;

#ifdef MTRACE
  mtrace ();
#endif /* MTRACE */

  if (argc != 2) {
    fprintf (stderr, "%s: array-size\n", argv[0]);
    return 1;
  }
  
  array_size = strtoul (argv[1], 0, 0);
  array = (char **) calloc (array_size, sizeof (char *));
  assert (array != 0);

  /* Follow the user's commands.  */
  while (!error) {
    printf ("Please enter a command: ");
    command_letter = getchar ();
    assert (command_letter != EOF);
    switch (command_letter) {

    case 'a':
      fgets (command, sizeof (command), stdin);
      if (sscanf (command, "%u %i", &array_index, &size_or_position) == 2 
	  && array_index < array_size)
	allocate (&(array[array_index]), size_or_position);
      else
	error = 1;
      break;

    case 'd':
      fgets (command, sizeof (command), stdin);
      if (sscanf (command, "%u", &array_index) == 1
	  && array_index < array_size)
	deallocate (&(array[array_index]));
      else
	error = 1;
      break;

    case 'r':
      fgets (command, sizeof (command), stdin);
      if (sscanf (command, "%u %i", &array_index, &size_or_position) == 2
	  && array_index < array_size)
	read_from_memory (array[array_index], size_or_position);
      else
	error = 1;
      break;

    case 'w':
      fgets (command, sizeof (command), stdin);
      if (sscanf (command, "%u %i", &array_index, &size_or_position) == 2
	  && array_index < array_size)
	write_to_memory (array[array_index], size_or_position);
      else
	error = 1;
      break;

    case 'q':
      free ((void *) array);
      return 0;

    default:
      error = 1;
    }
  }

  free ((void *) array);
  return 1;
}
