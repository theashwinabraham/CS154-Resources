# AUTHOR: ASHWIN ABRAHAM

def power(Set):
    return set([frozenset([p for i, p in enumerate(list(Set)) if (x>>i)&1]) for x in range(2**len(list(Set)))])