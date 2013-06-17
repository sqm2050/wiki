## 回退一个版本
### 首先显示一下版本日志：
```
svn log					# 必须在联网的情况下
```
### 回退版本,奇怪的是使用merge
```
svn merge -r 30:29 ""		# 这时候本地文件没有更改，只是本地代码库被修改了
```
### 与响应的版本比较
```
svn diff -r 29 ufile
```
### 恢复文件
```
svn revert ufile
```

SVN子命令diff三大用法详解
2010-05-24 14:57 佚名 我要评论(0) 字号：T | T

本文和大家讨论一下SVN子命令diff的用法，主要有检查本地修改、比较工作拷贝与版本库和比较版本库和版本库等用法，希望大家通过本文的学习能够掌握。
AD：2013大数据全球技术峰会课程PPT下载
本节接着上篇文章介绍SVN使用SVN子命令log,list,cat,diff查看所有及特定文件版本信息，本节主要介绍SVN子命令diff的用法，希望大家来一起学习。

检查历史修改的详情
我们已经看过SVN子命令 diff—使用标准区别文件格式显示区别，它在提交前用来显示本地工作拷贝与版本库的区别。
事实上，SVN子命令diff有三种不同的用法：
检查本地修改 
比较工作拷贝与版本库 
比较版本库与版本库

比较本地修改
像我们看到的，不使用任何参数调用时，svn diff将会比较你的工作文件与缓存在.svn的“原始”拷贝：
$ svn diff
Index: rules.txt
===================================================================
--- rules.txt    (revision 3)
+++ rules.txt    (working copy)
@@ -1,4 +1,5 @@
Be kind to others
Freedom = Responsibility
Everything in moderation
-Chew with your mouth open
+Chew with your mouth closed
+Listen when others are speaking
[/pre]比较工作拷贝和版本库
如果传递一个--revision（-r）参数，你的工作拷贝会与指定的版本比较。
$ svn diff -r 3 rules.txt
Index: rules.txt
===================================================================
--- rules.txt    (revision 3)
+++ rules.txt    (working copy)
@@ -1,4 +1,5 @@
Be kind to others
Freedom = Responsibility
Everything in moderation
-Chew with your mouth open
+Chew with your mouth closed
+Listen when others are speaking
[/pre]SVN子命令diff比较版本库与版本库
如果通过--revision （-r）传递两个通过冒号分开的版本号，这两个版本会进行比较。
$ svn diff -r 2:3 rules.txt
Index: rules.txt
===================================================================
--- rules.txt    (revision 2)
+++ rules.txt    (revision 3)
@@ -1,4 +1,4 @@
Be kind to others
-Freedom = Chocolate Ice Cream
+Freedom = Responsibility
Everything in moderation
Chew with your mouth open
[/pre]与前一个修订版本比较更方便的办法是使用--change (-c)：
$ svn diff -c 3 rules.txt
Index: rules.txt
===================================================================
--- rules.txt    (revision 2)
+++ rules.txt    (revision 3)
@@ -1,4 +1,4 @@
Be kind to others
-Freedom = Chocolate Ice Cream
+Freedom = Responsibility
Everything in moderation
Chew with your mouth open
[/pre]最后，即使你在本机没有工作拷贝，还是可以比较版本库的修订版本，只需要在命令行中输入合适的URL：
$ svn diff -c 5 http://svn.example.com/repos/example/trunk/text/rules.txt…
[/pre]浏览版本库
通过svn cat和svn list，你可以在未修改工作修订版本的情况下查看文件和目录的内容，实际上，你甚至也不需要有一个工作拷贝。
SVN子命令 cat            
如果你只是希望检查一个过去的版本而不希望察看它们的区别，使用svn cat：
$ svn cat -r 2 rules.txt
Be kind to others
Freedom = Chocolate Ice Cream
Everything in moderation
Chew with your mouth open
[/pre]你可以重定向输出到一个文件：
$ svn cat -r 2 rules.txt > rules.txt.v2
[/pre]              svn list            
svn list可以在不下载文件到本地目录的情况下来察看目录中的文件：
$ svn list http://svn.collab.net/repos/svn
README，branches/，clients/，tags/，trunk/
[/pre]如果你希望察看详细信息，你可以使用--verbose(-v) 参数：
$ svn list -v http://svn.collab.net/repos/svn
20620 harry            1084 Jul 13  2006 README
23339 harry                 Feb 04 01:40 branches/
21282 sally                 Aug 27 09:41 developer-resources/
23198 harry                 Jan 23 17:17 tags/
23351 sally                 Feb 05 13:26 trunk/
[/pre]这些列告诉你文件和目录最后修改的修订版本、做出修改的用户、如果是文件还会有文件的大小，最后是修改日期和项目的名字。

警告
没有任何参数的SVN子命令 list命令缺省使用当前工作拷贝的版本库URL，而不是本地工作拷贝的目录。毕竟，如果你希望列出本地目录，你只需要使用ls（或任何合理的非UNIX等价物）。
获得旧的版本库快照，除了以上的命令，你可以使用带参数--revision的svn update和svn checkout来使整个工作拷贝“回到过去”[8]：
$ svn checkout -r 1729 # Checks out a new working copy at r1729…
$ svn update -r 1729 # Updates an existing working copy to r1729…
[/pre]提示许多Subversion新手使用前面的svn update实例来“回退”修改，但是你不能提交修改，你获得有新修订版本的过时工作拷贝也是没有用的。关于如何“回退”，我们可以看“找回删除的项目”一节。
最后，如果你构建了一个版本，并且希望从Subversion打包文件，但是你不希望有讨厌的.svn目录，这时你可以导出版本库的一部分文件而没有.svn目录。就像svn update和svn checkout，你也可以传递--revision选项给svn export：
$ svn export http://svn.example.com/svn/repos1 # Exports latest revision…
$ svn export http://svn.example.com/svn/repos1 -r 1729
# Exports revision r1729。部分SVN子命令相关内容讲解完毕。

