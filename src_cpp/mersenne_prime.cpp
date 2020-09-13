/*
	메르센 수 Mersenne number,
	: M(n)은 2^n - 1의 형태를 가지는 수를 말한다.
	메르센 소수는 메르센 수들 중 소수를 가리킨다.
*/

#include <stdio.h>
#include <time.h>

typedef long long int llt;

int main() {
	int triple = 0;
	clock_t time;

	const llt N = (1LL << 61) - 1;
	// 같은 수 다른 표현
	// const llt N = 0x1FFFFFFFFFFFFFFF;

	printf("N = %lld\n", N);

	time = clock();

	if (N & 1 && (N == 3 || N % 3)) {
		llt i;
		for (i = 3; i * i <= N; i += 2, ++triple) {
			if (triple == 0) {
				triple = -3;
				continue;
			}
			if (N % i == 0) {
				printf("N is not a prime number. It can be divided by %lld.\n", i);
				break;
			}
		}
		if (i * i > N)
			printf("N is a prime number.\n");
	}
	else
		printf("N is not a prime number.\n");

	time = clock() - time;

	printf(" (%lf seconds)\n", time / 1000.0);

	return 0;
}