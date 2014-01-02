SnailIntepreter
==========

#### Snail语言解释器

1.已经实现基本功能,最后一行为空行表示结束；

2.if 语句的嵌套功能由递归实现；

3.程序暂时不支持一行输入多行语句；

4.程序不支持使用‘\t’ TAB缩进对齐，仅支持空格对齐；

5.if语句输入格式：

```C
    if exp then
	stmt_list
	    (else)
  	    (stmt_list)
     endif
```

