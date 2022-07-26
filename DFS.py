graph = [[],[2,4,5],[3],[4,5],[5],[1]]
n = len(graph)
vis = []
for i in range(n):
    vis.append(False)
def DFS(vertex):
    if(vis[vertex]==True):
        return
    print(vertex)
    vis[vertex] = True
    for child in graph[vertex] :
        DFS(child)

DFS(1)
    
