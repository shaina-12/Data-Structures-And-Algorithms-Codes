//To implement DFS traversal in a graph G
#include <iostream>
#include <list>
#include <map>
using namespace std;
class Graph
{
    map <int,bool> visited;
    map <int,list <int>> adjL;
    public:
    // function to add an edge to graph
    void addEdge(int u, int v);

    // prints DFS traversal from a given source s
    void DFS(int startV);

};
void Graph::addEdge(int u, int v) {
    adjL[u].push_back(v);
}
void Graph::DFS(int startV) {
    //Marking the vertex as visited
    visited[startV] = true;
    //Printing of the vertex
    cout<<startV<<" ";
    // Recur for all the vertices adjacent
    // to this vertex
    list <int>::iterator i;
    for(i=adjL[startV].begin();i!=adjL[startV].end();++i) {
        if(!visited[*i]){
            DFS(*i);
        }
    }
}
int main()
{
    Graph g;
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
    cout<<"DFS Traversal of a Graph G is: ";
    g.DFS(sVertex);
    return 0;
}
