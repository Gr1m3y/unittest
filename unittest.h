// unittest.h
// Based on MinUnit
// http://www.jera.com/techinfo/jtns/jtn002.html
//
// @author Angus Hilts
//
// Simple unit test framework for C

#define SUCCESS() do { printf("[ OK ]\n"); \
	tests_passed++; } while (0)
#define FAIL() do { printf("[FAIL]\n"); \
	tests_failed++; } while (0)
#define ut_assert(test) do { printf("%-30s", __func__); \
	if(!(test)) { FAIL(); } \
	else { SUCCESS(); return 0 ; } } while (0)
#define ut_run(test) do { int result = test(); tests_run++; \
	if ( result ) return result; } while (0)

extern int tests_run;
extern int tests_passed;
extern int tests_failed;
