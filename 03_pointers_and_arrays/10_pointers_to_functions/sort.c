#include <stdio.h>
#include "sort.h"

#define MAXLINES 5000	// max #lines to be sorted

char *lineptr[MAXLINES];	// pointers to text lines

/*sort input lines*/
int main(int argc, char * argv[]) {
	int nlines;		// number of input lines read
	int numeric = 0;	// 1 if numeric sort

	if (argc > 1 && str_cmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		/* qsort(lineptr, 0, nlines-1); */
		qsort((void**) lineptr, 0, nlines-1,
				(int (*)(void*,void*)) (numeric ? num_cmp : str_cmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
