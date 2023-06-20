#include <iostream>
#include <queue>
using namespace std;

// Weighted Adjacency Matrix
class AdjMatrix
{
private:
    int **matrix;
    int n;
    public:
    bool *visited;

public:
    AdjMatrix(int n)
    {
        this->n = n;
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        { // 0 1 2 3 4
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                i == j ? matrix[i][j] = 0 : matrix[i][j] = -1; // initializing with max weights
            }
        }
        visited = new bool[this->n];
        cout << "Graph Created!\n";
    }

    void printGraph()
    {
        cout << "Adjacency Matrix\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdgeUD()
    {
        int s, d, w;
        cout << "Enter Source, Destination, and weight respectively\n";
        cin >> s >> d >> w;
        matrix[s][d] = w;
        matrix[d][s] = w;
        cout << "Edge Added!\n";
    }

    void addEdgeD()
    {
        int s, d, w;
        cout << "Enter Source, Destination, and weight respectively\n";
        cin >> s >> d >> w;
        matrix[s][d] = w;
        cout << "Edge Added!\n";
    }

    void removeEdgeUD()
    {
        int s, d;
        cout << "Enter Source, and Destination respectively\n";
        cin >> s >> d;
        matrix[s][d] = -1;
        matrix[d][s] = -1;
        cout << "Edge Removed!\n";
    }

    void removeEdgeD()
    {
        int s, d;
        cout << "Enter Source, and Destination respectively\n";
        cin >> s >> d;
        matrix[s][d] = -1;
        cout << "Edge Removed!\n";
    }

    // Breadth First Search
    void bfs()
    {
        int s;
        cout << "Enter Source\n";
        cin >> s;
        bool visited[n];
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty())
        {
            int vrtx = q.front();
            cout << vrtx << " ";
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (matrix[vrtx][i] != -1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void dfs(int s, bool visited[])
    {
        cout << s << " ";
        visited[s] = true;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][s] != -1 && !visited[i])
            {
                dfs(i, visited);
            }
        }
    }

    ~AdjMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main()
{
    int v, ch, mode, run;
    run = 1;
    cout << "1) Directed\n2) Undirected\n";
    cin >> mode;
    cout << "Enter Number of Vertices for Graph\n";
    cin >> v;
    AdjMatrix graph(v);
    while (run)
    {
        cout << "1) Print 2) Add Edge 3) Remove Edge 4) BFS 5) DFS 0) Exit\n";
        cin >> ch;
        switch (mode)
        {
        case 1:
            switch (ch)
            {
            case 1:
                graph.printGraph();
                break;
            case 2:
                graph.addEdgeD();
                break;
            case 3:
                graph.removeEdgeD();
                break;
            case 4:
                graph.bfs();
                break;
            case 5:
                int s;
                cout << "Enter Source\n";
                cin >> s;
                graph.dfs(s, graph.visited);
                break;
             case 0:
                run = false;
                break;
            default:
                break;
            }
            break;

        case 2:
            switch (ch)
            {
            case 1:
                graph.printGraph();
                break;
            case 2:
                graph.addEdgeUD();
                break;
            case 3:
                graph.removeEdgeUD();
                break;
            case 4:
                graph.bfs();
                break;
            default:
                break;
            }
            break;

        case 0:
            run = false;
        default:
            break;
        }
    }
}