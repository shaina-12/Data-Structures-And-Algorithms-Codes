//To implement 0/1 Knapsack problem
#include<iostream>
#include<algorithm>
using namespace std;
class Items{
public:
    int weight, profit;
    Items(){
        this->weight = 0;
        this->profit = 0;
    }
};
bool cmp(Items a, Items b){
    return  a.weight<b.weight;
}
int Knapsack(Items I[],int maxWeight,int obj){
    //int totalProfit = 0;
    int m = obj, n = maxWeight;
    int **ans = new int *[m+1];
    for(int i=0;i<=m;i++){
        ans[i] = new int [n+1];
    }
    for(int i=0;i<=m;i++){
        ans[i][0] = 0;
    }
    for(int j=1;j<=n;j++){
        ans[0][j] = 0;
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if (i==0 || j==0){
                ans[i][j] = 0;
            }
            else if (I[i-1].weight<=j){
                ans[i][j] = max(I[i-1].profit+ans[i-1][j-I[i-1].weight],ans[i-1][j]);
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }
    return ans[m][n];
}
int main(){
    int obj;
    int maxWeight, totalProfit;
    cout<<"Enter the no of objects to be put into the knapsack: ";
    cin>>obj;
    //int *profit = new int[obj];
    //int *weight = new int[obj];
    Items *I= new Items [obj];
    cout<<"Enter the weight associated with the objects: ";
    for(int i=0;i<obj;i++){
        cin>>I[i].weight;
    }
    cout<<"Enter the profit associated with the objects: ";
    for(int i=0;i<obj;i++){
        cin>>I[i].profit;
    }
    //int *buf = new int buf[obj];
    cout<<"Enter the maximum capacity of the knapsack: ";
    cin>>maxWeight;
    //int *selObj = new int[obj];
    //for(int i=0;i<obj;i++){
    //    selObj[i] = 0;
    //}
    sort(I,I+obj,cmp);
    totalProfit = Knapsack(I,maxWeight,obj);
    cout<<"Total profit in the knapsack is: "<<totalProfit<<endl;
    //cout<<"The objects selected for knapsack is: ";
    //for(int i=0;i<obj;i++){
    //    cout<<selObj[i]<<" ";
    //}
    delete I;
    //delete profit;
    //delete weight;
    //delete selObj;
}
