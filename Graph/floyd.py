V, E = input().strip().split()
V, E = int(V), int(E)

AM = [[99999 for i in range(0,V)] for j in range(0,V)]

for i in range(E):
    a, b, w = input().strip().split()
    a, b, w = int(a), int(b), int(w)
    AM[a][b] = w

for i in AM:
    for j in i:
        print(j,'', end='') if j != 99999 else print('M ', end='')
    print()

for k in range(V):
    for i in range(V):
        for j in range(V):
            if i != j:
                AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j])

print('After Floyd :')
for i in AM:
    for j in i:
        print(j,'', end='') if j != 99999 else print('M ', end='')
    print()

'''
5 7
0 1 2
0 3 6
1 2 3
1 3 3
2 3 2
3 4 4
4 2 1
'''
