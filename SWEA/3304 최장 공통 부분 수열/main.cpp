#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

using namespace std;

#define MAXN 1001
int LCS[MAXN][MAXN];


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		char c1[MAXN];
		char c2[MAXN];
		cin >> c1 >> c2;
		
		memset(LCS, 0, sizeof(LCS));

		for (int i = 1; i <= strlen(c1); i++) {
			for (int j = 1; j <= strlen(c2); j++) {
				if (c1[i - 1] == c2[j - 1]) {
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}
				else {
					LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
				}
			}
		}
		printf("#%d %d\n", test_case, LCS[strlen(c1)][strlen(c2)]);
	}

	return 0;
}