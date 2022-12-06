#!/usr/bin/env python3
s=input("String: ")
mid=int(len(s)/2)
if((s[:mid]==s[mid:][::-1]) or (s[:mid]==s[mid+1:][::-1])):
    print("Symmetrical.")
else:
    print("Not a Symmetrical.")