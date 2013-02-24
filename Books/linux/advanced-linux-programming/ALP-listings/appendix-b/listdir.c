/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* Return a string that describes the type of the file system entry PATH.  */

const char* get_file_type (const char* path)
{
  struct stat st;
  lstat (path, &st);
  if (S_ISLNK (st.st_mode))
    return "symbolic link";
  else if (S_ISDIR (st.st_mode))
    return "directory";
  else if (S_ISCHR (st.st_mode))
    return "character device";
  else if (S_ISBLK (st.st_mode))
    return "block device";
  else if (S_ISFIFO (st.st_mode))
    return "fifo";
  else if (S_ISSOCK (st.st_mode))
    return "socket";
  else if (S_ISREG (st.st_mode))
    return "regular file";
  else
    /* Unexpected.  Each entry should be one of the types above.  */
    assert (0);
}

int main (int argc, char* argv[])
{
  char* dir_path;
  DIR* dir;
  struct dirent* entry;
  char entry_path[PATH_MAX + 1];
  size_t path_len;

  if (argc >= 2)
    /* If a directory was specified on the command line, use it.  */
    dir_path = argv[1];
  else 
    /* Otherwise, use the current directory.  */
    dir_path = ".";
  /* Copy the directory path into entry_path.  */
  strncpy (entry_path, dir_path, sizeof (entry_path));
  path_len = strlen (dir_path);
  /* If the directory path doesn't end with a slash, append a slash.  */
  if (entry_path[path_len - 1] != '/') {
    entry_path[path_len] = '/';
    entry_path[path_len + 1] = '\0';
    ++path_len;
  }

  /* Start the listing operation of the directory specified on the
     command line.  */
  dir = opendir (dir_path);
  /* Loop over all directory entries.  */
  while ((entry = readdir (dir)) != NULL) {
    const char* type;
    /* Build the path to the directory entry by appending the entry
       name to the path name.  */
    strncpy (entry_path + path_len, entry->d_name,
	     sizeof (entry_path) - path_len);
    /* Determine the type of the entry.  */
    type = get_file_type (entry_path);
    /* Print the type and path of the entry.  */
    printf ("%-18s: %s\n", type, entry_path);
  }

  /* All done.  */
  closedir (dir);
  return 0;
}
