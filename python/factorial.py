#!/usr/bin/env python3
n=int(input("Number: "))
fac=1
for i in range(2,n+1):
    fac=fac*i
print(f"Factorial {n}: {fac}")
