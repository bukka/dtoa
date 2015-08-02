/**
 * Simple dtoa test
 */
#include <sys/types.h>
#include <stdio.h>

#include "dtoa.c"

void echo_dval(double dd, int mode, int ndigits)
{
	int sign, decpt;
	char *s = dtoa(dd, mode, ndigits, sign, decpt, NULL);
	
	printf("%-25s: sign: %d, decpt: %d\n", s, sign, decpt);
	FREE(s);
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
	echo_dvals("0.1234567890123456789 in C", 0.1234567890123456789);
	echo_dvals("6 / 3", 6.0 / 3.0);
}
