#include "pch.h"
#include<iostream>
#include<string.h>

using namespace std;

#define DIV 1000000007
#define MAX 10000

long long dp[MAX][16]; // A, B, C, D 경우의 수 2^4 -1 = 15(모두 없는 경우 제외)


int main(int argc, char** argv)
{
	int test_case;
	int T;

	FILE *stream;
	freopen_s(&stream, "sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));

		char managers[MAX];
		int day = 0;
		cin >> managers;	

		while (managers[day]) {
			int manager = 1 << managers[day] - 'A';

			for (int i = 1; i < 16; i++) {
				if (day == 0) { // 1일차
					// i번째 경우에 관리자와 A가 포함되면
					if ( (i & manager) != 0 && (i & 1) != 0 ) {
						dp[day][i] = 1;
					}
				}
				else { // 2일차 ~
					// 전날까지의 경우의 수가 0이 아니면
					if (dp[day - 1][i] != 0) {
						for (int j = 1; j < 16; j++) {
							// 전날 나온 사람이 오늘도 나오고 (i & j != 0)
							// 오늘 나온 사람이 관리자인 경우 count (j & admin != 0)
							if (  (i & j) != 0 && (j & manager) != 0  ) {
								dp[day][j] += dp[day - 1][i];
								dp[day][j] %= DIV;
							}
						}
					}
				}
			}
			day++;
		}

		long long case_cnt = 0;

		for (int i = 1; i < 16; i++) {\
			case_cnt += dp[day - 1][i];
			case_cnt %= 1000000007;
		}
		printf("#%d %llu\n", test_case, case_cnt);

	}
	return 0;
}