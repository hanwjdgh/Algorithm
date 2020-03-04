# 그래프 (Graph)

## 1. 그래프

### 1. 그래프 개념과 용어 정리

- 관계 (relation)
  - 집합 A의 원소들 간의 관계 R
  - 순서쌍들의 부분집합 R ⊆ A × A = {(x, y) | ∀ x ∈ A, ∀ y ∈ A }
  - (x, y) ≠ (y, x)

- 관계의 수학적 표현
  - 순서쌍들의 집합 R ⊆ A × A
  - 행렬[matrix] = M<sub>R</sub>
  - 그래프[graph] G<sub>R</sub> = (V, E, r)
    - V : 정점(vertex, node)들의 집합
    - E : 간선(edge)들의 집합
    - r : E의 원소에 대응 되는 V의 원소의 관계, e<sub>k</sub> = (v<sub>i</sub>, v<sub>j</sub>)

- 유향/무향 그래프
  - 유향 그래프 (digraph)
    - all the edges are directed, (x, y) ≠ (y, x)
  - 무향 그래프 (undirected graph), (x, y) = (y, x)

그래프용어 및 성질에 대한 자세한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 10차시 그래프 - PDF (p.6 ~ 12) 참고

### 2. 그래프 표현

- 자료구조에 따른 성능 비교

|  | Edge List | Adjacency List | Adjacency Matrix |
|:--------|:--------:|:--------:|:--------:|
| space | n + m | n + m | n<sup>2<sup> |
| incidentEdges(v) | m | deg(v) | n |
| areAdjacent(v, w) | m | min(deg(v), deg(w)) | 1 |
| insertVertex(o) | 1 | 1 | n<sup>2</sup> |
| insertEdge(v, w, o) | 1 | 1 | 1 |
| removeVertex(v) | m | deg(v) | n<sup>2</sup> |
| removeEdge(e) | 1 | 1 |  1 |

## 2. 그래프 순회 알고리즘

### 1. Computing the transitive closure of a digraph

- Floyd-Warshall 알고리즘
  - O(n<sup>3</sup>)

### 2. Topological sorting

- A digraph admits a topological ordering if and only if it is a DAG

- O(n+m) using DFS

### 3. Depth-First Search[DFS] vs Breath-First Serach[BFS]

- DFS
  - A DFS traversal of a graph G
    - Visits all the vertices and edges of G
    - Determines whether G is connected
    - Computes the connected components of G
    - Computes a spanning forest of G

  - DFS on a graph with nvertices and medges takes O(n+ m)time

  - DFS 방식의 특성
    - DFS(G, v) visits all the vertices and edges in the connected component of v
    - The discovery edges labeled by DFS(G, v) form a spanning tree of the connected component of v
  
  - Back edge (v,w)
    - w는 v의 조상이다.

- BFS
  - A BFS traversal of a graph G
    - Visits all the vertices and edges of G
    - Determines whether G is connected
    - Computes the connected components of G
    - Computes a spanning forest of G

  - BFS on a graph with nvertices and medges takes O(n+ m)time

  - BFS 방식의 특성
    - BFS(G, s) visits all the vertices and edges of G
    - The discovery edges labeled by BFS(G, s) form a spanning tree T of G
    - For each vertex v in L

  - cross edge(v,w)
    - w는 v와 같은 레벨이거나 다음 레벨이다.

그래프 순회 알고리즘 pseudo나 진행과정에 대한 자세한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 10차시 그래프 - PDF (p.25 ~ 77) 참고

## 3. 최단 경로

- 가중치가 주어진 그래프가 주어질 때, u와 v사이의 최단 거리 경로를 구하는 것

- Dijkstra Algorithm
  - 주어진 점 u로 부터 모든 vertices 들 까지의 거리를 계산하며 진행
  
  - 가정
    - 음의 가중치가 없고 무향 그래프
  
  - O(ElogV)

- DAG-based Algorithm
  - 음의 가중치 가능
  - 위상정렬을 사용
  - O(n+m)

- All-Pair Shortest Paths
  - Floyd-Warshall, O(n<sup>3</sup>)

## 4. 최소 신장 트리

- Spanning subgraph
  - Subgraph of a graph Gcontaining all the verticesof G

- Spanning Tree
  - Spanning subgraphthat is itself a (free) tree

- Minimum spanning tree[MST]
  - Spanning tree of a weighted graph with minimumtotal edge weight

- Prim's Algorithm
  - The idea of using key values is to pick the minimum weight edge from cut.
  - O(ElogV)

- Kruskal Algorithm
  - pick the smallest weight edge that does not cause a cycle in the MST constructed so far. (Union-Find(Disjoint-set))
  - O(ElogE)

## 5. 네트워크 용량

네트워크 용량에 대한 자세한 설명은 SWEA → LEARN → Course → Programming Professional → Counting & Probability → 10차시 그래프 - PDF (p.100 ~ 114) 참고

## 6. 예제

- [4005. 비밀](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/5.%20%EA%B7%B8%EB%9E%98%ED%94%84/4005.cpp)
- [4006. 고속도로 건설 2](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/5.%20%EA%B7%B8%EB%9E%98%ED%94%84/4006.cpp)
- [4007. 간담회 참석](https://github.com/hanwjdgh/Algorithm/blob/master/SWEA/Professional/5.%20%EA%B7%B8%EB%9E%98%ED%94%84/4007.cpp)

개념에 대한 더 자세한 설명, 증명과정 및 예제와 문제에 대한 설명은 SWEA → LEARN → Course → Programming Professional → 그래프 참고
