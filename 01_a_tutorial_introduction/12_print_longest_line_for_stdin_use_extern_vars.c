#include <stdio.h>

#define MAXLINE 1000	// maximum input line length

/*An external variable must be defined, exactly once, outside of any function; this sets aside storage for it. The variable must also be declared in each function that wants to access it; this states the type of the variable. The declaration may be an explicit extern statement or may be implicit from context.*/
int max;	// maximum length seen so far
char line[MAXLINE];		// current input line
char longest[MAXLINE];	// longest line saved here

int getline_for_me_use_extern_vars();
void copy_for_me_use_extern_vars();

int print_longest_line_for_stdin_use_extern_vars() {
	int len;	// current line length
	// if extern vars are defined in the same file, then declarations can be omitted
	// The usual practice is to collect extern definations in header file
	/*extern int max;*/
	/*extern char longest[];*/

	max = 0;
	while ((len = getline_for_me_use_extern_vars()) > 0)
		if (len > max) {
			max = len;
			copy_for_me_use_extern_vars();
		}
	if (max > 0)	// there was a line
		printf("%s", longest);
	return 0;
}

/*getline_for_me_use_extern_vars: specialized version*/
int getline_for_me_use_extern_vars() {
	int c, i;
	/*extern char line[];*/

	for (i=0; i < MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/*copy_for_me_use_extern_vars specialized version*/
void copy_for_me_use_extern_vars() {
	int i;
	/*extern char line[], longest[];*/

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}


/*There is a tendency to make everything in sight an extern variable because it appears to simplify communications - argument lists are short and variables are always there when you want them. But external variables are always there even when you don't want them. Relying too heavily on external variables is fraught with peril since it leads to programs whose data connections are not all obvious - variables can be changed in unexpected and even inadvertent ways, and the program is hard to modify. The second version of the longest-line program is inferior to the first, partly for these reasons, and partly because it destroys the generality of two useful functions by writing into them the names of the variables they manipulate.*/
