#include <stdio.h>

void asterisco(int s) {
	for (int i = 0; i < s; i++)
		printf(" ");

	printf("*\n");
}

void freccia(int s, int a) {
	if (a == 1)
		asterisco(s);
	else {
		asterisco(s);
		freccia(s + 1, a - 2);
		asterisco(s);
	}
}
