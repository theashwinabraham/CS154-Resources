#! /usr/bin/python3.8

# AUTHOR: ASHWIN ABRAHAM

l = [1,2,3]
x=0
for e in l:
    x = x + e
    print(x)
    if (e==2):
        break
else:
 print(x)