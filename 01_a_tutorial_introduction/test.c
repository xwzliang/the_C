#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "01_hello_world.h"

void test_hello_world(void) {
	int stdout_bk; 	// is fd for stdout backup
	stdout_bk = dup(fileno(stdout));

	int pipefd[2];
	pipe(pipefd);

	// What used to be stdout will now go to the pipe.
	dup2(pipefd[1], fileno(stdout));

	hello_world();

	fflush(stdout);		//flushall();
	write(pipefd[1], "", 9); 	// null-terminated string!
	close(pipefd[1]);

	dup2(stdout_bk, fileno(stdout));	//restore

	char buf[101];
	read(pipefd[0], buf, 100);

	TEST_ASSERT_EQUAL_STRING(buf, "hello, world\n");
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_hello_world);
	return UNITY_END();
}
