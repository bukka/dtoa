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


char *echo_gcvt(int ndigit, char dec_point, char exponent, char *buf,
				char *digits, int sign, int decpt)
{
	char *dst, *src;
	int i;

	if (decpt == 9999) {
		/*
		 * Infinity or NaN, convert to inf or nan with sign.
		 * We assume the buffer is at least ndigit long.
		 */
		i = 0;
		if (sign && *digits == 'I') {
			buf[i++] = '-';
		}
		strncpy(&buf[i], *digits == 'I' ? "INF" : "NAN", 4);
		return (buf);
	}

	dst = buf;
	if (sign) {
		*dst++ = '-';
	}

	if ((decpt >= 0 && decpt > ndigit) || decpt < -3) { /* use E-style */
		/* exponential format (e.g. 1.2345e+13) */
		if (--decpt < 0) {
			sign = 1;
			decpt = -decpt;
		} else {
			sign = 0;
		}
		src = digits;
		*dst++ = *src++;
		*dst++ = dec_point;
		if (*src == '\0') {
			*dst++ = '0';
		} else {
			do {
				*dst++ = *src++;
			} while (*src != '\0');
		}
		*dst++ = exponent;
		if (sign) {
			*dst++ = '-';
		} else {
			*dst++ = '+';
		}
		if (decpt < 10) {
			*dst++ = '0' + decpt;
			*dst = '\0';
		} else {
			/* XXX - optimize */
			for (sign = decpt, i = 0; (sign /= 10) != 0; i++)
				continue;
			dst[i + 1] = '\0';
			while (decpt != 0) {
				dst[i--] = '0' + decpt % 10;
				decpt /= 10;
			}
		}
	} else if (decpt < 0) {
		/* standard format 0. */
		*dst++ = '0';   /* zero before decimal point */
		*dst++ = dec_point;
		do {
			*dst++ = '0';
		} while (++decpt < 0);
		src = digits;
		while (*src != '\0') {
			*dst++ = *src++;
		}
		*dst = '\0';
	} else {
		/* standard format */
		for (i = 0, src = digits; i < decpt; i++) {
			if (*src != '\0') {
				*dst++ = *src++;
			} else {
				*dst++ = '0';
			}
		}
		if (*src != '\0') {
			if (src == digits) {
				*dst++ = '0';   /* zero before decimal point */
			}
			*dst++ = dec_point;
			for (i = decpt; digits[i] != '\0'; i++) {
                *dst++ = digits[i];
            }
        }
        *dst = '\0';
    }
    return (buf);
}

void echo_dval(double dd, int mode, int ndigits)
{
	int sign, decpt;
	char buf[2048];
	char *s = dtoa(dd, mode, ndigits, &decpt, &sign, NULL);
	
	printf(" %d | %2d | %-55s | %4d | %5d | %s\n",
		   mode, ndigits, s, sign, decpt,
		   echo_gcvt(ndigits, '.', 'e', &buf[0], s, sign, decpt));
	freedtoa(s);
}

void echo_dvals(const char *title, double dd)
{
	printf("\n m |    | %-55s | sign | decpt | gcvt\n", title);
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
