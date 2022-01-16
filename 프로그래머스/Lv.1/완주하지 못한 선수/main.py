def solution(participant, completion):
    answer = ''

    name_dic = {}

    for p in participant:
        if name_dic.get(p) is None:
            name_dic[p] = 1
        else:
            name_dic[p] += 1

    for c in completion:
        name_dic[c] -= 1

    for p, cnt in name_dic.items():
        if cnt != 0:
            return p


if __name__ == "__main__":
    print(solution(["leo", "kiki", "eden"], ["eden", "kiki"]))
    print(solution(	["marina", "josipa", "nikola", "vinko", "filipa"], ["josipa", "filipa", "marina", "nikola"]))
    print(solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"]))