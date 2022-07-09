# AUTHOR: ASHWIN ABRAHAM

def insert(val, List):
    return [List[:x]+[val]+List[x:] for x in range(1+len(List))]

def permutations(List):
    if len(List) <= 1:
        return [List] if len(List) == 1 else []
    arr = [pm for x in permutations(List[1:]) for pm in insert(List[0], x)]
    return [w for i, w in enumerate(arr) if w not in arr[:i]]