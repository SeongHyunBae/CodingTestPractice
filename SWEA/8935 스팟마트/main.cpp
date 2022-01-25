#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXA = 3001, MAXB = 101;
int N, M;

int A[MAXA];
int B[MAXB];
int cache[MAXA][MAXB][MAXB][2];

//dp[n_i][m_i][skip][get]
//n_i : n봉지의 과자 중 n_i번째를 보고있는 상태(0과 n은 각각 왼쪽 끝, 오른쪽 끝을 의미한다.
//m_i : m봉지의 과자 중 고른 과자의 수
//skip : m봉지 중 스킵한 개수
//get : 위 상태일 때 바로 직전에 과자를 get했는가 (했으면 1)
int dp(int n_i, int m_i, int skip, int get)
{
	// 만약 n봉지 끝까지 갔고 && m봉지도 끝까지 간 경우(고른 과자 + 스킵 과자)
	if (n_i == N && m_i + skip == M) return 0;

	int& ret = cache[n_i][m_i][skip][get];
	if (ret != -1) return ret;

	ret = 0;

	// A봉지는 차례대로 놓고 고르고
	// B봉지는 고를 때는 조각이 가장 많은 봉투, 고르지 않을 때는 조각이 가장 적은 봉투를 놓음

	// 직전에 봉투를 고르지 않은 경우 -> 이번에는 고를수도 안고를수도 있음
	if (get == 0) {
		// 만약 n봉지를 다 고르지 않은 상태일 때
		if (n_i < N) {
			ret = max(ret, dp(n_i + 1, m_i, skip, 1) + A[n_i]); // 현재 차례의 A봉지를 놓고 고름
			ret = max(ret, dp(n_i + 1, m_i, skip, 0)); // 현재 차례의 A봉지를 놓되 고르지 않음
		}

		// 만약 m봉지를 다 고르지 않은 상태일 때
		if (m_i + skip < M) {
			ret = max(ret, dp(n_i, m_i + 1, skip, 1) + B[m_i]); // 과자가 가장 많은 B봉지를 놓고 고름
			ret = max(ret, dp(n_i, m_i, skip + 1, 0)); // 과자가 가장 적은은 B봉지를 놓되 고르지 않음
		}
	}
	// 직전에 봉투를 고른 경우 -> 이번에는 고르지 못함
	else {
		// 만약 n봉지를 다 고르지 않은 상태일 때
		if (n_i < N)
			ret = max(ret, dp(n_i + 1, m_i, skip, 0)); // 현재 차례의 A봉지를 놓되 고르지 않음(고르지 못함)

		// 만약 m봉지를 다 고르지 않은 상태일 때
		if (m_i + skip < M)
			ret = max(ret, dp(n_i, m_i, skip + 1, 0)); // 과자가 가장 적은은 B봉지를 놓되 고르지 않음(고르지 못함)
	}

	return ret;
}



int main()
{
	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i];

		cin >> M;
		for (int i = 0; i < M; i++) cin >> B[i];

		for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                for (int k = 0; k <= M; k++) {
                    cache[i][j][k][0] = -1;
                    cache[i][j][k][1] = -1;
                }
            }
        }

		// B 봉투를 내림차순 정렬
		sort(B, B + M, greater<int>());

		printf("#%d %d\n", test_case, dp(0, 0, 0, 0));
	}

	return 0;
}