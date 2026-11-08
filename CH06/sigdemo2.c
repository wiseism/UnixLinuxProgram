/* sigdemo2.c - shows how to ignore a signal
 *            - press Ctrl-\ to kill this one
 */
#include <unistd.h>       /* 新版 GCC 隐式声明报错 */

#include <stdio.h>
#include <signal.h>
#include <zconf.h>

int main()
{
	signal( SIGINT, SIG_IGN );

	printf("you can't stop me!\n");
	while( 1 )
	{
		sleep(1);
		printf("haha\n");
	}
	return 0;
}

