# Bipartite Matching

A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint. A maximum matching is a matching of maximum size.

- Pseudocode
```bash
bool dfs(int x) 
	for i = 0 to adj[x].size(): 
		int t = adj[x][i]
		if c[t]:
			continue
		c[t] = true;
		if d[t] == 0 || dfs(d[t]): 
			d[t] = x
			return true
	return false
```

- Time Complexity : VE

## Hopcroft-Karp Algorithm

An algorithm that takes a bipartite graph and outputs a maximum matching.

- Pseudocode
```bash
/* 
 G = U ∪ V ∪ {NIL}
 where U and V are partition of graph and NIL is a special null vertex
*/
  
function BFS ()
    for each u in U
        if Pair_U[u] == NIL
            Dist[u] = 0
            Enqueue(Q,u)
        else
            Dist[u] = ∞
    Dist[NIL] = ∞
    while Empty(Q) == false
        u = Dequeue(Q)
        if Dist[u] < Dist[NIL] 
            for each v in Adj[u]
                if Dist[ Pair_V[v] ] == ∞
                    Dist[ Pair_V[v] ] = Dist[u] + 1
                    Enqueue(Q,Pair_V[v])
    return Dist[NIL] != ∞

function DFS (u)
    if u != NIL
        for each v in Adj[u]
            if Dist[ Pair_V[v] ] == Dist[u] + 1
                if DFS(Pair_V[v]) == true
                    Pair_V[v] = u
                    Pair_U[u] = v
                    return true
        Dist[u] = ∞
        return false
    return true

function Hopcroft-Karp
    for each u in U
        Pair_U[u] = NIL
    for each v in V
        Pair_V[v] = NIL
    matching = 0
    while BFS() == true
        for each u in U
            if Pair_U[u] == NIL
                if DFS(u) == true
                    matching = matching + 1
    return matching
```

- Time Complexity : E√V