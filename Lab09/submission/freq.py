# AUTHOR: ASHWIN ABRAHAM

def freq(list1, list2):
    return [[x, list1.count(x)+list2.count(x)] for i, x in enumerate(list1) if x in list2 and x not in list1[:i]]