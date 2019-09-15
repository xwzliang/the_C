/*str_cmp: return <0 if s<t, 0 if s==t, >0 if s>t*/

/*array subscript version*/
/*int str_cmp(char *s, char *t) {*/
	/*int i;*/

	/*for (i = 0; s[i] == t[i]; i++)*/
		/*if (s[i] == '\0')*/
			/*return 0;*/
	/*return s[i] - t[i];*/
/*}*/

/*pointer version*/
int str_cmp(char *s, char *t) {
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
