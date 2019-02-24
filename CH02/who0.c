#include <stdio.h>
#include <fcntl.h>
#include <utmp.h>
#include <stdlib.h>
#include <zconf.h>

/*
 *	who version 0
 *		main outline but no substance
 */


/**
 * who1bot.c 不知道如何引入show_info函数
 *
 */
#include <stdio.h>

show_info( struct utmp *utbufp )
{
        printf("%-8.8s", utbufp->ut_name);	/* the logname	*/
        printf(" ");				/* a space	*/
        printf("%-8.8s", utbufp->ut_line);	/* the tty	*/
        printf(" ");				/* a space	*/
        printf("%10ld", utbufp->ut_time);	/* login time	*/
        printf(" ");				/* a space	*/
#ifdef	SHOWHOST
        printf("(%s)", utbufp->ut_host);	/* the host	*/
#endif
        printf("\n");				/* newline	*/
}

int main()
{
        int         fd;                 /* for file des of utmp */
        struct utmp current_record;     /* hold info from file */
        int         reclen = sizeof(struct utmp);

        fd = open(UTMP_FILE, O_RDONLY);
        if ( fd == -1 ){
                perror( "who0" );       /* report a system error */
                exit(1);                /* and get out now       */
        }

        while ( read(fd, &current_record, reclen) == reclen )
                show_info( &current_record );

        close (fd);
        return 0;
}
