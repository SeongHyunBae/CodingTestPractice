#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	int cnt[201];

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 1; i < 201; i++) {
			cnt[i] = 0;
		}

		int N;
		cin >> N;

		int max_cnt = 0;

		for (int i = 0; i < N; i++) {
			int from, to;
			cin >> from >> to;

			if (from > to) {
				from ^= to;
				to ^= from;
				from ^= to;
			}
			
			for (int i = (from + 1) / 2; i <= (to + 1) / 2; i++) {
				cnt[i]++;
				if (max_cnt < cnt[i]) max_cnt = cnt[i];
			}

		}
		printf("#%d %d\n", test_case, max_cnt);
	}

	return 0;
}