#include <stdio.h>
#include <string.h>
#include "../06_pointer_arrays_pointers_to_pointers/sort.h"

#define MAXLINE 1000

/* find: print lines that match pattern from 1st arg */
int main(int argc_count, char *argv[]) {
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	/* Notice that *++argv is a pointer to an argument string, so (*++argv)[0] is its first character. (An alternate valid form would be **++argv.) Because [] binds tighter than * and ++, the parentheses are necessary; without them the expression would be taken as *++(argv[0]). In fact, that is what we have used in the inner loop, where the task is to walk along a specific argument string. In the inner loop, the expression *++argv[0] increments the pointer argv[0]! */
	while (--argc_count > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc_count = 0;
					found = -1;
					break;
			}
	if (argc_count != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (get_line(line, MAXLINE) > 0) {
			lineno++;
			/* The standard library function strstr(s,t) returns a pointer to the first occurrence of the string t in the string s, or NULL if there is none. */
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				found++;
			}
		}
	return found;
}

