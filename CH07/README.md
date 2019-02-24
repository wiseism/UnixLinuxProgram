# error

在网上找了很久后终于发现了问题所在。因为 curses 不是linux里默认的C函数库，所以导致编译时未找到函数定义
  
正确的方法是：
g++ snack.cpp -o snack -l curses
./snack

```shell

====================[ Build | CH07_bounce_aio | Debug ]=========================
/home/edidada/clion-2018.2.6/bin/cmake/linux/bin/cmake --build /home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/cmake-build-debug --target CH07_bounce_aio -- -j 2
Scanning dependencies of target CH07_bounce_aio
[100%] Building C object CMakeFiles/CH07_bounce_aio.dir/CH07/bounce_aio.c.o
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH07/bounce_aio.c: In function ‘set_ticker’:
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH07/bounce_aio.c:30:5: warning: type of ‘n_msecs’ defaults to ‘int’ [-Wimplicit-int]
 int set_ticker( n_msecs )
     ^
[100%] Linking C executable CH07_bounce_aio
CMakeFiles/CH07_bounce_aio.dir/CH07/bounce_aio.c.o：在函数‘main’中：
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH07/bounce_aio.c:59：对‘aio_read’未定义的引用
CMakeFiles/CH07_bounce_aio.dir/CH07/bounce_aio.c.o：在函数‘on_input’中：
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH07/bounce_aio.c:80：对‘aio_error’未定义的引用
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH07/bounce_aio.c:84：对‘aio_return’未定义的引用
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH07/bounce_aio.c:94：对‘aio_read’未定义的引用
collect2: error: ld returned 1 exit status
make[3]: *** [CH07_bounce_aio] 错误 1
make[2]: *** [CMakeFiles/CH07_bounce_aio.dir/all] 错误 2
make[1]: *** [CMakeFiles/CH07_bounce_aio.dir/rule] 错误 2
make: *** [CH07_bounce_aio] 错误 2


```

[p-sdgaenyd-yx](http://www.voidcn.com/article/p-sdgaenyd-yx.html)

[conflicting types for ‘malloc’](https://stackoverflow.com/questions/47794084/error-conflicting-types-for-malloc)

[CLion中使用CMake导入第三方库的方法](https://blog.csdn.net/haoran823/article/details/71657602)

对‘splitline’未定义的引用
对‘aio_read’未定义的引用


- bounce1d
- bounce2d

```shell

bounce1d
hello

```

```shell
bounce2d
 o
 o
 o
 o
 o
 o
 o
 o
 o
 o
 o
 o
oo
oo
o
oo
oo
oo
o
oo
oo
oo
o
oo


```

