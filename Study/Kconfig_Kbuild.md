## 标签
### mainmenu
界面标题

### config
配置,会在 _.config_ 中生成 _CONFIG_ 开头的宏名字.

### prompt
是 *choice* 菜单的标题.

### choice
单选，里面由 *config* 组成,而且是 _bool_ 类型,由 _endchoice_ 结束

### menu
进入下一级菜单,由 *endmenu* 结束。



## 语句
### depends on
表示依赖于。如果不是在两个 *menu* 的依赖，就会自动显示

### 类型
类型有 int,bool,string型，类型后面可以紧跟随说明。

### default
类型int的话指定为数字，bool类型的话是y/n.

### range
`range 1 16`是`1<<= n << 16`

### if
1. `if`放在上面语句同一行的最后面,作为条件
2. 可以`if XXX`换行后，进行整块的选择，和 *depends on* 作用相似
