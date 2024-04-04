import sys
sys.setrecursionlimit(10 ** 6)

def dfs(graph , start ,sumcost, visited=[]):
    visited.append(start)
    for node in graph[start]:
        if node[0] not in visited:
            sumcost[node[0]]=sumcost[start]+node[1]
            dfs(graph,node[0],sumcost,visited)


def slove():
    n=int(input())
    graph=[[] for _ in range(n+1)]
    sumcost=[0 for _ in range(n+1)]
    for _ in range(n-1):
        start,end,cost=map(int,input().split())
        graph[start].append([end,cost])
        graph[end].append([start,cost])
    dfs(graph,1,sumcost)
    maxidx=sumcost.index(max(sumcost))
    # for i in range(n+1):
    #     print(sumcost[i],end=" ")
    sumcost=[0 for _ in range(n+1)]
    dfs(graph,maxidx,sumcost,[])
    print(max(sumcost))


    # for i in range(n+1):
    #     print(sumcost[i],end=" ")

    
    
    

if __name__=="__main__":
    slove()