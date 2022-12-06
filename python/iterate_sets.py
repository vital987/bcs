#!/usr/bin/env python3
s1={1,1.1, "a","CDJ"}
print(s1)
s1.add(65)
s1.update([3, 4, 5])
print(s1)
s1.discard("a")
print(s1)
s1.remove(1)
print(s1)
s2={5, 6, 7, 8.8, True}
s3=s1.union(s2)
print(s3)
