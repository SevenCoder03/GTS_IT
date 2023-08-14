#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Vertex {
    int id;
    int distance;

    Vertex(int id, int distance) : id(id), distance(distance) {}
};


struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};


void dijkstra(vector<vector<int>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.resize(n, INF);
    distances[start] = 0;

    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;

    pq.push(Vertex(start, 0));

    while (!pq.empty()) {
        Vertex u = pq.top();
        pq.pop();

        int uId = u.id;
        int uDistance = u.distance;

        if (uDistance > distances[uId]) {
            continue;
        }

        for (int v = 0; v < n; ++v) {
            if (graph[uId][v] != INF) {
                int newDistance = uDistance + graph[uId][v];
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    pq.push(Vertex(v, newDistance));
                }
            }
        }
    }
}

int main() {
    int n = 5;
    int start = 0;

    vector<vector<int>> graph = {
        {0, 2, INF, 1, 8},
        {2, 0, 4, INF, INF},
        {INF, 4, 0, 6, INF},
        {1, INF, 6, 0, 3},
        {8, INF, INF, 3, 0}
    };

    vector<int> distances;

    dijkstra(graph, start, distances);

    cout << "Khoang cach tu dinh " << start << " den cac dinh khac:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i << ": " << distances[i] << endl;
    }
    return 0;
}
