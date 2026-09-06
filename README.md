# UnixLinuxProgram

《Unix-Linux编程实践教程》
书籍源码

linux cmmake编译

### 工具版本

（以下为当前实际环境版本，2026-09 实测）

- 系统：Ubuntu 24.04，x86_64
- gcc / g++：13.3.0（Ubuntu 13.3.0-6ubuntu2~24.04.1）
- cmake：3.28.3
- make：GNU Make 4.3
- IDE：CLion（新版本即可；旧版 2019.3 需 cmake 3.15 支持）

```shell script
gcc --version
gcc (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0

cmake --version
cmake version 3.28.3

make --version
GNU Make 4.3
```

### 没有搞定的项目

无（全部目标 cmake 编译通过，可执行程序在 build/ 目录）

- who3.c / utmp_open() / utmp_next() / utmp_close() 已解决：
  新建 CH02/utmplib.h，who3、who3top 链接 CH02_utmplib 静态库。
  注：who3top.c 原文件不完整（文件尾部注释被截断），现按
  who3top(main) + who1bot.c(show_info) + utmplib 结构编译通过；
  如需 who3 风格(showtime 格式化时间)输出，可再补充 who3bot.c。


### linux c api has?

libncurses

splite CH01

