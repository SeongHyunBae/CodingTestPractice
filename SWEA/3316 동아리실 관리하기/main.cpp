#include "pch.h"
#include<iostream>
#include<string.h>

using namespace std;

#define DIV 1000000007
#define MAX 10000

long long dp[MAX][16]; // A, B, C, D ����� �� 2^4 -1 = 15(��� ���� ��� ����)


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
				if (day == 0) { // 1����
					// i��° ��쿡 �����ڿ� A�� ���ԵǸ�
					if ( (i & manager) != 0 && (i & 1) != 0 ) {
						dp[day][i] = 1;
					}
				}
				else { // 2���� ~
					// ���������� ����� ���� 0�� �ƴϸ�
					if (dp[day - 1][i] != 0) {
						for (int j = 1; j < 16; j++) {
							// ���� ���� ����� ���õ� ������ (i & j != 0)
							// ���� ���� ����� �������� ��� count (j & admin != 0)
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