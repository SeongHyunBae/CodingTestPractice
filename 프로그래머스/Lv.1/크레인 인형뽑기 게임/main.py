def solution(board, moves):
    answer = 0
    bag = []
    for m in moves:
        m -= 1

        for i in range(len(board[0])):
            n = board[i][m]
            if n != 0:
                board[i][m] = 0

                if len(bag) == 0:
                    bag.append(n)
                else:
                    if n != bag[-1]:
                        bag.append(n)
                    else:
                        bag.pop()
                        answer += 2
                break

    return answer


if __name__ == "__main__":
    print(solution(	[[0,
                         0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]))