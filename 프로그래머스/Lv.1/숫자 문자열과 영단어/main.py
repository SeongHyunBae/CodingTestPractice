def solution(s):
    decoder = {
        'zero': '0',
        'one': '1',
        'two': '2',
        'three': '3',
        'four': '4',
        'five': '5',
        'six': '6',
        'seven': '7',
        'eight': '8',
        'nine': '9'
    }

    word = ''
    answer = ''
    for n, i in enumerate(s):
        if i.isdigit():
            answer += i
        else:
            word += i

            if word in decoder.keys():
                answer += decoder[word]
                word = ''

    return int(answer)


if __name__ == "__main__":
    print(solution("one4seveneight"))
    print(solution("23four5six7"))
    print(solution("2three45sixseven"))
    print(solution("123"))