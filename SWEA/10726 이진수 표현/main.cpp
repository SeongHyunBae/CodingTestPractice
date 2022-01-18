#include "pch.h"
#include<iostream>

typedef long long ll;
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	ll N, M, x;

	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		// N비트가 모두 1인 수 계산
		x = (1 << N) - 1;

		// M의 뒤 N비트가 모두 1 이면
		if ((M & x) == x)
			printf("#%d ON\n", test_case);
		else 
			printf("#%d OFF\n", test_case);
	}
	return 0;
}