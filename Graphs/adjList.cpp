#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// Weighted Adjacency Matrix
class AdjList
{
private:
    vector<int> *list;
    int n;
    public:
    bool *visited;

public:
    AdjList(int n)
    {
        this->n = n;
        list = new vector<int>[n];
        visited = new bool[n];
        cout << "Graph Created!\n";
    }

    void printGraph()
    {
        cout << "Adjacency List\n";
        for (int i = 0; i < n; i++)
        {
            cout<<"Vertex "<<i<<" : ";
            for (auto j: list[i])
            {
                cout<<" -> "<<j;
            }
            cout << endl;
        }
    }

    void addEdgeUD()
    {
        int s, d, w;
        cout << "Enter Source, and Destination respectively\n";
        cin >> s >> d >> w;
        list[s].push_back(d);
        list[d].push_back(s);
        cout << "Edge Added!\n";
    }

    void addEdgeD()
    {
        int s, d, w;
        cout << "Enter Source, and Destination respectively\n";
        cin >> s >> d;
        list[s].push_back(d);
        cout << "Edge Added!\n";
    }

    void removeEdgeUD()
    {
        int s, d;
        cout << "Enter Source, and Destination respectively\n";
        cin>>s>>d;
        for(auto i = list[s].begin(); i<list[s].end() ; i++){
            if(*i==d){
                list[s].erase(i);
            }
            for(auto i = list[d].begin(); i<list[d].end() ; i++){
            if(*i==s){
                list[d].erase(i);
            }
        }
        cout << "Edge Removed!\n";
    }
    }

    void removeEdgeD()
    {
        int s, d;
        cout << "Enter Source, and Destination respectively\n";
        cin >> s >> d;
        //list[s].erase(d);
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
            for (auto i: list[vrtx])
            {
                if (!visited[i])
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
        for (auto i:list[s])
        {
            if (!visited[i])
            {
                dfs(i,visited);
            }
        }
    }

    //Finding the Minimum Spanning Tree using Prims Algorithm
    int MST(){
        vector<int>weight(n,INT_MAX); //weighing infinity
        bool checked[n]; int result = 0;
        weight[0] = 0;
        int u;
        for (int i = 0; i < n; i++)
        {
            u = -1;  //min weight vertex
            for (int j = 0; j < n; j++)
            {
             if(!checked[j] && u==-1 || weight[j]<weight[u]){
                u = j;
             }
             checked[u] = true;
             result+=weight[u];

             for (int k = 0; i < n; k++)
             {
                // if(matrix[k][u]!=-1 && !checked[k]){
                //     weight[k] = min(weight[k],matrix[u][k]);
               // }
             }
             
            }
            
        }
        return result;
        
    }

    ~AdjList()
    {
        delete[] list;
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
    AdjList graph(v);
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
                graph.dfs(s,graph.visited);
                graph.visited = new bool[false]; 
                cout<<endl;
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
            case 5:
                int s;
                cout << "Enter Source\n";
                cin >> s;
                graph.dfs(s,graph.visited);
                cout<<endl;
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