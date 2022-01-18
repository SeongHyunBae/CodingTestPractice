def solution(array, commands):
    answer = []

    for i, j, k in commands:
        s_arr = sorted(array[i - 1:j])
        answer.append(s_arr[k - 1])

    return answer


if __name__ == "__main__":
    print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))