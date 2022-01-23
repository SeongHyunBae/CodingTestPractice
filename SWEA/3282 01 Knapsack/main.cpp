#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int W[100], V[100];
int N, K;
int dp[101][1001];

int go(int i, int w) 
{
	if (dp[i][w] > 0) return dp[i][w];
	if (i == N) return 0;

	int n1 = 0;
	if (w + W[i] <= K)
		n1 = V[i] + go(i + 1, w + W[i]); // 포함
	int n2 = 0 + go(i + 1, w); // 미포함

	return dp[i][w] = max(n1, n2);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> W[i] >> V[i];
		}

		memset(dp, 0, sizeof(dp));

		printf("#%d %d\n", test_case, go(0, 0));
	}

	return 0;
}