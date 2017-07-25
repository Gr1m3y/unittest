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
int asserts_passed = 0;
int asserts_failed = 0;

int square(int x) {
	return x*x;
}

// WRITE TESTS HERE
/*******************************************************************/



/*******************************************************************/

int main(int argc, char **argv) {
	
	printf("Starting test driver...\n\n");

	/*******************************************************************/
	// RUN TESTS HERE
	


	/*******************************************************************/
	printf("\n**********RESULTS**********\n");
	
	if ( tests_run ) {
		printf("Tests run: %16d\n", tests_run);
		printf("Tests passed: %13d\n", tests_passed);
		printf("Tests failed: %13d\n", tests_failed);
		printf("%3.1f%% of tests passed.\n\n", 100*(double)tests_passed/tests_run);
	} else {
		printf("No tests were run.\n\n");
	}

	return tests_failed;
}
