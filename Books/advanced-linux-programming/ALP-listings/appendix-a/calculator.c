/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

/* Calculate using unary numbers.  */

/* Enter one-line expressions using reverse postfix notation, e.g.,
     602 7 5 - 3 * +
   Nonnegative numbers are entered using decimal notation.  The
   operators "+", "-", and "*" are supported.  The unary operators
   "even" and "odd" return the number one iff its one operand is even
   or odd, respectively.  Spaces must separate all words.  Negative
   numbers are not supported.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "definitions.h"


/* Apply the binary function with operands obtained from the stack,
   pushing the answer on the stack.  Return nonzero upon success.  */

int apply_binary_function (number (*function) (number, number), 
			   Stack* stack) 
{
  number operand1, operand2;
  if (empty_stack (*stack))
    return 0;
  operand2 = pop_stack (stack);
  if (empty_stack (*stack))
    return 0;
  operand1 = pop_stack (stack);
  push_stack (stack, (*function) (operand1, operand2));
  destroy_number (operand1);
  destroy_number (operand2);
  return 1;
}

/* Apply the unary function with an operand obtained from the stack,
   pushing the answer on the stack.  Return nonzero upon success.  */

int apply_unary_function (number (*function) (number), 
			  Stack* stack) 
{
  number operand;
  if (empty_stack (*stack))
    return 0;
  operand = pop_stack (stack);
  push_stack (stack, (*function) (operand));
  destroy_number (operand);
  return 1;
}

int main ()
{
  char command_line[1000];
  char* command_to_parse;
  char* token;
  Stack number_stack = create_stack ();

  while (1) {
    printf ("Please enter a postfix expression:\n");
    command_to_parse = fgets (command_line, sizeof (command_line), stdin);
    if (command_to_parse == NULL)
      return 0;
    
    token = strtok (command_to_parse, " \t\n");
    command_to_parse = 0;
    while (token != 0) {
      if (isdigit (token[0]))
	push_stack (&number_stack, string_to_number (token));
      else if (((strcmp (token, "+") == 0) &&
		!apply_binary_function (&add, &number_stack)) ||
	       ((strcmp (token, "-") == 0) &&
		!apply_binary_function (&subtract, &number_stack)) ||
	       ((strcmp (token, "*") == 0) &&
		!apply_binary_function (&product, &number_stack)) ||
	       ((strcmp (token, "even") == 0) &&
		!apply_unary_function (&even, &number_stack)) ||
	       ((strcmp (token, "odd") == 0) &&
		!apply_unary_function (&odd, &number_stack)))
	return 1;
      token = strtok (command_to_parse, " \t\n");
    }
    if (empty_stack (number_stack))
      return 1;
    else {
      number answer = pop_stack (&number_stack);
      printf ("%u\n", number_to_unsigned_int (answer));
      destroy_number (answer);
      clear_stack (&number_stack);
    }
  }

  return 0;
}
