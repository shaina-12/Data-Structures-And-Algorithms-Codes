//To implement BFS Traversal of a graph G
#include <iostream>
#include <list>
using namespace std;
class Graph
{
    public:
    int numV;
    list <int> *adjL;
    Graph(int numV);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v);

    // prints BFS traversal from a given source s
    void BFS(int startV);

};
Graph::Graph(int numV) {
    this->numV = numV;
    adjL = new list<int>[numV];
}
void Graph::addEdge(int u, int v) {
    adjL[u].push_back(v);
}
void Graph::BFS(int startV) {
    //Visited array is used to track whether the node is visited or not
    bool *visited = new bool [numV];
    for(int i=0;i<numV;i++) {
        visited[i] = false;
    }
    list <int> q;
    //Pushing the starting vertex into the queue
    visited[startV] = true;
    q.push_back(startV);
    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    list<int>::iterator i;
    while(!q.empty()) {
        startV = q.front();
        cout<<startV<<" ";
        q.pop_front();
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for(i=adjL[startV].begin();i!=adjL[startV].end();++i) {
            if(!visited[*i]){
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
    delete visited;
}
int main()
{
    int n;
    cout<<"Enter the number of vertices of the graph: ";
    cin>>n;
    Graph g = Graph(n);
    cout<<"Enter the edges of the graph: "<<endl;
    //int c = 1;
    while(true)
    {
        int u,v;
        cout<<"Enter the source vertex: ";
        cin>>u;
        cout<<"Enter the destination vertex: ";
        cin>>v;
        g.addEdge(u,v);
        cout<<"Do you want to add new edge (1-yes/0-no)?";
        int c;
        cin>>c;
        if(c==0){
            break;
        }
    }
    int sVertex;
    cout<<"Enter the starting vertex: ";
    cin>>sVertex;
    cout<<"BFS Traversal of a Graph G is: ";
    g.BFS(sVertex);
    return 0;
}
