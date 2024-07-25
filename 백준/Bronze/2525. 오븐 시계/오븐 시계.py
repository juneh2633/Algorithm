data = input()
H, M = map(int, data.split())
wm = int(input())

M +=wm
H = ( M//60 + H )%24
M = M%60

print(int(H), int(M))


