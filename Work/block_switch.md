## 模块选中，抹去，优先级设置
### 基本结构:
```
struct _acl_fun {
	char name[10];
	int (*fun)(int, int);
	int lvl;
};

struct _acl_fun fun_arr[] = {
	{"fun1", fun_1, 0},
	{"fun2", fun_2, 0},
	{"fun3", fun_3, 0}
};
```

### 位图变量:
```
int bit_map = 0;
```

### 操作:
#### 设置
```
set_fun(char *fun, int lvl)
{
	if (lvl == 0 ) {
		set_zero(fun);
		return;
	}
		
	check_remove(lvl);
	
	set_lvl;
}
```

#### 重置
```
reset_fun()
{
	bit_map = 0;
	for() {
			fun_arr[i].lvl = 0;
	}
}
```
