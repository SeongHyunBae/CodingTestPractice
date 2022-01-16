def solution(id_list, report, k):
    id_encoder = {}
    check = [[0]*len(id_list) for _ in range(len(id_list))]
    get_cnt = [0]*len(id_list)

    for n, i in enumerate(id_list):
        id_encoder[i] = n

    for r in report:
        from_id, to_id = r.split(" ")
        from_id, to_id = id_encoder[from_id], id_encoder[to_id]

        if not check[from_id][to_id]:
            check[from_id][to_id] += 1

    for i in range(len(id_list)):
        s = 0
        save = []
        for j in range(len(id_list)):
            if check[j][i]:
                s += 1
                save.append(j)

        if s >= k:
            for x in save:
                get_cnt[x] += 1

    return get_cnt

if __name__ == "__main__":
    print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"], 2))
    print(solution(["con", "ryan"], ["ryan con", "ryan con", "ryan con", "ryan con"], 3))