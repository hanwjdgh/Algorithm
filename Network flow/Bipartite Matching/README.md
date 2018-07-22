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