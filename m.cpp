#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <unordered_map>

using namespace std;

// Structure representing a metro station
struct Station
{
    string name;
    int corridor;
    vector<int> lines;
};

// Structure representing an edge between two metro stations
struct Edge
{
    string destination;
    int distance;
};

// Function to perform Dijkstra's algorithm to find the shortest path
void dijkstra(const vector<vector<Edge>> &graph, const unordered_map<string, int> &stationIndices, int source, vector<int> &distance, vector<int> &parent)
{
    int n = graph.size();
    distance.resize(n, numeric_limits<int>::max());
    parent.resize(n, -1);

    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (const Edge &edge : graph[u])
        {
            int v = stationIndices.at(edge.destination);
            int weight = edge.distance;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
}

// Function to perform a depth-first search on the metro graph
void dfs(const vector<vector<Edge>> &graph, const unordered_map<int, string> &stationNames, const unordered_map<string, int> &stationIndices, int source, vector<bool> &visited)
{
    stack<int> s;
    s.push(source);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        cout << "Station: " << stationNames.at(u) << ", Distance: " << graph[u][0].distance << endl;

        for (const Edge &edge : graph[u])
        {
            string v = edge.destination;
            s.push(stationIndices.at(v));
        }
    }
}

// Function to perform a breadth-first search on the metro graph
void bfs(const vector<vector<Edge>> &graph, const unordered_map<int, string> &stationNames, const unordered_map<string, int> &stationIndices, int source, vector<bool> &visited)
{
    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        cout << "Station: " << stationNames.at(u) << ", Distance: " << graph[u][0].distance << endl;

        for (const Edge &edge : graph[u])
        {
            string v = edge.destination;
            q.push(stationIndices.at(v));
        }
    }
}

int main()
{
    // Create the Delhi Metro graph
    vector<vector<Edge>> graph(10); // Assuming there are 10 metro stations

    // Map station names to indices for easy access
    unordered_map<string, int> stationIndices;
    unordered_map<int, string> stationNames;

    // Add station names and their corresponding indices
    stationIndices["New Delhi"] = 0;
    stationNames[0] = "New Delhi";
    stationIndices["Chandni Chowk"] = 1;
    stationNames[1] = "Chandni Chowk";
    stationIndices["Rajiv Chowk"] = 2;
    stationNames[2] = "Rajiv Chowk";
    stationIndices["Hauz Khas"] = 3;
    stationNames[3] = "Hauz Khas";
    stationIndices["Karol Bagh"] = 4;
    stationNames[4] = "Karol Bagh";

    // Add edges between the metro stations
    graph[stationIndices["New Delhi"]].push_back({"Chandni Chowk", 5});
    graph[stationIndices["New Delhi"]].push_back({"Rajiv Chowk", 10});
    graph[stationIndices["Chandni Chowk"]].push_back({"Rajiv Chowk", 6});
    graph[stationIndices["Rajiv Chowk"]].push_back({"Hauz Khas", 8});
    graph[stationIndices["Rajiv Chowk"]].push_back({"Karol Bagh", 3});
    graph[stationIndices["Hauz Khas"]].push_back({"Karol Bagh", 7});

    // Perform Dijkstra's algorithm
    vector<int> distance;
    vector<int> parent;
    string source, destination;
    cout << "Enter the source station: ";
    cin.ignore();
    getline(cin, source);
    cout << "Enter the destination station: ";
    getline(cin, destination);
    dijkstra(graph, stationIndices, stationIndices[source], distance, parent);

    // Display the shortest distance
    cout << "Shortest Distance: " << distance[stationIndices[destination]] << endl;

    // Display the metro route
    vector<bool> visited(graph.size(), false);

    // Depth-first search
    cout << "DFS Route:" << endl;
    dfs(graph, stationNames, stationIndices, stationIndices[source], visited);

    // Reset visited array
    fill(visited.begin(), visited.end(), false);

    // Breadth-first search
    cout << "BFS Route:" << endl;
    bfs(graph, stationNames, stationIndices, stationIndices[source], visited);

    return 0;
}