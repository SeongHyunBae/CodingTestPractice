def solution(absolutes, signs):
    answer = 0

    for n, p in zip(absolutes, signs):
        if p:
            answer += n
        else:
            answer -= n

    return answer


if __name__ == "__main__":
    print(solution([4, 7, 12], [True, False, True]))
    print(solution([1, 2, 3], [False, False, True]))