/*
	�޸��� �� Mersenne number,
	: M(n)�� 2^n - 1�� ���¸� ������ ���� ���Ѵ�.
	�޸��� �Ҽ��� �޸��� ���� �� �Ҽ��� ����Ų��.
*/

#include <stdio.h>
#include <time.h>

typedef long long int llt;

int main() {
	int triple = 0;
	clock_t time;

	const llt N = (1LL << 61) - 1;
	// ���� �� �ٸ� ǥ��
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