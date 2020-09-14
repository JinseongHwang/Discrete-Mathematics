/*
	�޸��� �� Mersenne number,
	: M(n)�� 2^n - 1�� ���¸� ������ ���� ���Ѵ�.
	�޸��� �Ҽ��� �޸��� ���� �� �Ҽ��� ����Ų��.

	����: https://gunhoflash.tistory.com/36
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

	// �˾Ƶ־� �ϴ� ���:
	// ������ �� N�� ������ ��, N �ڽ��� ������ ��� �� ���� ū ���� sqrt(N)���� �۰ų� ����.
	// => ���� ��� �Ǻ��� �� ��, sqrt(N)������ �����ϸ� �ȴ�.

	// N & 1 => N�� ¦���� 0 ��ȯ, Ȧ���� 1 ��ȯ
	// N == 3 || N % 3 => N�� 3�̰ų� 3�� ����� �ƴϰų�
	// ����, 3�� ������ 2�� ����� 3�� ����� �ɷ�����.
	if (N & 1 && (N == 3 || N % 3)) {
		llt i;
		// N���� ���� �� �ִ� ���� ���� ���� 3���� �����Ұǵ�,
		// i�� sqrt(N)������ Ȯ���ص� ����ϴ�.
		// ¦���� �������� �ƴϱ� ������ 3���� i�� 2�� ������Ű�� Ȯ���ϰ�,
		// ���ÿ� 3�� �����° ���������� �Ͼ�� ��, 3�� ������� �ڸ��ϹǷ� continue�� ���ش�.
		for (i = 3; i * i <= N; i += 2, ++triple) {
			if (triple == 0) {
				triple = -3;
				continue;
			}
			if (N % i == 0) { // ���� ������ ������ �غ���.
				printf("N is not a prime number. It can be divided by %lld.\n", i);
				break;
			}
		}
		// sqrt(N)���� ũ�鼭 2�� 3�� ����� �ƴ϶�� �Ҽ��̴�.
		if (i * i > N)
			printf("N is a prime number.\n");
	}
	else // ��κ��� ��쿡, 2 �Ǵ� 3�� ����� ���
		printf("N is not a prime number.\n");

	time = clock() - time;

	printf(" (%lf seconds)\n", time / 1000.0);

	return 0;
}