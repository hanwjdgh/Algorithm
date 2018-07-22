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

## Ford-fulkerson
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

## Edmonds-karp
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
