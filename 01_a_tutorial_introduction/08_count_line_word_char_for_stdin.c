#include <stdio.h>

#define IN 1	// inside a word
#define OUT 0	// outside a word

void count_line_word_char_for_stdin() {
	int c, nl, nw, nc, state;	// nc for characters, nw for words, nl for lines

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if ( c == '\n' )
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
