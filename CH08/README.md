# CH08


### error

对‘splitline’未定义的引用

- forkdemo1
- forkdemo2
- forkdemo3
- waitdemo1
- waitdemo2

### forkdemo1

```shell

forkdemo1
Before: my pid is 6261
After: my pid is 6261, fork() said 6262
After: my pid is 6262, fork() said 0

```

### forkdemo2

```shell

forkdemo2
my pid is 6125
my pid is 6125
my pid is 6128

```

### forkdemo3

```shell

forkdemo3
Before: my pid is 6371
I am the parent. my child is 6373
I am the child.  my pid=6373

```

### waitdemo1

```shell

waitdemo1
before: mypid is 5162
child 5163 here. will sleep for 2 seconds
child done. about to exit
done waiting for 5163. Wait returned: 5163

```

### waitdemo2

```shell

waitdemo2
before: mypid is 5063
child 5064 here. will sleep for 5 seconds
child done. about to exit
done waiting for 5064. Wait returned: 5064
status: exit=17, sig=0, core=0

```


execl, execlp, execle, execv, execvp, execvpe - execute a file

getpid, getppid - get process identification

fork, wait, waitpid - basic process management

sleep - delay for a specified amount of time:

#### printf

printf中分别代表的输出类型：   
%a(%A)：浮点数、十六进制数字和p-(P-)记数法(C99)
%c：字符
%d：有符号十进制整数
%f：浮点数(包括float和doulbe)
%e(%E)：浮点数指数输出[e-(E-)记数法]
%g(%G)：浮点数不显无意义的零"0"
%i：有符号十进制整数(与%d相同)
%u：无符号十进制整数
%o：八进制整数 e.g. 0123
%x(%X)：十六进制整数0f(0F) e.g. 0x1234
%p：指针
%s：字符串
%%："%" 

### exevcp

相关函数：fork, execl, execle, execlp, execv, execve
头文件：#include <unistd.h>
定义函数：int execvp(const char *file, char * const argv []);
函数说明：execvp()会从PATH 环境变量所指的目录中查找符合参数file 的文件名, 找到后便执行该文件, 然后将第二个参数argv 传给该欲执行的文件。
返回值：如果执行成功则函数不会返回, 执行失败则直接返回-1, 失败原因存于errno 中.
错误代码：请参考 execve ()。
范例
/*请与execlp ()范例对照 */

```c

#include <unistd.h>
main()
{
    char * argv[] = {"ls", "-al", "/etc/passwd", 0};
    execvp("ls", argv);
}

```

执行：
`-rw-r--r-- 1 root root 705 Sep 3 13 :52 /etc/passwd`


#### fork

`man fork`
fork, wait, waitpid - basic process management
fork 创建子进程
wait  进程一旦调用了wait，就立即阻塞自己，由wait自动分析是否当前进程的某个子进程已经 退出，如果让它找到了这样一个已经变成僵尸的子进程，wait就会收集这个子进程的信息，并把它彻底销毁后返回；如果没有找到这样一个子进程，wait就 会一直阻塞在这里，直到有一个出现为止。
     
wait和waitpid函数是用来处理僵死进程的。https://www.cnblogs.com/yusenwu/p/4655286.html

fork
返回值是pid_t
-1 出错
0  子进程
其他 父进程(原有进程)
