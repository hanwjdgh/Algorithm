# Minimum spanning tree

Spanning tree with weight less than or equal to the weight of every other spanning tree.

## prim's algorithm
The idea of using key values is to pick the minimum weight edge from cut. The key values are used only for vertices which are not yet included in MST, the key value for these vertices indicate the minimum weight edges connecting them to the set of vertices included in MST.
- Pseudocode
```bash
PRIM(G,w,r)
    for each u ∈ G.V:
        u.key = inf
        u.π = NIL
    r.key = 0
    Q = G.V
    while Q ≠ 0:
        u = EXTRACT-MIN(Q)
        for each v ∈ G.Adj[u]:
            if v ∈ Q and w(u,v) < v.key:
                v.π = u
                v.key = w(u,v)
```
- Time Complexity : ElogV

## kruskal algorithm
pick the smallest weight edge that does not cause a cycle in the MST constructed so far. (Union-Find(Disjoint-set))
- Pseudocode
```bash
KRUSKAL(G):
    A = ∅
    for each v ∈ G.V:
       MAKE-SET(v)
    for each (u, v) in G.E ordered by weight(u, v), increasing:
       if FIND-SET(u) ≠ FIND-SET(v):
          A = A ∪ {(u, v)}
          UNION(u, v)
    return A
```
- Time Complexity : ElogE