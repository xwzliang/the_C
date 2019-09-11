#include <stdio.h>

void copy_stdin_to_stdout() {
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);
}
