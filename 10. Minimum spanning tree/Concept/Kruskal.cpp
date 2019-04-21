#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

#define V 5

using namespace std;

struct Node {
	int src, dst, weight;
};

bool operator<(Node a, Node b) {
	return (a.weight < b.weight);
}

vector <Node > v;
int parent[V];

int find(int i) {
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void union1(int i, int j) {
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	v.push_back({ 0,1,2 });
	v.push_back({ 0,3,6 });
	v.push_back({ 1,2,3 });
	v.push_back({ 1,3,8 });
	v.push_back({ 1,4,5 });
	v.push_back({ 2,4,7 });
	v.push_back({ 3,4,9 });

	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	sort(v.begin(), v.end());

	int edge_count = 0;
	for (auto n : v) {
		if (find(n.src) != find(n.dst)) {
			union1(n.src, n.dst);

			cout << "Edge " << edge_count++ << "( " << n.src << "," << n.dst << ")" << " cost : " << n.weight << "\n";
			mincost += n.weight;
		}
	}
	
	cout << "Minimum cost = " << mincost << "\n";

	return 0;
}