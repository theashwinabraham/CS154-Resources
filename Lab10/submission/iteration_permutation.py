# AUTHOR: ASHWIN ABRAHAM

def fact(n):
    prod = 1
    for i in range(1, 1+n):
        prod*=i
    return prod

def dec_point(Enum_List):
    for i in range(len(Enum_List)-1, 0, -1):
        if Enum_List[i][0] > Enum_List[i-1][0]:
            return i
    return 0

def find_greater(val, Enum_List):
    for ind in range(len(Enum_List)):
        if Enum_List[len(Enum_List) - ind - 1][0]>val:
            return len(Enum_List) - ind - 1

def next_permutation(Enum_List):
    dp = dec_point(Enum_List)
    if dp == 0:
        return Enum_List[::-1]
    return (Enum_List[:dp-1]+[Enum_List[dp+find_greater(Enum_List[dp-1][0], Enum_List[dp:])]]+
    (Enum_List[dp:dp+find_greater(Enum_List[dp-1][0], Enum_List[dp:])]+[Enum_List[dp-1]]+
    Enum_List[dp+find_greater(Enum_List[dp-1][0], Enum_List[dp:])+1:])[::-1])

def permutations(List):
    if len(List) == 0:
        return []
    ret = [List]
    Enum_List = [(i, x) for i, x in enumerate(List)]
    for i in range(1, fact(len(List))):
        Enum_List = next_permutation(Enum_List)
        ret.append([x[1] for x in Enum_List])
    return [w for i, w in enumerate(ret) if w not in ret[:i]]