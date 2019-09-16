#include <stdio.h>
#include <string.h>
#include "sort.h"

#define MAXLEN 1000		// max length of any input line

/*readlines: read input lines*/
int readlines(char *lineptr[], int maxlines) {	// lineptr is an array of pointers
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';		// delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/*writelines: write output lines*/
/*void writelines(char *lineptr[], int nlines) {*/
	/*int i;*/

	/*for (i = 0; i < nlines; i++)*/
		/*printf("%s\n", lineptr[i]);*/
/*}*/

/*writelines: write output lines, pointer version*/
void writelines(char *lineptr[], int nlines) {
	/*for ( ; nlines > 0; lineptr++, nlines--)*/
		/*printf("%s\n", *lineptr);*/
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
