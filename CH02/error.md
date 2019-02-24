# error

```shell

====================[ Build | who1 | Debug ]====================================
/home/edidada/clion-2018.2.6/bin/cmake/linux/bin/cmake --build /home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/cmake-build-debug --target who1 -- -j 2
Scanning dependencies of target who1
[100%] Building C object CMakeFiles/who1.dir/CH02/who1.c.o
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH02/who1.c: In function ‘show_info’:
/home/edidada/CLionProjects/linuxcplus/UnixLinuxProgram/CH02/who1.c:41:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int32_t {aka int}’ [-Wformat=]
  printf("%10ld", utbufp->ut_time); /* login time */
         ^
[100%] Linking C executable who1
[100%] Built target who1

Build finished

```
