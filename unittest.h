// unittest.h
// Based on MinUnit
// http://www.jera.com/techinfo/jtns/jtn002.html
//
// @author Angus Hilts
//
// Simple unit test framework for C


#define ut_assert(test) do { if(!(test)) { FAIL(); return 1; } while (0)
#define ut_run(test) do { int result = test(); tests_run++; \
	if ( result ) return result; } while (0)

extern int tests_run;
