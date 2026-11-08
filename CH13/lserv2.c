/****************************************************************************
 * lsrv2.c  
 * License server server program version 2 - features ticket recycling
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/errno.h>
#include <unistd.h>       /* alarm */
int setup();	/* 前向声明 */
void handle_request(char *, struct sockaddr_in *, socklen_t);	/* 前向声明 */

void narrate(char *, char *, struct sockaddr_in *);	/* 前向声明 */

#define	MSGLEN		128

#define RECLAIM_INTERVAL 5		/* reclaim every 60 seconds */
int main(int ac, char *av[])
{
	struct sockaddr_in client_addr;	/* 与 funcs2 统一 */
	socklen_t addrlen;
	char      buf[MSGLEN];
	int	  ret, sock;
	void	  ticket_reclaim();	/* version 2 addition */
	unsigned  time_left;

	sock = setup();
	signal(SIGALRM, ticket_reclaim); /* run ticket reclaimer */
	alarm(RECLAIM_INTERVAL);	 /* after this delay     */

	while(1) {
		addrlen = sizeof(client_addr);
		ret = recvfrom(sock,buf,MSGLEN,0,
				(struct sockaddr *)&client_addr,&addrlen);
		if ( ret != -1 ){
			buf[ret] = '\0';
			narrate("GOT:", buf, &client_addr);
			time_left = alarm(0);
			handle_request(buf,&client_addr,addrlen);
			alarm(time_left);
		}
		else if ( errno != EINTR )
			perror("recvfrom");
	}
}
