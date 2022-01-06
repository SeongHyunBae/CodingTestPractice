def solution(new_id):
    # 1 단계: 모든 대문자를 대응되는 소문자로 치환
    new_id = new_id.lower()

    # 2 단계: 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자를 제거
    new_id2 = ''
    for i in new_id:
        if i.isdecimal() or i.isalpha() or i in ['-', '_', '.']:
            new_id2 += i
    new_id = new_id2

    # 3 단계: 마침표가 2번 이상 연속된 부분을 하나의 마침표로 치환
    new_id2 = new_id[0]
    for i in range(1, len(new_id)):
        if new_id2[len(new_id2) - 1] == new_id[i] and new_id2[len(new_id2) - 1] == '.' and new_id[i] == '.':
            continue
        new_id2 += new_id[i]
    new_id = new_id2

    # 4 단계: 마침표가 처음이나 끝에 위치한다면 제거
    if len(new_id) > 0 and new_id[0] == '.':
        new_id = new_id[1:]

    if len(new_id) > 0 and new_id[-1] == '.':
        new_id = new_id[:-1]

    # 5 단계: 빈 문자열이라면, "a"를 대입
    if len(new_id) == 0:
        new_id = 'a'

    # 6 단계: 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    #        만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id[-1] == '.':
            new_id = new_id[:-1]

    # 7 단계: 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙임
    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]

    return new_id


if __name__ == "__main__":
    print(solution("...!@BaT#*..y.abcdefghijklm"))
    print(solution(	"z-+.^."))
    print(solution(	"=.="))
    print(solution("123_.def"))
    print(solution("abcdefghijklmn.p"))