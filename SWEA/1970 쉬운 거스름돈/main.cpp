#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int coin[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
int used[8] = { 0 };

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		if (test_case > 1) 
		{ 
			for (int i = 0; i < 8; i++) {
				used[i] = 0;
			} 
		}

		for (int i = 0; i < 8; i++) {
			while (N >= coin[i]) {
				N -= coin[i];
				used[i]++;
			}
		}

		printf("#%d\n", test_case);
		for (int i = 0; i < 8; i++) {
			printf("%d ", used[i]);
		}
		printf("\n");
	}
	return 0;
}