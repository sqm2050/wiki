sed就是要注意模式空间的概念，操作（替换，打印，删除等）的对象都是它。


sed -r ':a;$!N;/#/!s/\n/ /;ta;P;D' urfile

@urfile:
	#
	1
	2
	3

-r, --regexp-extended
	use extended regular expressions in the script 使用扩展的正则表达式

1.经过N处理过的输出和原文件没有区别，但是本质不一样了。原文件，就会像下面：
	#\n1
	2\n3

2.读入第一个pattern space /#/,$!成立，执行N命令，创建多行模式空间，就如上所示

3.紧接着，读入pattern space /#\n1/,/#/!条件不成立，不执行s/\n/ /，跳过ta，执行
P，打印“#“，执行D，删除”#\n“，pattern space内容为/1/。

4.随后，读入pattern space /1\n2/,/#/!条件成立，执行s/\n/ /,跳转到：a，进入循环
pattern space内容位/1 2/。
	#
---> 	1 2\n3

5.打印出#是因为，P D作用的结果。

6.因为D命令执行成功后会使得控制流跳到脚本的第一条语句，这里，就是跳到了 :a处，
也进入一个新的循环。

7.新的开始，从:a开始执行，所以当前的行号是2，也就是说$!永远成立，这也就说明了N
前面加不加$!都是可以的，效果一样。
	#
--->	1 2 3

8.打印出1 2 3 是因为跳出循环，又因为N没有下一行可以读了，所以就exit 了，不再执
行后面的命令（这里说明退出循环是N的作用），则时候pattern spaced的内容是/1 2 3/
因此就被输出到了标准输出上。这也间接说明了加了-n后1 2 3就全被抑制输出了

上面用到的选项的说明：

注意大P和小p的作用意义不同：

p: print the current pattern space
   打印当前模式空间的内容。

P: Print up to the first embedded newline of the current pattern space.
   打印当前模式空间的第一行。

D: Delete up to the first embedded newline in the pattern space.Start next cy-
   ccle,but skip reading from the input if there data in the pattern space,wi-
   th-out reading a new line of input.
   删除模式空间中开头到第一个换行符之间的内容.并且把控制流跳到第一条语句。但是
   如果模式空间有数据就不会读入新的行。

N: Add a newline to the pattern space,then append the next line of input to t-
   he pattern space.If there is no more input then sed exits without processi-
   ng any more commands.
   追加下一行到模式空间的后面，如果没有了输入，sed就会退出，而不进行更多的处理
{{{
	$ cat urfile:
		1111
	$ sed 'N;s/1111/2222/g' urfile
		1111
	因为，只有一行，读不到下一行，就直接退出了。
									}}}

sed的调试：
{{{
	$ cat npd
	$ :a;$!N;/#/!s/\n/ /;ta;P;D

	$ cat urfile | sedsed -d -f npd
									}}}
{{{
	[root@PTS-300 test]# cat file2.txt
		4.iso
		3.iso
		2.iso
		1.iso
	[root@PTS-300 test]# sed 'N;$!P;' file2.txt
		4.iso
		4.iso
		3.iso
		2.iso
		1.iso
	用sedsed查看到执行过程如下：
	[root@PTS-300 test]# cat file2.txt | sedsed -d -f npd2
		PATT:4.iso$
		HOLD:$
		COMM:N
		PATT:4.iso\n3.iso$
		HOLD:$
		COMM:$ !P
		4.iso
		PATT:4.iso\n3.iso$
		HOLD:$			#这里打印出来4.iso 和 3.iso是因为不是循环执行N命令，所以会先打出模式空间的信息
		4.iso			#再去在读入新行
		3.iso
		PATT:2.iso$
		HOLD:$
		COMM:N
		PATT:2.iso\n1.iso$
		HOLD:$
		COMM:$ !P
		PATT:2.iso\n1.iso$
		HOLD:$
		2.iso
		1.iso
	[root@PTS-300 test]# cat npd2
		N;$!P;
									}}}
------------------------------------------------------------------------------
sed:
{{{
	#!/bin/sh

	search=$1
	shift
	for file
	do
	sed '
	/'"$search"'/b
	N
	h
	s/.*\n//
	/'"$search"'/b
	g
	s/ *\n/ /
	/'"$search"'/{
	g
	b
	}
	g
	D' $file
	done

	cat urfile:
		Stray birds of summer come to my 
		window to sing and fly away.
		Come to my window，baby！

	sh sed.sh "my window" urfile
									}}}
