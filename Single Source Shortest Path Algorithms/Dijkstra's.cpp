#include<iostream>
#include<climits>
using namespace std;
// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int  minDistance(int *dist, bool *sptSet, int n){
    //Initialize the minimum value
    int minVal = INT_MAX, minIndex;
    for(int i=0;i<n;i++){
        if(sptSet[i] == false && dist[i] <= minVal){
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
// A utility function to print the constructed distance array
void printSolution(int *dist, int n){
    cout<<"Vertex \t Distance from Source: "<<endl;
    for(int i=0;i<n;i++){
        cout  << i << " \t\t"<<dist[i]<< endl;
    }
}
void dijkstras(int **adjM,int n,int source){
    // The output array.  dist[i] will hold the shortest distance from source vertex to ith vertex
    int *dist = new int [n];
    // path tree or shortest distance from source vertex to ith vertex is finalized
    //sptSet[i] will be true if vertex i is included in shortest
    bool *sptSet = new bool[n];
    //Initialize all the distance to INFINITE and stpSet[i] to false
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    //initializing the source vertex as 0
    dist[source] = 0;
    //finding the shortest path of all the vertices
    for(int i=0;i<n;i++){
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to source vertex in the first iteration.
        int u = minDistance(dist, sptSet, n);
        // Mark the picked vertex as processed
        sptSet[u] = true;
        // Update dist value of the adjacent vertices of the picked vertex.
        for(int v=0;v<n;v++){
            //Update dist[v] only if it is not in the sptSet, there is an edge from u to v, and total weight of path from src to  v through u is smaller than current value of dist[v]
            if(!sptSet[v] && adjM[u][v] && dist[u] != INT_MAX && dist[u]+adjM[u][v] < dist[v]){
                dist[v] = dist[u] + adjM[u][v];
            }
        }
    }
    // print the constructed distance array
    printSolution(dist,n);
}
int main(){
    //No of Vertices
    int n;
    cout<<"Enter the number of vertices present in the graph: ";
    cin>>n;
    //Adjacency Matrix
    int **adjM = new int *[n];
    cout<<"Enter the graph: "<<endl;
    for(int i=0;i<n;i++){
        adjM[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>adjM[i][j];
        }
    }
    int source;
    cout<<"Enter the source vertex of the graph: ";
    cin>>source;
    dijkstras(adjM,n,source);
    return 0;
}
