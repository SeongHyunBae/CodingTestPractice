def solution(numbers, hand):
    answer = ''

    pad = {1: [0, 0], 2: [0, 1], 3: [0, 2],
           4: [1, 0], 5: [1, 1], 6: [1, 2],
           7: [2, 0], 8: [2, 1], 9: [2, 2],
           0: [3, 1]}

    left_pos = [3, 0]
    right_pos = [3, 2]

    for i in numbers:
        if i in [1, 4, 7]:
            answer += 'L'
            left_pos = pad[i]

        elif i in [3, 6, 9]:
            answer += 'R'
            right_pos = pad[i]

        else:
            pos = pad[i]
            l_dist = abs(left_pos[0] - pos[0]) + abs(left_pos[1] - pos[1])
            r_dist = abs(right_pos[0] - pos[0]) + abs(right_pos[1] - pos[1])

            if l_dist > r_dist:
                answer += 'R'
                right_pos = pos
            elif l_dist < r_dist:
                answer += 'L'
                left_pos = pos
            else:
                if hand == "right":
                    answer += 'R'
                    right_pos = pos
                else:
                    answer += 'L'
                    left_pos = pos

    return answer


if __name__ == "__main__":
    print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
    print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"))
    print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], "right"))