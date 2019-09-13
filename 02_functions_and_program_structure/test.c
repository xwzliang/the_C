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

void test_calculator() {
	stdout_capture_start();
	calculator();
	stdout_capture_finish();

	char* expect = 
		"\t35\n"
		"\t-0.8\n"
		"\t100\n"
		"\t2.5\n"
		"error: zero divisor\n\t1\n"
		"\t3.3333333\n"
		;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_calculator);
	return UNITY_END();
}
