#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXA = 3002, MAXB = 102;
int N, M;

int A[MAXA];
int B[MAXB];
int cache[MAXA][MAXB][MAXB][2];

// a: 현재 가장 앞에 있는 A봉지 위치
// b1: 현재 가장 많은 조각이 담긴 B봉지 위치 (왼쪽에서 오른쪽으로 이동)
// b2: 현재 가장 적은 조각이 담긴 B봉지 위치 (오른쪽에서 왼쪽을 이동)
// t: 1이면 선택 0이면 선택안함
// cache: a, b1, b2, t 조건에서 가장 많은 조각을 가지는 값

int dp(int a, int b1, int b2, int t)
{
	// A봉지, B봉지 모두 사용
	if (a > N && b1 + (M - b2) > M) return 0;

	// 캐시에서 값 가져오기
	int& ret = cache[a][b1][b2][t];
	// 같은 조건에서 이미 계산한 값이 있으면
	if (ret != -1) return ret;

	// 아래 모든 경우에 대해서 가장 많은 조각을 가지는 값을 리턴해야함
	// 이번 과자 봉지를 선택안하는 경우
	// -> 선택을 안하기 때문에 다음번에는 선택을 하는 경우 / 안하는 경우 모두 따져야함
	if (t == 0) {
		int nuseA = 0, nuseB1 = 0, nuseB2 = 0;
		// A봉지가 있는 경우
		if (a <= N)
			nuseA = max(dp(a + 1, b1, b2, 0), dp(a + 1, b1, b2, 1));

		// B봉지가 있는 경우
		if (b1 + (M - b2) <= M) {
			// 가장 많은 조각이 담긴 B봉지를 가져가는 경우
			nuseB1 = max(dp(a, b1 + 1, b2, 0), dp(a, b1 + 1, b2, 1));
			// 가장 적은 조각이 담긴 B봉지를 가져가는 경우
			nuseB2 = max(dp(a, b1, b2 - 1, 0), dp(a, b1, b2 - 1, 1));
		}
		ret = max({ nuseA, nuseB1, nuseB2 });
	}
	// 이번 과자 봉지를 선택하는 경우
	// -> 선택을 하기 때문에 가져간 조각의 개수 계산 필요 + 다음번에 선택하는 경우 제외
	else {
		int useA = 0, useB1 = 0, useB2 = 0;
		// A봉지가 있는 경우
		if (a <= N)
			useA = dp(a + 1, b1, b2, 0) + A[a];

		// B봉지가 있는 경우
		if (b1 + (M - b2) <= M) {
			// 가장 많은 조각이 담긴 B봉지를 가져가는 경우
			useB1 = dp(a, b1 + 1, b2, 0) + B[b1];
			// 가장 적은 조각이 담긴 B봉지를 가져가는 경우
			useB2 = dp(a, b1, b2 - 1, 0) + B[b2];
		}
		ret = max({ useA , useB1, useB2 });
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
		for (int i = 1; i < N + 1; i++) cin >> A[i];

		cin >> M;
		for (int i = 1; i < M + 1; i++) cin >> B[i];

		for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= M + 1; j++) {
                for (int k = 0; k <= M + 1; k++) {
                    cache[i][j][k][0] = -1;
                    cache[i][j][k][1] = -1;
                }
            }
        }

		// B 봉투를 내림 차순 정렬
		sort(B, B + M);

		printf("#%d %d\n", test_case, max(dp(1, 1, M, 0), dp(1, 1, M, 1)));
	}

	return 0;
}