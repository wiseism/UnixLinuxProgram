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
