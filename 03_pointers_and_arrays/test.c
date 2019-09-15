#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "test.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[1001];

void stdout_capture_start() {
	fflush(stdout);		//flushall();
	stdout_bk = dup(fileno(stdout));

	pipe(pipefd);

	// What used to be stdout will now go to the pipe.
	dup2(pipefd[1], fileno(stdout));
}

void stdout_capture_finish() {
	fflush(stdout);		//flushall();
	write(pipefd[1], "", 9); 	// null-terminated string!
	close(pipefd[1]);

	dup2(stdout_bk, fileno(stdout));	//restore

	read(pipefd[0], buf, 1000);
}

void test_swap() {
	int x = 32;
	int y = 28;
	swap(&x, &y);
	TEST_ASSERT_EQUAL_INT(28, x);
	TEST_ASSERT_EQUAL_INT(32, y);
}

void test_getint() {
	int x;
	int y;
	getint(&x);
	getint(&y);
	TEST_ASSERT_EQUAL_INT(343, x);
	TEST_ASSERT_EQUAL_INT(-689, y);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_swap);
	RUN_TEST(test_getint);
	return UNITY_END();
}
