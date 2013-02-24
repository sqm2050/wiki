/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

/* Operate on unary numbers.  */

#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "definitions.h"

/* Create a number representing zero.  */

number make_zero ()
{
  return 0;
}

/* Return nonzero if the number represents zero.  */

int zerop (number n)
{
  return n == 0;
}

/* Decrease a positive number by one.  */

number decrement_number (number n)
{
  number answer;
  assert (!zerop (n));
  answer = n->one_less_;
  free (n);
  return answer;
}

/* Add 1 to a number.  */

number add_one (number n)
{
  number answer = malloc (sizeof (struct LinkedListNumber));
  answer->one_less_ = n;
  return answer;
}

/* Destroying a number.  */

void destroy_number (number n)
{
  while (!zerop (n))
    n = decrement_number (n);
}

/* Copy a number.  This function is only needed because of memory
   allocation.  */

number copy_number (number n)
{
  number answer = make_zero ();
  while (!zerop (n)) {
    answer = add_one (answer);
    n = n->one_less_;
  }
  return answer;
}

/* Add two numbers.  */

number add (number n1, number n2)
{
  number answer = copy_number (n2);
  number addend = n1;
  while (!zerop (addend)) {
    answer = add_one (answer);
    addend = addend->one_less_;
  }
  return answer;
}

/* Subtract a number from another.  */

number subtract (number n1, number n2)
{
  number answer = copy_number (n1);
  number subtrahend = n2;
  while (!zerop (subtrahend)) {
    assert (!zerop (answer));
    answer = decrement_number (answer);
    subtrahend = subtrahend->one_less_;
  }
  return answer;
}

/* Return the product of two numbers.  */

number product (number n1, number n2)
{
  number answer = make_zero ();
  number multiplicand = n1;
  while (!zerop (multiplicand)) {
    number answer2 = add (answer, n2);
    destroy_number (answer);
    answer = answer2;
    multiplicand = multiplicand->one_less_;
  }
  return answer;
}

/* Return nonzero if number is even.  */

number even (number n)
{
  if (zerop (n))
    return add_one (make_zero ());
  else
    return odd (n->one_less_);
}

/* Return nonzero if number is odd.  */

number odd (number n)
{
  if (zerop (n))
    return make_zero ();
  else
    return even (n->one_less_);
}

/* Convert a string representing a decimal integer into a "number".  */

number string_to_number (char * char_number)
{
  number answer = make_zero ();
  int num = strtoul (char_number, (char **) 0, 0);
  while (num != 0) {
    answer = add_one (answer);
    --num;
  }
  return answer;
}

/* Convert a "number" into an "unsigned int".  */

unsigned number_to_unsigned_int (number n)
{
  unsigned answer = 0;
  while (!zerop (n)) {
    n = n->one_less_;
    ++answer;
  }
  return answer;
}
