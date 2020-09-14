/*
	메르센 수 Mersenne number,
	: M(n)은 2^n - 1의 형태를 가지는 수를 말한다.
	메르센 소수는 메르센 수들 중 소수를 가리킨다.

	참고: https://gunhoflash.tistory.com/36
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

	// 알아둬야 하는 사실:
	// 임의의 수 N이 존재할 때, N 자신을 제외한 약수 중 가장 큰 값은 sqrt(N)보다 작거나 같다.
	// => 따라서 약수 판별을 할 때, sqrt(N)까지만 진행하면 된다.

	// N & 1 => N이 짝수면 0 반환, 홀수면 1 반환
	// N == 3 || N % 3 => N이 3이거나 3의 배수가 아니거나
	// 따라서, 3을 제외한 2의 배수와 3의 배수를 걸러낸다.
	if (N & 1 && (N == 3 || N % 3)) {
		llt i;
		// N으로 들어올 수 있는 가장 작은 수인 3부터 시작할건데,
		// i는 sqrt(N)까지만 확인해도 충분하다.
		// 짝수는 고려대상이 아니기 때문에 3부터 i를 2씩 증가시키며 확인하고,
		// 동시에 3의 배수번째 증가연산이 일어났을 때, 3의 배수임이 자명하므로 continue를 해준다.
		for (i = 3; i * i <= N; i += 2, ++triple) {
			if (triple == 0) {
				triple = -3;
				continue;
			}
			if (N % i == 0) { // 직접 나머지 연산을 해본다.
				printf("N is not a prime number. It can be divided by %lld.\n", i);
				break;
			}
		}
		// sqrt(N)보다 크면서 2와 3의 배수가 아니라면 소수이다.
		if (i * i > N)
			printf("N is a prime number.\n");
	}
	else // 대부분의 경우에, 2 또는 3의 배수인 경우
		printf("N is not a prime number.\n");

	time = clock() - time;

	printf(" (%lf seconds)\n", time / 1000.0);

	return 0;
}