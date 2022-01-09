import itertools
from collections import defaultdict
def solution(orders, course):
    answer = []
    new_order= list()
    for l in orders:
        new_order.append(sorted(l))
    
    for num in course:
        order_count = defaultdict(int)
        for order in new_order:
            comb = list(itertools.combinations(order,num))
            for com in comb:
                string_comb = "".join(com)
                order_count[string_comb] += 1
        max_value = max(list(order_count.values()) + [2])
        for key, value in order_count.items():
            if value == max_value:
                answer.append(key)
    # 정답은 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬해서 return.
    return sorted(answer)