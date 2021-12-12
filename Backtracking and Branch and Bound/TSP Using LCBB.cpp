#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
#define n 5
#define inf INT_MAX
using namespace std;
//structure to represent state space tree nodes
struct Node{
    //helps to trace the path when the path is found
    vector <pair<int,int>> path;
    //reduced matrix
    int rm[n][n];
    //stores the lower bound - cost from home town to the last visited city
    int cost;
    //stores the current city
    int city;
    //stores the number of cities visited so far
    int level;
};
// Function to allocate a new node `(i, j)` corresponds to visiting city `j`from city `i`
Node * newNode(int pm[n][n], vector<pair<int,int>> const &path, int level, int i, int j){
    Node *node = new Node;
    //stores the ancestor edge of the state space tree
    node->path  = path;
    //skip for the root node
    if(level != 0){
        //add edge to the current path
        node->path.push_back(make_pair(i,j));
    }
    //copy the data from the parent node to the current node
    memcpy(node->rm,pm,sizeof node->rm);
    //change all the entries of row i and column j to inifiniti
    //skip for root node
    for(int k=0; level !=0 && k<n; k++){
        node->rm[i][k] = inf;
        node->rm[k][j] = inf;
    }
    node->rm[j][0] = inf;
    node->level = level;
    node->city = j;
    return node;
}
//row reduction
void row_red(int rm[n][n], int row[n]){
    //fill the row array to inifiniti
    fill_n(row,n,inf);
    // `row[i]` contains minimum in row `i`
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rm[i][j]<row[i]){
                row[i] = rm[i][j];
            }
        }
    }
    //reduce the minimum value from each element in each row
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rm[i][j] != inf && row[i] != inf){
                rm[i][j] -= row[i];
            }
        }
    }
}
//column reduction
void col_red(int rm[n][n], int col[n]){
    //initialize the column array to inifiniti
    fill_n(col,n,inf);
    // `col[j]` contains minimum in col `j`
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(rm[i][j]< col[j]){
                    col[j]=rm[i][j];
                }
        }
    }
    //reduce the minimum value from each element in each column
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(rm[i][j] != inf && col[j] != inf){
                rm[i][j] -= col[j];
            }
        }
    }
}
//printing the path
void printPath(vector <pair<int,int>> const &p){
    for(int i=0;i<p.size();i++){
        cout<<p[i].first + 1<<" -> "<<p[i].second + 1<<endl;
    }
}
//function to cal the lower bound of the path string at the current minimum node
int calCost(int rm[n][n]){
    //initial cost to zero
    int cost = 0;
    //row reduction
    int row[n];
    row_red(rm,row);
    //column reduction
    int col[n];
    col_red(rm,col);
    //cal of the cost
    for(int i=0;i<n;i++){
        cost += (row[i] != INT_MAX) ? row[i] : 0;
        cost += (col[i] != INT_MAX) ? col[i] : 0;
    }
    return cost;
}
//Comparison object to be used to order the heap
struct cmp{
    bool operator()(const Node* lhs, const Node* rhs) const{
        return lhs->cost > rhs->cost;
    }
};
//function to solve tsp using lcbb
int tsp(int cm[n][n]){
    //create the priority queue to store the live node of the search tree
    priority_queue<Node*, vector<Node*>, cmp> pq;
    vector<pair<int,int>> v;
    //create a new node and calculate its cost
    //tSp starts from the first city, i.e., node 0.
    Node *root = newNode(cm,v,0,-1,0);
    //get the lower bound of the path start from 0.
    root->cost = calCost(root->rm);
    //add root to the list of live node
    pq.push(root);
    //find the live node with least ost and ad it to the children of list of live nodes and finally deletes it from the list
    while(!pq.empty()){
        //find the live node with least cost
        Node *mini = pq.top();
        //the found node is deleted from the list
        pq.pop();
        //i stores the current city
        int i = mini->city;
        //if all the cities are visited
        if(mini->level == n-1){
            // return to the starting city
            mini->path.push_back(make_pair(i,0));
            //print the list of the cities visited
            printPath(mini->path);
            return mini->cost;
        }
        for(int j=0;j<n;j++){
                if(mini->rm[i][j] != inf){
                        //create a child node and calulate its cost
                    Node *child = newNode(mini->rm,mini->path,mini->level+1,i,j);
                    child->cost = mini->cost + mini->rm[i][j] + calCost(child->rm);
                    pq.push(child);
                }
        }
        // delete the parent node since we have already stored in the
        delete mini;
    }
    return -1;
}
int main(){
    int cost_matrix[n][n] = {
                                {inf,10,8,9,7},
                                {10,inf,10,5,6},
                                {8,10,inf,8,9},
                                {9,5,8,inf,6},
                                {7,6,9,6,inf}
                            };
    cout<<"The cost is: "<<tsp(cost_matrix)<<endl;
    return 0;
}
