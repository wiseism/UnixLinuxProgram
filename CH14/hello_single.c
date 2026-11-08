/* hello_single.c - a single threaded hello world program */
#include <stdio.h>       /* 新版 GCC 隐式声明报错 */

#include  <stdio.h>
#include <zconf.h>
#include <unistd.h>       /* 需要 sleep(); 新版 GCC 隐式声明报错 */

#define	NUM	5

void main()
{
	void	print_msg(char *);

	print_msg("hello");
	print_msg("world\n");
}
void print_msg(char *m)
{
	int i;
	for(i=0 ; i<NUM ; i++){
		printf("%s", m);
		fflush(stdout);
		sleep(1);
	}
}
