/*
	1. 메르센 수 M_p == 2^p - 1 이라고 정의하자.

	2. 수열 r_n(n >= 1)을 다음과 같이 정의하자.
		if(n == 1)
			r_1 == 4
		else
			r_(n-1)^2

	그러면 p가 3이상인 소수일 때,
	메르센 수가 소수일 필요충분조건은

	r_(p-1) === 0 (mod M_p) 이다.
	
	참고: https://librewiki.net/wiki/%EB%A4%BC%EC%B9%B4-%EB%A0%88%EB%A8%B8_%EC%86%8C%EC%88%98%ED%8C%90%EC%A0%95%EB%B2%95
	영문위키: https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test
	국문위키: https://ko.wikipedia.org/wiki/%EB%A4%BC%EC%B9%B4-%EB%A0%88%EB%A8%B8_%EC%86%8C%EC%88%98%ED%8C%90%EB%B3%84%EB%B2%95
*/

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdint.h>

typedef unsigned long long int ullt;

ullt LL_primality_test(ullt p) {
	ullt N = (1ULL << p) - 1; // 설정된 메르센 수
	ullt r = 4; // r의 기본값은 4이다.
	ullt i;

	assert(p >= 3);
	assert(p <= 64);
	if (p == 64) N = 0x1fffffffffffffff;

	for (i = 1; i < p - 1; ++i) {
		r = (r * r - 2) % N;
		printf("%lld: %lld\n", i, r);
	}

	return (!r);
}

int main() {
	clock_t time;
	time = clock();

	// 왜 소수가 아니라고 나오지?
	// 뭔가 문제가 있는 소스코드.
	const ullt p = 61; 

	if (LL_primality_test(p)) {
		printf("N is a prime number.\n");
	}
	else {
		printf("N is not a prime number.\n");
	}
	
	time = clock() - time;
	printf(" (%lf seconds)\n", time / 1000.0);
	return 0;
}