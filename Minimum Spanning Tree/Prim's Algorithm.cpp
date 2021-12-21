#include <iostream>
#include <algorithm>
#include <climits>
#define n 5
using namespace std;
//utility function to find out the vertex with minimum key value, from the set of vertices that are not included in MST
int findMinVertex(int key[n], bool visited[n]){
    int mini = INT_MAX, minIndex;
    for(int i=0;i<n;i++){
        if(!visited[i] && key[i]<mini){
            mini = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
//to print the MST
void printMST(int parent[n], int adj[n][n]){
    cout<<"Edge\tWeight\n";
    int cost = 0;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<adj[i][parent[i]]<<" \n";
        cost += adj[i][parent[i]];
    }
    cout<<"The cost of MST is: "<<cost;
}
void primsMST(int adj[n][n]){
    //to track for visited vertex
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[n] = false;
    }
    //array to store constructed MST
    int parent[n];
    //key is used to store the minimum edge of MST
    int key[n];
    //initializing all the vertices as infiniti except the source vertex
    for(int i=0;i<n;i++){
        key[i] = INT_MAX;
    }
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; //First node is always root of MST
    // The MST will have n vertices
    for(int i=0;i<n-1;i++){
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int v = findMinVertex(key,visited);
        // Add the picked vertex to the MST Set
        visited[v] = true;
        //update the key value and parent index of the adjacent vertices of the picked vertex.
        //consider only those vertices which are not yet included in MST
        for(int j=0;j<n;j++){
            //adj[v][j] should be non zero for adjacent vertices of m
            //visited[v] is false for vetices that are not included in MST
            //update the key only if adj[v][j] is smaller than key[v]
            if(adj[v][j] && !visited[j] && adj[v][j] < key[j]){
                parent[j] = v;
                key[j] = adj[v][j];
            }
        }
    }
    //print the constructed MST
        printMST(parent,adj);
}
int main(){
    int adj[n][n] = {{0,4,8,0,0},
                     {4,0,2,6,0},
                     {8,2,0,3,9},
                     {0,6,3,0,5},
                     {0,0,9,5,0}};
    /*
    int adj[n][n] = { { 0, 2, 0, 6, 0 },
                      { 2, 0, 3, 8, 5 },
                      { 0, 3, 0, 0, 7 },
                      { 6, 8, 0, 0, 9 },
                      { 0, 5, 7, 9, 0 } };
    */
    primsMST(adj);
}
