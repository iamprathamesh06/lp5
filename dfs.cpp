#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void dfs(int startNode, vector<vector<int>> &arr, vector<bool> &visited)
{
    cout << "current node: " << startNode << " ";
    visited[startNode] = true;
    for (int i = 0; i < arr[startNode].size(); i++)
    {
        int node = arr[startNode][i];
        if (!visited[node])
        {
            dfs(node, arr, visited);
        }
    }
}

int main()
{

    int nodes, edges;
    cout << "Enter number of nodes" << endl;
    cin >> nodes;
    cout << "Enter number of edges" << endl;
    cin >> edges;

    vector<vector<int>> arr(nodes + 1);

    while (edges--)
    {
        int u, v;
        cout << "Enter u and v" << endl;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<bool> visited(nodes + 1, false);

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, arr, visited);
        }
    }

    return 0;
}