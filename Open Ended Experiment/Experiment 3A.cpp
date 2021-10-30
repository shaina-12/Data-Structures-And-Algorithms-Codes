/* A road network can be considered as a graph with positive weights. The nodes represent road junctions and each edge of the graph is associated with a road segment between 
two junctions. The weight of an edge may correspond to the length of the associated road segment, the time needed to traverse the segment or the cost of traversing the segment. 
Using directed edges it is also possible to model one-way streets. Such graphs are special in the sense that some edges are more important than others for long distance travel 
(e.g. highways). This property has been formalized using the notion of highway dimension. There are a great number of algorithms that exploit this property and are therefore 
able to compute the shortest path a lot quicker than would be possible on general graphs. Develop a program to find the shortest path from each node to solve the road network 
problem */
//To implement Floyd Warshall Algorithm on a Road Network
//There are other algorithms to implement also but in this course, we are using Floyd Warshall's Algorithm.
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
class RoadNetwork{
    int junc;
    //cin>>n;
    int **road_nw;
public:
    RoadNetwork(int n){
        junc = n;
        road_nw= new int*[junc];
        for(int i=0;i<junc;i++){
                road_nw[i] = new int[junc];
                for(int j=0;j<junc;j++){
                        if(i==j){
                            road_nw[i][j]=0;
                        }
                        else{
                            road_nw[i][j] = INT_MAX;
                        }
                }
        }
    }
    void distbwJun(int u,int v, int wt){
        road_nw[u][v] = wt;
    }
    void path(int s, int d){
        int n = junc;
        int **p = new int*[n];
        for(int i=0;i<n;i++){
            p[i] = new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(road_nw[i][j]==INT_MAX || i==j){
                    p[i][j] = -1;
                }
                else{
                    p[i][j] = i;
                }
            }
        }
        /*
        cout<<"path: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<road_nw[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    if((road_nw[i][j]>(road_nw[i][k]+road_nw[k][j])) && ((road_nw[i][k]!=INT_MAX) && (road_nw[k][j]!=INT_MAX))){
                        road_nw[i][j]=road_nw[i][k]+road_nw[k][j];
                        p[i][j]=k;
                        //cout<<p[i][j]<<" ";
                    }
                    //if(road_nw[i][k] == INT_MAX )
                }
            }
            /*
            cout<<"path: "<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<p[i][j]<<" ";
            }
            cout<<endl;
            */
        }

        /*
        cout<<"path: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<"resultant cost: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<road_nw[i][j]<<" ";
            }
            cout<<endl;
        }
        vector <int> v;
        v.push_back(d);
        //cout<<"s "<<s<<endl;
        //cout<<"d "<<d<<endl;
        int node = d;
        int flag = 0;
        while(node!=s){
            int aux = p[s][node];
            if(aux == -1){
                flag=1;
                break;
            }
            v.push_back(aux);
            node = aux;
            //cout<<"aux "<<aux<<endl;
            //cout<<"node "<<node<<endl;
        }
        if(flag==1){
            if(road_nw[s][d] == INT_MAX){
            cout<<"The path does not exist"<<endl;
            }
            else{
                cout<<"The shortest path between "<<s<<" and "<<d<<" is: "<<s<<" "<<d<<endl;
                cout<<"The cost of the path is: "<<road_nw[s][d]<<endl;
            }
        }
        else{
        cout<<"The shortest path between "<<s<<" and "<<d<<" is:"<<endl;
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        int sum=0;
        for(int i=v.size()-1;i>0;i--){
            int a = v[i];
            int b = v[i-1];
            //cout<<a<<" "<<b<<endl;
            sum += road_nw[a][b];
        }
        cout<<"The cost of the path is: "<<sum<<endl;
        }
        //cout<<road_nw[n-1][n-1];
    }
    /*
    4
0
3
6
15
-9999
0
-2
-9999
-9999
-9999
0
2
1
-9999
-9999
0
0
4*/
    /*
    ~RoadNetwork(){
        for(int i=0;i<junc;i++){
            delete [] road_nw[i];
        }
        delete [] road_nw;
    }*/
};
int main(){
    int junction;
    cout<<"Enter the no of locations in a road network: ";
    cin>>junction;
    RoadNetwork r = RoadNetwork(junction);
    int n = junction;
    cout<<"Enter the weight of the each edge: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                int wt;
                cin>>wt;
                if(wt != -9999){
                    r.distbwJun(i,j,wt);
                }
        }
    }
    int source;
    int destination;
    cout<<"Enter the starting point: ";
    cin>>source;
    cout<<"Enter the destination point: ";
    cin>>destination;
    r.path(source,destination);
}
