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
// assert function for test
#define ut_assert(test) do { printf("%-30s", __func__); \
	if(!(test)) { FAIL(); } \
	else { SUCCESS(); return 0 ; } } while (0)
// test runner
#define ut_run(test) do { int result = test(); tests_run++; \
	if ( result ) return result; } while (0)

// Summary data
extern int tests_run;
extern int tests_passed;
extern int tests_failed;
