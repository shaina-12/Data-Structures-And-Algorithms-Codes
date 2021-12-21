#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//DSU data structure
//path compression + rank by union
class DSU{
    int *parent;
    int *rank;
public:
    DSU(int n){
        parent = new int[n];
        rank = new int [n];
        for(int i=0;i<n;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    //find function - used for cycle detection so that there will be no cycles in the result
    int find(int i){
        if(parent[i] == -1){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    //union function - for further calculation of MST
    int unite(int u, int v){
        int s1 = find(u);
        int s2 = find(v);
        if(s1!=s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
class Graph{
    //represents edge list
    vector<vector<int>> edgelist;
    //no of vertices of a graph
    int numV;
public:
    Graph(int numV){
        this->numV = numV;
    }
    //add the edges and their weights in the edge list
    void addEdge(int u, int v,int cost){
        edgelist.push_back({u,v,cost});
    }
    //main function to find out the MST
    int kruskalsMST(){
        //1. sort all the edges
        sort(edgelist.begin(),edgelist.end());
        //initialize the DSU
        DSU s(numV);
        int ans = 0;
        cout<<"Edge\tWeight\n";
        for(auto edge : edgelist){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            //take the edge of MST if it does not form a cycle
            if(s.find(u) != s.find(v)){
                s.unite(u,v);
                cout<<u<<" - "<<v<<" \t"<<cost<<" \n";
                ans += cost;
            }
        }
        return ans;
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    int cost = g.kruskalsMST();
    cout<<"The cost of MST is: "<<cost<<endl;
}
