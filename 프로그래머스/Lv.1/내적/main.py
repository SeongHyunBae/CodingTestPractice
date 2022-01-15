def solution(a, b):
    answer = 0

    for x, y in zip(a, b):
        answer += x * y

    return answer

if __name__ == "__main__":
    print(solution([1, 2, 3, 4], [-3, -1, 0, 2]))
    print(solution([-1, 0, 1], [1, 0, -1]))