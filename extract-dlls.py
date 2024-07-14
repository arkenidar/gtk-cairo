print("cd /media/darcan/ms-win-11/msys64/mingw64/bin/")

print("cp \\")

for line in open("wine-output.txt"):
    parts = line.split(" ")
    if len(parts) > 1 and parts[1] == "Library":
        print(parts[2] + " \\")

print("/media/darcan/ms-win-11/0/projects/gtk-cairo/")
