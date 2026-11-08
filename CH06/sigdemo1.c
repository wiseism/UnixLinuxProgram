/* sigdemo1.c - shows how a signal handler works.
 *            - run this and press Ctrl-C a few times
 */
#include <unistd.h>       /* 新版 GCC 隐式声明报错 */

#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <zconf.h>

int main()
{
	void	f(int);			/* declare the handler	*/
	int	i;

	signal( SIGINT, f );		/* install the handler SIGINT 终止进程	*/
	for(i=0; i<5; i++ ){		/* do something else	*/
		printf("hello\n");
		sleep(2);
	}
	return 0;
}

void f(int signum)			/* this function is called */
{
	printf("OUCH!\n");
}
