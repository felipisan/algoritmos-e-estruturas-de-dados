#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int mdc(int a, int b) {
	while(b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int mmc(int a, int b) {
	return (a * b) / mdc(a, b);
}