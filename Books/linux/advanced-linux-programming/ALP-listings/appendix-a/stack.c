/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

/* Provide a stack of "number"s.  */

#include <assert.h>
#include <stdlib.h>
#include "definitions.h"

/* Create an empty stack.  */

Stack create_stack ()
{
  return 0;
}

/* Return nonzero if the stack is empty.  */

int empty_stack (Stack stack)
{
  return stack == 0;
}

/* Remove the number at the top of a non-empty stack.  If the stack is
   empty, abort.  */

number pop_stack (Stack* stack)
{
  number answer;
  Stack rest_of_stack;

  assert (!empty_stack (*stack));
  answer = (*stack)->element_;
  rest_of_stack = (*stack)->next_;
  free (*stack);
  *stack = rest_of_stack;
  return answer;
}

/* Add a number to the beginning of a stack.  */

void push_stack (Stack* stack, number n)
{
  Stack new_stack = malloc (sizeof (struct StackElement));
  new_stack->element_ = n;
  new_stack->next_ = *stack;
  *stack = new_stack;
}

/* Remove all the stack's elements.  */

void clear_stack (Stack* stack)
{
  while (!empty_stack (*stack)) {
    number top = pop_stack (stack);
    destroy_number (top);
  }
}
