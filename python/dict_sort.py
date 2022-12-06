#!/usr/bin/env python3
d={3: "Three", 1: "One", 2:"Two"}
sorted_d={}
for i in sorted(d):
    sorted_d[i]=d[i]
print(f"Unsorted: {d}\nSorted: {sorted_d}")