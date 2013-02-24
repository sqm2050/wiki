/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <pthread.h>

extern bool should_exit_thread_immediately ();

class ThreadExitException
{
public:
  /* Create an exception signalling thread exit with RETURN_VALUE.  */
  ThreadExitException (void* return_value)
    : thread_return_value_ (return_value)
  {
  }

  /* Actually exit the thread, using the return value provided in the
     constructor.  */
  void* DoThreadExit ()
  {
    pthread_exit (thread_return_value_);
  }

private:
  /* The return value that will be used when exiting the thread.  */
  void* thread_return_value_;
};

void do_some_work ()
{
  while (1) {
    /* Do some useful things here...  */

    if (should_exit_thread_immediately ()) 
      throw ThreadExitException (/* thread's return value = */ NULL);
  }
}

void* thread_function (void*)
{
  try {
    do_some_work ();
  }
  catch (ThreadExitException ex) {
    /* Some function indicated that we should exit the thread.  */
    ex.DoThreadExit ();
  }
  return NULL;
}
