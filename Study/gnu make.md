# GNU Make

## 2. An Introduction to Makefile
A target can also be the name of an action to carry out, such as 'clean'.

A tab character (or whatever character is specified by the .RECIPEPREFIX variable) must come at the beginning of every line in the recipe to _distinguish_ recipes _from_ other lines in the makefile.

> .RECIPEPREFIX在3.82以后的版本中才被支持。

Targets that do not refer to files but are just actions are called phony targets.

By default,make starts with the first target (not targets whose names start '.').

A target whose name stats '.' can be treated as default goal with the .DEFAULT_GOAL special variable.

```
.PHONY: clean
clean:
	-rm edit $(objects)
```
This prevents *make* from getting confused by an actual file called *clean* and causes it to continue in spite of errors from rm.

> in spite of sth:  without being affected or prevented by something

## 3. Writing Makefiles
Makefiles contain five kinds of things: explicit rules, implicit rules, variable definitions, directive, and comments.

$You cannot use comments within variable references or function calls: any instance of # will be treated literally(rather than as the start of a comment) inside a variable reference or function call.$

### Including Other Makefiles
The directive is a line in the makefile that looks like this:

`include filenames ...`

Filenames can contain shell file name patterns. If filenames is empty, nothing is included and no error is printed.

Extra spaces are allowed and ignored at the beginning of the line, but the first character must not be a tab(or the value of .RECIPEPREFIX) --- if the line begins with a tab, it will be considered a recipe line.

Whitespace is required between include and the file names, and between file names;extra whitespace is ignored there and at the end of the directive.

```
	a.mk b.mk c.mk, $(bar) = bish bash
	include foo *.mk $(bar)  <==> include foo a.mk b.mk c.mk bish bash
```

If the specified name does not start with a slash, and the file is not found in the current directory,servral other directories are searched. First,any directories you have specified with the '-I' or '--include-dir' option are searched. Then the following directories are searched, in this order: `/usr/local/include, /usr/gnu/include, /usr/include`.

> slash: 斜线，这里应该是路径中的根目录的意思了，表示$指明了目录。$

Once it has finished reading makefiles, make will try to $remake$ any that are out of date or don't exist. Only after it has tried to find a way to $remake$ a makefile and failed, will make diagnose the missing makefile as a fatal error.

If you want  *make*  to simply ignore a makefile which does not exist or cannot be remade, with no error message, use the -include directive instead of include, like this:

`-include filenames ...`

For compatibility with some other *make* implementations, *sinclude* is another name for *-include* .

### The Variable MAKEFILES
If the environment variable MAKEFILES is defined, *make* considers its value as a list of names (separated by whitespace) of additional makefiles to be read before the others.

This works must like the *include* directive:various directories are searched for those files. In addition, the default goal is never taken from one of these makefiles (or any makefiles include by them) and it is not an error if the files listed in MAKEFILES are not found.

The main use of MAKEFILES is in communication between recursive invocations of *make* . It usually is not desirable to set the environment variable before a top-level invocation of *make* , because it is usually better not to mess with a makefile from outside.

### How Makefiles Are Remade
Sometimes makefiles can be remade from other files, such as RCS or SCCS files. If a makefile can be remade from other files, you probably want *make* to get an up-to-date version of the makefile to read in.

If the makefiles specify a $double-colon$ rule to remake a file with a recipe but no prerequisites, that file will always be remade.

In the case of makefiles, a makefile that has a double-colon rule with a recipe but no prerequsites will be remade every time *make* is run, and then again after *make* starts over and reads the makefiles again. This would cause an infinite loop: *make* would constantly remake the makefile,and never do anything else. So to avoid this,make will not attempt to remake makefiles which are specified as targets of a double-colon rule with a recipe but no prerequisites.

> 一个双冒号目标，没有依赖，有一个explicit的recipe:上面3个条件成立时这个目标将会每次都执行。

$Note that it is not an error if *make* cannot find or make any makefile;a makefile is not always necessary.$

'-t' or '--touch', '-q' or '--question', 'n' or '--just-print' do not prevent updating of makefiles, because an out-of-date makefile would result in the wrong output for other targets.

Thus,'make -f mfile -n foo' will update 'mfile',read it in and then print the recipe to update 'foo' and its prerequisites without running it.The recipe printed for 'foo' will be the one specified in the updated contents of 'mfile'.

However,you can prevent updating of even the makefiles by specifying the makefiles as goals in the command line as well as specifying them as makefiles.

Thus,'make -f mfile -n mfile foo' would read the makefile 'mfile',print the recipe needed to upate it without actually running it, and then print the recipe need to update 'foo' without running that.

Makefile:
```
include remake.mk

all:
	@cat remake.mk
	@echo $(dat)
remake.mk:
	echo  dat=101 > remake.mk
```

执行`make`:
```
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
dat=101
101
```
include报警告，但是会继续，然后根据后续规则生成include的文件，然后重新read `remake.mk` in.

#### 验证1：
删掉remake.mk:`rm remake.mk`;重新make：`make -n`：
```
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
cat remake.mk
echo 101
```
虽然添加了`-n`参数，但是还是会生成自动生成（更行）remake.mk文件。

#### 验证2：
删掉remake.mk:`rm remake.mk`;把remake.mk指定为目标，重新make：`make -n remake.mk`：
```
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
Makefile:1: remake.mk: No such file or directory
echo  dat=101 > remake.mk
...
```
不会更新remake.mk，陷入死循环。

make -f mfile,然后更新自身的情况，还没有尝试。

### Overriding Part of Another Makefile
