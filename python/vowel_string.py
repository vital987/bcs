#!/usr/bin/env python3
s=input("String: ")
isThere=False
for i in range(len(s)):
    if(s[i] in ['a', 'e', 'i', 'o', 'u']):
        isThere=True
print("String contains vowel(s).") if isThere else print("String doesn't contain any vowel.")
