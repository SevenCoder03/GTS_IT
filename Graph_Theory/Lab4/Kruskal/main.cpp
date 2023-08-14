#include <bits/stdc++.h>
using namespace std;
int label[] = {1, 2, 3, 4, 5, 6};
class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph {
    vector <vector<int>> edgelist;
    int V;
public:
    Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w) {
        edgelist.push_back({ w, x, y });
    }

    void kruskals_mst() {
        sort(edgelist.begin(), edgelist.end());
        DSU s(V+1);
        int ans = 0;
        cout << "Edge \tWeight\n";
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << label[x-1] << "-->" << label[y-1] << " \t" << w << endl;
            }
        }
        cout << "Total weight of minimum spanning tree: " << ans;
    }
};

int main() {
    Graph g(6);
    g.addEdge(1, 6, 1);
    g.addEdge(2, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(4, 5, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(3, 5, 5);
    g.kruskals_mst();

    return 0;
}
