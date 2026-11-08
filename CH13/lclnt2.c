/****************************************************************************
 * lclnt2.c
 * License server client version 2
 *  link with lclnt_funcs2.o dgram.o
 */
#include <unistd.h>       /* 新版 GCC 隐式声明报错 */

#include <stdio.h>
#include <stdlib.h>       /* 需要 exit(); 新版 GCC 隐式声明报错 */
void setup();	/* 前向声明 */
int get_ticket();	/* 前向声明 */
void do_regular_work();	/* 前向声明 */
int validate_ticket();	/* 前向声明 */
void release_ticket();	/* 前向声明 */
void shut_down();	/* 前向声明 */

int main(int ac, char *av[])
{
	setup();
	if (get_ticket() != 0 )
		exit(0);	

	do_regular_work();

	release_ticket();
	shut_down();

	return 0;
}
*
 * do_regular_work  the main work of the application goes here
 */
void do_regular_work()
{
	printf("SuperSleep version 1.0 Running - Licensed Software\n");
	sleep(15);	/* our patented sleep algorithm */

	if ( validate_ticket() != 0 ){
		printf("Server errors. Please Try later.\n");
		return;
	}
	sleep(15);
}

