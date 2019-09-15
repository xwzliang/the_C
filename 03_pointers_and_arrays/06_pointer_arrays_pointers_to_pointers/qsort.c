#include <string.h>

/*qsort: quick sort, sort v[left]...v[right] into increasing order*/
void qsort(char *v[], int left, int right) {
	int i, last;
	void swap_char(char *v[], int i, int j);

	if (left >= right)	// do nothing if array contains fewer than two elements
		return;
	swap_char(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap_char(v, ++last, i);
	swap_char(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/*swap: interchange v[i] and v[j]*/
void swap_char(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
