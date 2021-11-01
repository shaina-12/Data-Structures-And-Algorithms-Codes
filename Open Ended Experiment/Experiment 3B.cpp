//To implement TSP using hamiltonian cycle approach.
//Here, we are taking undirected weighted graph for it.
//Here, we are using 0th vertex as the source vertex.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool hasCycle;
vector <vector<int>> permu;
/*
0 10 15 -9999
10 0 35 25
15 35 0 30
-9999 25 30 0*/
bool isSafe(int v, int **g, vector<int> path, int pos)
{
    if (g[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
void FindHamCycle(int **g, int pos, vector<int> path, bool *visited, int n)
{
    if (pos == n) {
        if (g[path[path.size() - 1]][path[0]] != 0) {

            path.push_back(0);
            /*
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }*/
            permu.push_back(path);
            //cout << endl;
            path.pop_back();
            hasCycle = true;
        }
        return;
    }
    for (int v = 0; v < n; v++) {
        if (isSafe(v, g, path, pos) && !visited[v]) {
            path.push_back(v);
            visited[v] = true;
            FindHamCycle(g, pos + 1, path, visited, n);
            visited[v] = false;
            path.pop_back();
        }
    }
}
void hamCycle(int **g, int n)
{
    hasCycle = false;
    vector<int> path;
    path.push_back(0);
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[0] = true;
    FindHamCycle(g, 1, path, visited, n);
    if (!hasCycle) {
        //cout << "No Hamiltonian Cycle is possible " << endl;
        return;
    }
}
int main(){
    int n;
    cout<<"Enter the no of vertices present in the graph: ";
    cin>>n;
    cout<<"Enter the graph: "<<endl;
    int **graph= new int*[n];
        for(int i=0;i<n;i++){
                graph[i] = new int[n];
                for(int j=0;j<n;j++){
                        if(i==j){
                            graph[i][j]=0;
                        }
                        else{
                            graph[i][j] = INT_MAX;
                        }
                }
        }
    int **g = new int*[n];
    for(int i=0;i<n;i++){
        g[i] = new int[n];
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                int wt;
                cin>>wt;
                if(wt != -9999){
                    graph[i][j]=wt;
                    g[i][j]=1;
                }
        }
    }
    hamCycle(g,n);
    if(!hasCycle){
        cout<<"Since no hamiltonian cycle exists so,solution could not be figured."<<endl;
    }
    else{
        /*
        for(int i=0;i<permu.size();i++){
            for(int j=0;j<n+1;j++){
                    cout<<permu[i][j]<<" ";
            }
            cout<<endl;
        }*/
        vector <int> costs;
        for(int i=0;i<permu.size();i++){
            int sum = 0;
            for(int j=0;j<n;j++){
            int a = permu[i][j];
            int b = permu[i][j+1];
            //cout<<a<<" "<<b<<endl;
            //cout<<"g"<<graph[a][b]<<" ";//<<endl;
            sum += graph[a][b];
        }
        costs.push_back(sum);
        //cout<<endl;
        //cout<<sum<<" ";
        }
        //cout<<endl;
        int ind = 0;
        int ele = costs[0];
        for(int i=1;i<costs.size();i++){
            if(ele>costs[i]){
                ele = costs[i];
                ind = i;
            }
        }
        cout<<"The shortest path is: "<<endl;
        vector <int> tsp_path = permu[ind];
        for(int i=0;i<n+1;i++){
            cout<<tsp_path[i]<<" ";
        }
        cout<<endl;
        cout<<"The cost is: "<<ele<<endl;
    }
}
