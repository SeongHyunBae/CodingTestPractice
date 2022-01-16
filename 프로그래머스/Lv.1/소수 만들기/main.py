import math


def isPrimeNumber(x):
    if x < 2:
        return False

    for i in range(2, int(math.sqrt(x) + 1)):
        if x % i == 0:
            return False

    return True


def dfs(depth, pos, nums, selected, prime):
    if depth == 3:
        s = 0
        for i in selected:
            s += i

        if isPrimeNumber(s):
            prime.append(s)

        return

    if pos == len(nums):
        return

    dfs(depth + 1, pos + 1, nums, selected + [nums[pos]], prime)
    dfs(depth, pos + 1, nums, selected, prime)


def solution(nums):
    prime = []
    dfs(0, 0, nums, [], prime)
    return len(prime)

if __name__ == "__main__":
    print(solution([1, 2, 3, 4]))
    print(solution([1, 2, 7, 6, 4]))