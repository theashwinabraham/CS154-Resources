#! /usr/bin/python3.8

# AUTHOR: ASHWIN ABRAHAM

l = [1,2,3]
l2 = l
if l is l2:
    print("it's the same object")
l2.append(10)
print(l)