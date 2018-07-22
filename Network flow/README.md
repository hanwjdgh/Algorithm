# Network flow

- Source : Start position
- Sink : End position
- Vertex : Location where flow is gathered
- Edge : Role of flow pipe
- Capacity : Size at which can flow
- c(u,v) : Capacity, that from u to v
- f(u,v) : Flow, that from u to v

- f(u,v) ≤ c(u,v)
- f(u,v) = -f(u,v)
- Σf(u,v) = 0

## Ford-fulkerson Algorithm
The Ford-Fulkerson algorithm is an algorithm that tackles the max-flow min-cut problem. (DFS)

- Pseudocode
```bash
initialize flow to 0
path = findAugmentingPath(G, s, t)
while path exists:
    augment flow along path                 #This is purposefully ambiguous for now
    G_f = createResidualGraph()
    path = findAugmentingPath(G_f, s, t)
return flow

flow = 0
for each edge (u, v) in G:
    flow(u, v) = 0
while there is a path, p, from s -> t in residual network G_f:
    residual_capacity(p) = min(residual_capacity(u, v) : for (u, v) in p)
    flow = flow + residual_capacity(p)
    for each edge (u, v) in p:
        if (u, v) is a forward edge:
            flow(u, v) = flow(u, v) + residual_capacity(p)
        else:
            flow(u, v) = flow(u, v) - residual_capacity(p)
return flow
```
- Time Complexity : Ef

## Edmonds-karp Algorithm
The Edmonds-Karp Algorithm is a specific implementation of the Ford-Fulkerson algorithm. Like Ford-Fulkerson, Edmonds-Karp is also an algorithm that deals with the max-flow min-cut problem. (BFS)

- Pseudocode
```bash
inputs
    C[n x n] : Capacity Matrix
    E[n x n] : Adjacency Matrix
    s : source
    t : sink
output
    f : maximum flow
Edmonds-Karp:
    f = 0                // Flow is initially 0
    F = [n x n]       // residual capacity array
    while true:
        m, P = Breadth-First-Search(C, E, s, t, F)
        if m = 0:
            break
        f = f + m
        v = t
        while v != s:
            u = P[v]
            F[u, v] = F[u, v] - m       //This is reducing the residual capacity of the augmenting path
            F[v, u] = F[v, u] + m        //This is increasing the residual capacity of the reverse edges 
            v = u
    return f
```
- Time Complexity : VE<sup>2</sup>


## Dinic's Algorithm

Strongly polynomial algorithm for computing the maximum flow in a flow network

- level graph : Graph showing the shortest distance from the source (the number of trunks that must be traversed) to the level value for all vertices
- blocking flow : Movement is possible only when the level of v is exactly 1 level greater than that of u. In these graphs, no more flow rate is allowed from the source.

- Pseudocode
```bash
bool bfs()
    fill(level, level+MAX, -1)
    level[S] = 0
    
    queue<int> Q
    Q.push(S)
    while !Q.empty():
        int curr = Q.front()
        Q.pop()
        for int next: adj[curr]:
            if level[next] == -1 && c[curr][next]-f[curr][next] > 0:
                level[next] = level[curr] + 1
                Q.push(next)
    return level[E] != -1

int dfs(int curr, int dest, int flow)
    if curr == dest:
        return flow;
 
    for int &i=work[curr] to adj[curr].size()
        int next = adj[curr][i]
        if level[next] == level[curr]+1 && c[curr][next]-f[curr][next] > 0:
            int df = dfs(next, dest, min(c[curr][next]-f[curr][next], flow))
            if df > 0:
                f[curr][next] += df
                f[next][curr] -= df
                return df
    return 0;

```

- Time Complexity : V<sup>2</sup>E