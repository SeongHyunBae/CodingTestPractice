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

// a: ���� ���� �տ� �ִ� A���� ��ġ
// b1: ���� ���� ���� ������ ��� B���� ��ġ (���ʿ��� ���������� �̵�)
// b2: ���� ���� ���� ������ ��� B���� ��ġ (�����ʿ��� ������ �̵�)
// t: 1�̸� ���� 0�̸� ���þ���
// cache: a, b1, b2, t ���ǿ��� ���� ���� ������ ������ ��

int dp(int a, int b1, int b2, int t)
{
	// A����, B���� ��� ���
	if (a > N && b1 + (M - b2) > M) return 0;

	// ĳ�ÿ��� �� ��������
	int& ret = cache[a][b1][b2][t];
	// ���� ���ǿ��� �̹� ����� ���� ������
	if (ret != -1) return ret;

	// �Ʒ� ��� ��쿡 ���ؼ� ���� ���� ������ ������ ���� �����ؾ���
	// �̹� ���� ������ ���þ��ϴ� ���
	// -> ������ ���ϱ� ������ ���������� ������ �ϴ� ��� / ���ϴ� ��� ��� ��������
	if (t == 0) {
		int nuseA = 0, nuseB1 = 0, nuseB2 = 0;
		// A������ �ִ� ���
		if (a <= N)
			nuseA = max(dp(a + 1, b1, b2, 0), dp(a + 1, b1, b2, 1));

		// B������ �ִ� ���
		if (b1 + (M - b2) <= M) {
			// ���� ���� ������ ��� B������ �������� ���
			nuseB1 = max(dp(a, b1 + 1, b2, 0), dp(a, b1 + 1, b2, 1));
			// ���� ���� ������ ��� B������ �������� ���
			nuseB2 = max(dp(a, b1, b2 - 1, 0), dp(a, b1, b2 - 1, 1));
		}
		ret = max({ nuseA, nuseB1, nuseB2 });
	}
	// �̹� ���� ������ �����ϴ� ���
	// -> ������ �ϱ� ������ ������ ������ ���� ��� �ʿ� + �������� �����ϴ� ��� ����
	else {
		int useA = 0, useB1 = 0, useB2 = 0;
		// A������ �ִ� ���
		if (a <= N)
			useA = dp(a + 1, b1, b2, 0) + A[a];

		// B������ �ִ� ���
		if (b1 + (M - b2) <= M) {
			// ���� ���� ������ ��� B������ �������� ���
			useB1 = dp(a, b1 + 1, b2, 0) + B[b1];
			// ���� ���� ������ ��� B������ �������� ���
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

		// B ������ ���� ���� ����
		sort(B, B + M);

		printf("#%d %d\n", test_case, max(dp(1, 1, M, 0), dp(1, 1, M, 1)));
	}

	return 0;
}