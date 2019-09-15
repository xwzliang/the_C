#include <stdio.h>
#include "sort.h"

#define MAXLINES 5000	// max #lines to be sorted

char *lineptr[MAXLINES];	// pointers to text lines

/*sort input lines*/
int sort() {
	int nlines;		// number of input lines read

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
