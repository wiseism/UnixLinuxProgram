/* write0.c
 *
 *	purpose: send messages to another terminal
 *	 method: open the other terminal for output then
 *	 	 copy from stdin to that terminal
 *	  shows: a terminal is just a file supporting regular i/o
 *	  usage: write0 ttyname
 */
#include <fcntl.h>       /* 新版 GCC 隐式声明报错 */
#include <stdio.h>       /* 新版 GCC 隐式声明报错 */
#include <string.h>       /* 新版 GCC 隐式声明报错 */
#include <unistd.h>       /* 新版 GCC 隐式声明报错 */

#include	<stdio.h>
#include	<fcntl.h>
#include <stdlib.h>       /* 需要 exit(); 新版 GCC 隐式声明报错 */

int main( int ac, char *av[] )
{
	int	fd;
	char	buf[BUFSIZ];

	/* check args */
	if ( ac != 2 ){
		fprintf(stderr,"usage: write0 ttyname\n");
		exit(1);
	}

	/* open devices */
	fd = open( av[1], O_WRONLY );
	if ( fd == -1 ){
		perror(av[1]); exit(1);
	}

	/* loop until EOF on input */
	while( fgets(buf, BUFSIZ, stdin) != NULL )
		if ( write(fd, buf, strlen(buf)) == -1 )
			break;
	close( fd );
	return 0;
}
