#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include<iostream>

using namespace std;


void dfs(int cnt, int num, char* arr, int cur, int& max_val) {
	if (cnt == num) {
		int val = atoi(arr);
		if (val > max_val) max_val = val;
		return;
	}

	for (int i = cur; i < strlen(arr) - 1; i++) {
		for (int j = i + 1; j < strlen(arr); j++) {
			char tmp;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			dfs(cnt + 1, num, arr, i, max_val);
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		char arr[10];
		int num;

		cin >> arr >> num;

		if (num > strlen(arr)) num = strlen(arr);

		int max_val = 0;
		dfs(0, num, arr, 0, max_val);
		printf("#%d %d\n", test_case, max_val);
	}

	return 0;
}