#!/usr/bin/env python3
n=input("Number: ")
sum=0
for i in n:
    sum+=int(i)**len(n)
if int(n)==sum:
    print("Armstrong.")
else:
    print("Ain't Armstrong.")
