# error

在网上找了很久后终于发现了问题所在。因为 curses 不是linux里默认的C函数库，所以导致编译时未找到函数定义
  
正确的方法是：
g++ snack.cpp -o snack -l curses
./snack

[p-sdgaenyd-yx](http://www.voidcn.com/article/p-sdgaenyd-yx.html)

[conflicting types for ‘malloc’](https://stackoverflow.com/questions/47794084/error-conflicting-types-for-malloc)

[CLion中使用CMake导入第三方库的方法](https://blog.csdn.net/haoran823/article/details/71657602)

对‘splitline’未定义的引用
对‘aio_read’未定义的引用