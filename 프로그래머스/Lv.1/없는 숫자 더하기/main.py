def solution(numbers):
    return sum([i for i in range(10)]) - sum(numbers)


if __name__ == "__main__":
    print(solution([1, 2, 3, 4, 6, 7, 8, 0]))
    print(solution([5, 8, 4, 0, 6, 7, 9]))