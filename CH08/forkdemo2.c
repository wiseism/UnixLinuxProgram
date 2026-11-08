#include <zconf.h>
#include <stdio.h>
#include <unistd.h>       /* 新版 GCC 隐式声明报错 */
//#include <caca_conio.h>

/* forkdemo2.c - shows how child processes pick up at the return
 *               from fork() and can execute any code they like,
 *               even fork().  Predict number of lines of output.
 */

void main()
{
	printf("Before fork my pid is %d\n", getpid() );
	fork();
//	fork();//增加一次fork不增加打印的pid数量，Afrer fork只有三行？
	fork();
	fork();
	printf("After fork my pid is %d\n", getpid() );
}
