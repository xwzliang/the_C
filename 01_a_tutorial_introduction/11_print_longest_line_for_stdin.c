#include <stdio.h>

#define MAXLINE 1000	// maximum input line length

/*if these two are declared after print_longest_line_for_stdin, gcc will give warning*/
/*another solution is put print_longest_line_for_stdin function at last*/
int getline_for_me(char s[], int lim);
void copy_for_me(char to[], char from[]);

int print_longest_line_for_stdin() {
	int len;	// current line length
	int max;	// maximum length seen so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];	// longest line saved here

	max = 0;
	while ((len = getline_for_me(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy_for_me(longest, line);
		}
	if (max > 0)	// there was a line
		printf("%s", longest);
	return 0;
}

/*getline_for_me: read a line into s, return length*/
int getline_for_me(char s[], int lim) {
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	/*getline puts the character '\0' (the null character, whose value is zero) at the end of the array it is creating, to mark the end of the string of characters.*/
	s[i] = '\0';
	return i;
}

/*copy: copy 'from' into 'to'; assume to is big enough*/
void copy_for_me(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
