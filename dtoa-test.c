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
	
	printf("%-80s -- sign: %d, decpt: %d\n", s, sign, decpt);
	freedtoa(s);
}

void echo_dvals(const char *title, double dd)
{
	printf("\n%s\n", title);
	echo_dval(dd, 0, 0);
	echo_dval(dd, 2, 17);
	echo_dval(dd, 2, 100);
}

int main()
{
	echo_dvals("0.5 in C", 0.5);
	echo_dvals("0.00001234567890123456789 in C", 0.00001234567890123456789);
	echo_dvals("-12323.23422134233 in C", -12323.23422134233);
	echo_dvals("123232394239048932930489349234903422134233", 123232394239048932930489349234903422134233.1);
	echo_dvals("6 / 3", 6.0 / 3.0);
	echo_dvals("0.908234 / 0.293023323234", 0.908234 / 0.293023323234);
}
