# Breadth First Search (BFS)

algorithm where you should start traversing from a selected node and traverse the graph layerwise thus exploring the neighbour nodes. You must then move towards the next-level neighbour nodes.

- Pseudocode
```bash
BFS (G, s)                   //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue,whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v  
          for all neighbours w of v in Graph G
               if w is not visited 
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
```

- Time Complexity : adjacency list V+E / adjacency matrix : V<sup>2</sup>