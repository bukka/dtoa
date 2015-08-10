/**
 * Simple dtoa test
 */
#include <sys/types.h>
#include <stdio.h>

#ifdef WORDS_BIGENDIAN
#define IEEE_MC68k 1
#else
#define IEEE_8087 1
#endif

#define DEBUG 1

#define Long int

#include "dtoa.c"

void echo_dval(double dd, int mode, int ndigits)
{
	int sign, decpt;
	char *s = dtoa(dd, mode, ndigits, &decpt, &sign, NULL);
	
	printf(" %d | %2d | %-55s | %4d | %5d\n", mode, ndigits, s, sign, decpt);
	freedtoa(s);
}

void echo_dvals(const char *title, double dd)
{
	printf("\n m |    | %-55s | sign | decpt\n", title);
	echo_dval(dd, 0, 0);
	echo_dval(dd, 2, 17);
	echo_dval(dd, 2, 50);
}

#define ECHO_CDV(_val) echo_dvals(#_val" in C", _val)
#define ECHO_DIV(_v1, _v2) echo_dvals(#_v1" / "#_v2, _v1 / _v2)

int main()
{
#ifdef DBL_DIG
	printf("DBL_DIG: %d\n", DBL_DIG);
#else
	puts("DBL_DIG is not defined\n");
#endif
	/* echo C double values */
	ECHO_CDV(0.5);
	ECHO_CDV(0.9999);
	ECHO_CDV(0.9999999999999999);
	ECHO_CDV(0.00001234567890123456789);
	ECHO_CDV(-12323.23422134233);
	ECHO_CDV(123232394239048932930489349234903422134233.1);

	/* echo divisions */
	ECHO_DIV(6.0, 3.0);
	ECHO_DIV(0.908234, 0.293023323234);
}
