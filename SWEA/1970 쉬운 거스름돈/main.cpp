#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	int coin[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, cnt;
		cin >> N;

		printf("#%d\n", test_case);

		for (int i = 0; i < 8; i++) {
			cnt = N / coin[i];
			N -= cnt * coin[i];
			printf("%d ", cnt);
		}
		printf("\n");
	}
	return 0;
}