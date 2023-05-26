#include <iostream>
#include <vector>
#include <queue>
#define NUM_OF_THREADS 4

using namespace std;

void bfs(vector<vector<int>> &arr)
{
    int nodes = arr.size();
    vector<int> visited(nodes, 0);
    queue<int> q;

#pragma omp parallel for num_of_threads(NUM_OF_THREADS)
    for (int i = 1; i < nodes; i++)
    {
        int startNode = i;

        if (!visited[startNode])
        {
            visited[startNode] = 1;
            q.push(startNode);

            while (!q.empty())
            {
                int currentNode = q.front();
                cout << "currentNode: " << currentNode << " ";
                q.pop();

#pragma omp parallel for num_threads(NUM_THREADS)
                for (int j = 0; j < arr[currentNode].size(); j++)
                {
                    int node = arr[currentNode][j];
                    if (!visited[node])
                    {
#pragma omp critical
                        q.push(node);
                        visited[node] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter No. of Nodes: ";
    cin >> nodes;
    cout << "Enter No. of edges: ";
    cin >> edges;

    vector<vector<int>> arr(nodes + 1);

    while (edges--)
    {
        int u, v;
        cout << "Enter U and V: ";
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u); // We built the adjacency list for the graph
    }

    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= nodes; ++i)
    {
        cout << "Node " << i << ": ";
        for (int j = 0; j < arr[i].size(); ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    bfs(arr);

    return 0;
}
