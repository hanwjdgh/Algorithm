# Depth-First Search (DFS)

Algorithm traverses a graph in a depthward motion and uses a stack to remember to get the next vertex to start a search, when a dead end occurs in any iteration.

- Pseudocode
```bash
procedure DFS(G,v):
      label v as discovered
      for all edges from v to w in G.adjacentEdges(v) do
          if vertex w is not labeled as discovered then
            	recursively call DFS(G,w)
```

- Time Complexity : adjacency list V+E / adjacency matrix : V<sup>2</sup>