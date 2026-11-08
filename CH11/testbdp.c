/*
 * testbpd.c  - test bidirectional pipes
 */
#include <stdio.h>       /* 新版 GCC 隐式声明报错 */
#include <stdlib.h>       /* 新版 GCC 隐式声明报错 */
#include <unistd.h>       /* 新版 GCC 隐式声明报错 */

int main()
{
	int	p[2];

	if ( pipe(p) == -1 ) exit(1);
	if ( write(p[0], "hello", 5) == -1 )
		perror("write into pipe[0] failed");
	else
		printf("write into pipe[0] worked\n");
}
