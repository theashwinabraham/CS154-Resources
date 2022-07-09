def min(l):
    if (len(l)==1):
        return l[0]
    tmp = l[0]
    m = min(l[1:])
    if (l[0]<m):
        return l[0]
    else:
        return m


l=[0,20,111,33,222,12,1]
l=[2,1]

print (min(l))
