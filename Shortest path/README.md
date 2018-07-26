# Shortest path

Finding a path between two vertices (or nodes) in a graph such that the sum of the weights of its constituent edges is minimized.

- single-sourece shortest path : from a source vertex v to all other vertices in the graph.
- single-destination shortest path : from all vertices in the directed graph to a single destination vertex v.
- single-pair shortest path between u and v.
- all-pair shortest path : between every pair of vertices v, v' in the graph.

## Dijkstra's Algorithm
- Suitable for solving a single-sourece shortest path
- Doesn’t work for Graphs with negative weight edges
- Pseudocode
```bash
function Dijkstra(Graph, source):
      dist[source] ← 0                           // Initialization

     create vertex set Q
     for each vertex v in Graph:           
         if v ≠ source
             dist[v] ← INFINITY                 // Unknown distance from source to v
         prev[v] ← UNDEFINED                    // Predecessor of v

         Q.add_with_priority(v, dist[v])


     while Q is not empty:                      // The main loop
         u ← Q.extract_min()                    // Remove and return best vertex
         for each neighbor v of u:              // only v that is still in Q
             alt ← dist[u] + length(u, v) 
             if alt < dist[v]
                 dist[v] ← alt
                 prev[v] ← u
                 Q.decrease_priority(v, alt)

     return dist, prev
```
- Time Complexity : V<sup>2</sup>, Min heap = ElogV

## Bellman-Ford Algorithm
- Suitable for solving a single-sourece shortest path 
- Does work for Graphs with negative weight edges
- Pseudocode
```bash
function BellmanFord(list vertices, list edges, vertex source)
   ::distance[],predecessor[]
   
   // This implementation takes in a graph, represented as
   // lists of vertices and edges, and fills two arrays
   // (distance and predecessor) with shortest-path
   // (less cost/distance/metric) information
   
   // Step 1: initialize graph
   for each vertex v in vertices:
       distance[v] := inf             // At the beginning , all vertices have a weight of infinity
       predecessor[v] := null         // And a null predecessor
   
   distance[source] := 0              // The weight is zero at the source
   
   // Step 2: relax edges repeatedly
   for i from 1 to size(vertices)-1:
       for each edge (u, v) with weight w in edges:
           if distance[u] + w < distance[v]:
               distance[v] := distance[u] + w
               predecessor[v] := u
   
   // Step 3: check for negative-weight cycles
   for each edge (u, v) with weight w in edges:
       if distance[u] + w < distance[v]:
           error "Graph contains a negative-weight cycle"
   
   return distance[], predecessor[]
```
- Time Complexity : VE

## Shortest Path Faster Algorithm

- Difference
Bellman-Ford Algorithm update for all edges, but SPFA update for changed vertex and connected edge.

- Pseudocode
```bash
procedure Shortest-Path-Faster-Algorithm(G, s)
    for each vertex v ≠ s in V(G)
        d(v) := ∞
    d(s) := 0
    offer s into Q
    while Q is not empty
        u := poll Q
        for each edge (u, v) in E(G)
            if d(u) + w(u, v) < d(v) then
                d(v) := d(u) + w(u, v)
                 if v is not in Q then
                     offer v into Q
```
- Time complexity : E or V+E

## Floyd-Warshall Algorithm
- Suitable for solving a single-sourece shortest path 
- Finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).
- Pseudocode
```bash
for i = 1 to V
   for j = 1 to V
      if there is an edge from i to j
         dist[0][i][j] = the length of the edge from i to j
      else
         dist[0][i][j] = INFINITY
  
for k = 1 to V
   for i = 1 to V
      for j = 1 to V
         dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j])
```
- Time Complexity : V<sup>3</sup>