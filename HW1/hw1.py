#!/usr/bin/env python

import subprocess

print("menu (1) gugudan (2) factorial\n")

a = int(input("which one would you like to choose?\n"))

if a == 1:
    print("run gugudan\n")
    print(subprocess.run("python3.10 gugudan.py", shell=True))

elif a == 2:
    print("run factorial\n")
    print(subprocess.run("python3.10 factorial.py", shell=True))

else:
    print("error\n")


