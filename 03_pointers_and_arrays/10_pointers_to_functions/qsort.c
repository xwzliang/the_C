#include <string.h>

/*qsort: quick sort, sort v[left]...v[right] into increasing order*/
/* void qsort(char *v[], int left, int right) { */
void qsort(void *v[], int left, int right, int (*comp) (void *, void *)) {
/* int (*comp)(void *, void *) which says that comp is a pointer to a function that has two void * arguments and returns an int. */
/* As indicated by the function prototype, qsort expects an array of pointers, two integers, and a function with two pointer arguments. The generic pointer type void * is used for the pointer arguments. Any pointer can be cast to void * and back again without loss of information, so we can call qsort by casting arguments to void *. The elaborate cast of the function argument casts the arguments of the comparison function. These will generally have no effect on actual representation, but assure the compiler that all is well. */
	int i, last;
	/* void swap_char(char *v[], int i, int j); */
	void swap_all(void *v[], int i, int j);

	if (left >= right)	// do nothing if array contains fewer than two elements
		return;
	swap_all(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		/* if (strcmp(v[i], v[left]) < 0) */
		if ((*comp)(v[i], v[left]) < 0)
		/* The use of comp in the line if ((*comp)(v[i], v[left]) < 0) is consistent with the declaration: comp is a pointer to a function, *comp is the function, and (*comp)(v[i], v[left]) is the call to it. The parentheses are needed so the components are correctly associated; without them, int *comp(void *, void *)    [> WRONG <] says that comp is a function returning a pointer to an int, which is very different. */
			swap_all(v, ++last, i);
	swap_all(v, left, last);
	/* qsort(v, left, last-1); */
	/* qsort(v, last+1, right); */
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

/*swap: interchange v[i] and v[j]*/
/* void swap_char(char *v[], int i, int j) { */
void swap_all(void *v[], int i, int j) {
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
