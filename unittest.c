// unittest.c
// Based on MinUnit
// http://www.jera.com/techinfo/jtns/jtn002.html
//
// @author Angus Hilts
//
// Simple unit test framework for C

#include <stdio.h>
#include "unittest.h"

int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

int square(int x) {
	return x*x;
}

// WRITE TESTS HERE

int test01() {
	ut_assert( square(5) == 25 );
	return 0;
}

int test02() {
	ut_assert( square(0) == 1 );
	return 0;
}

int test03() {
	ut_assert( square(1) == 1 );
	return 0;
}

int main(int argc, char **argv) {
	
	printf("Starting test driver...\n\n");

	// RUN TESTS HERE
	ut_run( test01 );
	ut_run( test02 );
	ut_run( test03 );

	printf("\n*******RESULTS*******\n");
	printf("Tests run: %10d\n", tests_run);
	printf("Tests passed: %7d\n", tests_passed);
	printf("%3.1f%% of tests passed.\n\n", 100*(double)tests_passed/tests_run);

	return tests_failed;
}
