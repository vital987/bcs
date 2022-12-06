#!/usr/bin/env python3
n=int(input("Number: "))
sumn=0
for i in range(1, n):
    if(n%i==0):
        sumn+=i
print("Number is perfect.") if(sumn==n) else print("Number is imperfect.")

