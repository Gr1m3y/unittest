// unittest.h
// Based on MinUnit
// http://www.jera.com/techinfo/jtns/jtn002.html
//
// @author Angus Hilts
//
// Simple unit test framework for C

// Colours
#define RED "\x1B[31m"		// Red
#define GRN "\x1B[32m"		// Green
#define RST "\x1B[0m"		// Reset colours



// Success message
#define SUCCESS() do { printf("[ " GRN "OK" RST " ]\n"); \
	tests_passed++; } while (0)
// Fail message
#define FAIL() do { printf("[" RED "FAIL" RST "]\n"); \
	tests_failed++; } while (0)

#ifndef VERBOSE		// Only presents information for each test
// assert function for test
#define ut_assert(test) do { printf("%-30s", __func__); \
	if(!(test)) { return 1; } \
	else { return 0 ; } } while (0)
// test runner
#define ut_run(test) do { int result = test(); tests_run++; \
	if ( result ) { FAIL(); } \
	else { SUCCESS(); } } while (0)


// NOTE: For now, the verbose version does not work. Need to think about anice
// way to prevent returning from ut_assert so that all asserts can be run

#else				// Version that presents information for all
					// asserts that are made

#define assert_SUCCESS() do { printf("[ " GRN "OK" RST " ]\n"); \
	asserts_passed++; } while(0)
#define assert_FAIL() do { printf("[" RED "FAIL" RST "]\n"); 	\
	asserts_failed++; } while(0)


#define ut_assert(test) do { printf("\tLine: %-15d", __LINE__); 	\
	if (!(test)) { assert_FAIL() ; } 						\
	else { assert_SUCCESS() ; } } while (0)

#define ut_run(test) do { printf( #test "...\n" );	\
	int current = asserts_failed;					\
	test(); tests_run++;							\
	printf("%-35s", "Result:");						\
	if( asserts_failed-current ) { FAIL(); }		\
	else { SUCCESS(); } } while(0)


#endif

// Summary data
extern int tests_run;
extern int tests_passed;
extern int tests_failed;
extern int asserts_failed;
extern int asserts_passed;
