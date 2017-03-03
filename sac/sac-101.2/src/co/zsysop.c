/*
CDOC
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 
 *** Function:	zsysop_(comstr,pnumc,perr,dummylen)		D. Trimmer
 
 *** Purpose:	Executes a system command
 
 *** Inputs:	comstr	A character string containing a system command and
			input parameters.  The first token is the command,
			and the following blank delimited tokens are the
			run string parameters.
		pnumc	A pointer to a long containing the number of characters
			in comstr.
		perr	A pointer to a long which will be loaded with error
			flag
			0	successful
			1111	error
		dummylen	a long containing size of comstr array--
				generated by FORTRAN 77
 
 *** Returns:	none
 
 *** Notes:	This function is to be called by a FORTRAN routine.  The
		'_' is appended to the name for compatibility with FORTRAN.
 
 *** History:	07/25/84	Under development--D. Trimmer	
		07/25/84	Tested--D. Trimmer
		10/01/84	Convert command string to lower case--D. Trimmer
                08/01/89        Deleted forced conversion to lower case--J. Tull
 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
CEND
*/
 
#include <stdio.h>
#include <errno.h>
 

zsysop(comstr,dummylen,pnumc,perr)
char *comstr;	/* command string */
long dummylen;	/* generated by FORTRAN 77--unused */
long *pnumc;	/* number of characters in comstr */
long *perr;	/* error flag returned here */
 
{
	int i;	/* index */
 
	comstr[(int) *pnumc] = '\0';
 
	if (system(comstr) != -1)
		return;
 
	*perr = 1111;
	return;
}
 