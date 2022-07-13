#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Knapsack{
    int *weight;
    int *profit;
    int n; // n - total items
    int capacity;
    vector <vector<int>> arr;
    vector <int> cap; // c - total capacity
public:
    Knapsack(int N,int c){
        n = N;
        capacity = c;
        weight = new int[n];
        profit = new int[n];
    }
    void addWP(){
        for(int i=0;i<n;i++){
            cin>>weight[i];
            cin>>profit[i];
        }
    }
    void sack(vector <int> v, int po, int i,int mc){
        if(i<0){
            return;
        }
        //cout<<"index: "<<n-i+1<<" ";
        //cout<<"capacity: "<<mc<<" ";
        //cout<<"Profit: "<<po<<endl;
        if(i==0){
            if(mc<0){
                return;
            }
            else{
                if(!v.empty()){
                    arr.push_back(v);
                    cap.push_back(po);
                    //cout<<"profit: "<<po<<endl;
                }
            }
        }
        if(mc<0){
            return;
        }
        //cout<<n-i<<endl;
        v.push_back(n-i);
        sack(v,po+profit[n-i],i-1,mc-weight[n-i]);
        v.pop_back();
        sack(v,po,i-1,mc);
    }
    void calKnapsack(){
        vector <int> v;
        int po=0;
        int i = n;
        int mc = capacity;
        sack(v,po,i,mc);
        int maxProfit = cap[0];
        int ind = 0;
        for(int i=1;i<cap.size();i++){
            if(maxProfit<cap[i]){
                maxProfit = cap[i];
                ind = i;
            }
        }
        cout<<"The maximum profit is: "<<maxProfit<<endl;
        cout<<"The selected objects are (in the form of solution vector i.e I = { ";
        for(int i=0;i<n;i++){
            cout<<"I"<<i+1;
            if(i != n-1){
                cout<<", ";
            }
        }
        cout<<" }): I = { ";
        int *a = new int [n];
        for(int i=0;i<n;i++){
            a[i] = 0;
        }
        for(int i=0;i<arr[ind].size();i++){
            a[arr[ind][i]] = 1;
        }
        for(int i=0;i<n;i++){
            cout<<a[i];
            if(i!=n-1){
                cout<<", ";
            }
        }
        cout<<" }."<<endl;
        delete a;
    }
};
int main(){
    int n;
    cin>>n;
    int c;
    cin>>c;
    Knapsack k(n,c);
    k.addWP();
    k.calKnapsack();
}
