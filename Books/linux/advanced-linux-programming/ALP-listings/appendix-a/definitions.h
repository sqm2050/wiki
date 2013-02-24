/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#ifndef DEFINITIONS_H
#define DEFINITIONS_H 1

/* Implement a number using a linked list.  */
struct LinkedListNumber 
{
  struct LinkedListNumber*
		one_less_;
};
typedef struct LinkedListNumber* number;

/* Implement a stack of number's as a linked list.  Use 0 to represent
   an empty stack.  */
struct StackElement 
{
  number 	element_;
  struct 	StackElement* next_;
};
typedef struct StackElement* Stack;

/* Operate on the stack of numbers.  */
Stack create_stack ();
int empty_stack (Stack stack);
number pop_stack (Stack* stack);
void push_stack (Stack* stack, number n);
void clear_stack (Stack* stack);

/* Operations on numbers.  */
number make_zero ();
void destroy_number (number n);
number add (number n1, number n2);
number subtract (number n1, number n2);
number product (number n1, number n2);
number even (number n);
number odd (number n);
number string_to_number (char* char_number);
unsigned number_to_unsigned_int (number n);

#endif /* DEFINITIONS_H */
