#include "pch.h"
#include<iostream>

using namespace std;

int solve() {
	int N;
	cin >> N;
	int i = 1;
	int val;
	int check = 0;

	// 0~9 위치 모두 표시될 때 까지
	while (check != (1 << 10) - 1) {
		val = N * i++;

		int tmp = val;
		while (tmp) {
			check = check | (1 << (tmp % 10)); // 각 자릿수를 check에 표시
			tmp /= 10;
		}
	}
	return val;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	FILE *stream;
	freopen_s(&stream, "sample_input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << '#' << test_case << " " << solve() << endl;
	}
	return 0;
}