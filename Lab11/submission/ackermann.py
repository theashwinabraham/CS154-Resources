# AUTHOR: ASHWIN ABRAHAM

def ackermann(m, n):
    if m == 0:
        return n+1
    if n == 0:
        return ackermann(m-1, 1)
    return ackermann(m-1, ackermann(m, n-1))

ackermannmap = {}

def ackermann_memo(m, n):
    if (m, n) in ackermannmap:
        return ackermannmap[(m, n)]
    if m == 0:
        ackermannmap[(m, n)] = n+1
        return n+1
    if n == 0:
        ackermannmap[(m, n)] = ackermann_memo(m-1, 1)
        return ackermannmap[(m, n)]
    ackermannmap[(m, n)] = ackermann_memo(m-1, ackermann_memo(m, n-1))
    return ackermannmap[(m, n)]