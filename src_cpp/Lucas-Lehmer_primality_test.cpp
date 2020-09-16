/*
	1. �޸��� �� M_p == 2^p - 1 �̶�� ��������.

	2. ���� r_n(n >= 1)�� ������ ���� ��������.
		if(n == 1)
			r_1 == 4
		else
			r_(n-1)^2

	�׷��� p�� 3�̻��� �Ҽ��� ��,
	�޸��� ���� �Ҽ��� �ʿ����������

	r_(p-1) === 0 (mod M_p) �̴�.
	
	����: https://librewiki.net/wiki/%EB%A4%BC%EC%B9%B4-%EB%A0%88%EB%A8%B8_%EC%86%8C%EC%88%98%ED%8C%90%EC%A0%95%EB%B2%95
	������Ű: https://en.wikipedia.org/wiki/Lucas%E2%80%93Lehmer_primality_test
	������Ű: https://ko.wikipedia.org/wiki/%EB%A4%BC%EC%B9%B4-%EB%A0%88%EB%A8%B8_%EC%86%8C%EC%88%98%ED%8C%90%EB%B3%84%EB%B2%95
*/

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdint.h>

typedef unsigned long long int ullt;

ullt LL_primality_test(ullt p) {
	ullt N = (1ULL << p) - 1; // ������ �޸��� ��
	ullt r = 4; // r�� �⺻���� 4�̴�.
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

	// �� �Ҽ��� �ƴ϶�� ������?
	// ���� ������ �ִ� �ҽ��ڵ�.
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