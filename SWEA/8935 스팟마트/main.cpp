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
//n_i : n������ ���� �� n_i��°�� �����ִ� ����(0�� n�� ���� ���� ��, ������ ���� �ǹ��Ѵ�.
//m_i : m������ ���� �� �� ������ ��
//skip : m���� �� ��ŵ�� ����
//get : �� ������ �� �ٷ� ������ ���ڸ� get�ߴ°� (������ 1)
int dp(int n_i, int m_i, int skip, int get)
{
	// ���� n���� ������ ���� && m������ ������ �� ���(�� ���� + ��ŵ ����)
	if (n_i == N && m_i + skip == M) return 0;

	int& ret = cache[n_i][m_i][skip][get];
	if (ret != -1) return ret;

	ret = 0;

	// A������ ���ʴ�� ���� ����
	// B������ �� ���� ������ ���� ���� ����, ���� ���� ���� ������ ���� ���� ������ ����

	// ������ ������ ���� ���� ��� -> �̹����� ������ �Ȱ����� ����
	if (get == 0) {
		// ���� n������ �� ���� ���� ������ ��
		if (n_i < N) {
			ret = max(ret, dp(n_i + 1, m_i, skip, 1) + A[n_i]); // ���� ������ A������ ���� ��
			ret = max(ret, dp(n_i + 1, m_i, skip, 0)); // ���� ������ A������ ���� ���� ����
		}

		// ���� m������ �� ���� ���� ������ ��
		if (m_i + skip < M) {
			ret = max(ret, dp(n_i, m_i + 1, skip, 1) + B[m_i]); // ���ڰ� ���� ���� B������ ���� ��
			ret = max(ret, dp(n_i, m_i, skip + 1, 0)); // ���ڰ� ���� ������ B������ ���� ���� ����
		}
	}
	// ������ ������ �� ��� -> �̹����� ���� ����
	else {
		// ���� n������ �� ���� ���� ������ ��
		if (n_i < N)
			ret = max(ret, dp(n_i + 1, m_i, skip, 0)); // ���� ������ A������ ���� ���� ����(���� ����)

		// ���� m������ �� ���� ���� ������ ��
		if (m_i + skip < M)
			ret = max(ret, dp(n_i, m_i, skip + 1, 0)); // ���ڰ� ���� ������ B������ ���� ���� ����(���� ����)
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

		// B ������ �������� ����
		sort(B, B + M, greater<int>());

		printf("#%d %d\n", test_case, dp(0, 0, 0, 0));
	}

	return 0;
}