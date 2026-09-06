/* utmplib.h - header for utmplib.c
 *
 *      functions to buffer reads from the utmp file:
 *              utmp_open( filename )   - open file, return fd, -1 on error
 *              utmp_next( )            - return pointer to next struct, NULL on eof
 *              utmp_close( )           - close file
 */
#ifndef UTMPLIB_H
#define UTMPLIB_H

#include <utmp.h>

int             utmp_open( char *filename );
struct utmp    *utmp_next( void );
void            utmp_close( void );

#endif
