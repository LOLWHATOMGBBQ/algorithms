# Number letter counts
# one, two, three, four, five, six, sevem, eight, nine
# ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
# twenty
# thirty
# forty -- SPELLED LIKE THIS NOT fourty
# fifty
# sixty
# seventy
# eighty
# ninety
# one hundred


def to_len(n):
    num_to_len = {
        0: len(""), # nothing
        1: len("one"),
        2: len("two"),
        3: len("three"),
        4: len("four"),
        5: len("five"),
        6: len("six"),
        7: len("seven"),
        8: len("eight"),
        9: len("nine"),
    }
    teen_to_len = {
        10: len("ten"),
        11: len("eleven"),
        12: len("twelve"),
        13: len("thirteen"),
        14: len("fourteen"),
        15: len("fifteen"),
        16: len("sixteen"),
        17: len("seventeen"),
        18: len("eighteen"),
        19: len("nineteen"),
    }
    ten_to_len = {
        2: len("twenty"),
        3: len("thirty"),
        4: len("forty"),
        5: len("fifty"),
        6: len("sixty"),
        7: len("seventy"),
        8: len("eighty"),
        9: len("ninety"),
    }

    def hundreds(n):
        return num_to_len[n // 100] + len("hundred")
    def teens(n):
        if n < 10:
            return num_to_len[n]
        elif n < 20:
            return teen_to_len[n]
        else:
            return ten_to_len[n//10] + num_to_len[n%10]

    if n == 1000:
        return len("one") + len("thousand")
    elif n%100 == 0:
        return hundreds(n)
    elif n > 100:
        return hundreds(n) + len("and") + teens(n%100)
    else:
        return teens(n)

tot = 0
for i in range(1, 1001):
    tot += to_len(i)
print(tot)
