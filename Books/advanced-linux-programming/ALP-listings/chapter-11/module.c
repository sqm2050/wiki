/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"

char* module_dir;

struct server_module* module_open (const char* module_name)
{
  char* module_path;
  void* handle;
  void (* module_generate) (int);
  struct server_module* module;

  /* Construct the full path of the module shared library we'll try to
     load.  */
  module_path = 
    (char*) xmalloc (strlen (module_dir) + strlen (module_name) + 2);
  sprintf (module_path, "%s/%s", module_dir, module_name);

  /* Attempt to open MODULE_PATH as a shared library.  */
  handle = dlopen (module_path, RTLD_NOW);
  free (module_path);
  if (handle == NULL) {
    /* Failed; either this path doesn't exist, or it isn't a shared
       library.  */
    return NULL;
  }

  /* Resolve the module_generate symbol from the shared library.  */
  module_generate = (void (*) (int)) dlsym (handle, "module_generate");
  /* Make sure the symbol was found.  */
  if (module_generate == NULL) {
    /* The symbol is missing.  While this is a shared library, it
       probably isn't a server module.  Close up and indicate failure.  */
    dlclose (handle);
    return NULL;
  }

  /* Allocate and initialize a server_module object.  */
  module = (struct server_module*) xmalloc (sizeof (struct server_module));
  module->handle = handle;
  module->name = xstrdup (module_name);
  module->generate_function = module_generate;
  /* Return it, indicating success.  */
  return module;
}

void module_close (struct server_module* module)
{
  /* Close the shared library.  */
  dlclose (module->handle);
  /* Deallocate the module name.  */
  free ((char*) module->name);
  /* Deallocate the module object.  */
  free (module);
}
