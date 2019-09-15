/*str_cpy: copy t to s; array subscript version*/
/*void str_cpy(char *s, char *t) {*/
	/*int i;*/
	
	/*i = 0;*/
	/*while ((s[i] = t[i]) != '\0')*/
		/*i++;*/
/*}*/

/*pointer version*/
/*void str_cpy(char *s, char *t) {*/
	/*int i;*/

	/*i = 0;*/
	/*while ((*s = *t) != '\0') {*/
		/*s++;*/
		/*t++;*/
	/*}*/
/*}*/

/*pointer version 2*/
/*void str_cpy(char *s, char *t) {*/
	/*while ((*s++ = *t++) != '\0')*/
		/*;*/
/*}*/

/*pointer version 3*/
void str_cpy(char *s, char *t) {
	// '\0' is zero, so the equal test is redundant
	while (*s++ = *t++)
		;
}
