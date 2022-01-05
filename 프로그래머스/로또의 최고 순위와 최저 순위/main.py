def solution(lottos, win_nums):
    answer = []

    zero_num = 0
    correct_num = 0
    for i in lottos:
        if i == 0:
            zero_num += 1
        else:
            if i in win_nums:
                correct_num += 1

    # 로또 규칙
    # 6개 일치, 1등
    # 5개 일치, 2등
    # 4개 일치, 3등
    # 3개 일치, 4등
    # 2개 일치, 5등
    # 그 외, 6등

    best_result = 7 - (correct_num + zero_num)
    worst_result = 7 - correct_num

    answer.append(min(6, best_result))
    answer.append(min(6, worst_result))

    return answer

if __name__ == "__main__":
    print(solution(	[44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))
    print(solution(	[0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]))
    print(solution(	[45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35]))