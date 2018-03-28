# Setting...
inf = 999999
V, E = [int(i) for i in input().strip().split()]

# Declaring...
AM = [[inf for i in range(V+1)] for j in range(V+1)]
AL = [[] for i in range(V+1)]
pernah = [False for i in range(V+1)]
dist = [inf for i in range(V+1)]
ans = []
Q = []

# Defining function...
def add(m, n):
    AL[m].append(n)
    AL[m] = sorted(AL[m])
    AL[n].append(n)
    AL[n] = sorted(AL[m])

def dijkstra(v):
    Q.append(v)
    ans.append(v)
    pernah[v] = True

    while len(Q):
        f = Q[0]

        for i in range(len(AL[f])):
            alfi = AL[f][i]

            if pernah[alfi] != True:
                Q.append(alfi)
                ans.append(alfi)
                pernah[alfi] = True

            dist[alfi] = min(dist[alfi], dist[f]+AM[f][alfi])

        Q.pop(0)

# Input graph (undirected)...
for i in range(E):
    a, b, w = [int(i) for i in input().strip().split()]
    add(a, b)
    AM[a][b] = w
    AM[b][a] = w

# Define source...    
src = int(input().strip())
dist[src] = 0

# Execute Dijkstra...
dijkstra(src)

# Print the shortest path...
print('Length of shortest path from')
for i in range(1, len(dist)):
    print('vrtx {} to vrtx {} = {},'.format(src, i, dist[i]))
    
# if it prints 999999, then there's no path from src to this vertex
# to see input and output format, please see in dijkstra.cpp in this folder
