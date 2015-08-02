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

#include "dtoa.c"

void echo_dval(double dd, int mode, int ndigits)
{
	int sign, decpt;
	char *rve;
	char *s = dtoa(dd, mode, ndigits, &sign, &decpt, NULL);
	
	printf("%-25s: sign: %d, decpt: %d\n", s, sign, decpt);
	freedtoa(s);
}

void echo_dvals(const char *title, double dd)
{
	printf("\ntitle\n");
	echo_dval(dd, 0, 14);
	echo_dval(dd, 0, 17);
	echo_dval(dd, 2, 14);
	echo_dval(dd, 2, 17);
}

int main()
{
	echo_dvals("0.1234567890123456789 in C", 0.123);
	echo_dvals("6 / 3", 6.0 / 3.0);
}
