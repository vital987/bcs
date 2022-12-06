#!/usr/bin/env python3
s=int(input("Number: "))
isPrime=True
for i in range(2, s):
    if(s%i==0):
        isPrime=False
print("Number is Prime") if isPrime else print("Number is Composite.")
