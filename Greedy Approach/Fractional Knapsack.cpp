#include <iostream>
using namespace std;
float FractionalKnapsack(float profit[],float weight[],float fraction[],float selObj[],float maxWeight,int obj){
    int i;
    float totalProfit = 0;
    for(i=0;i<obj;i++){
        if(weight[i]<maxWeight){
            totalProfit += profit[i];
            maxWeight -= weight[i];
            selObj[i] = 1;
        }
        else{
            break;
        }
    }
    if(i<obj){
        float fract = maxWeight/weight[i];
        totalProfit += (profit[i]*fract);
        maxWeight = 0;
        selObj[i] = fract;
    }
    return totalProfit;
}
int main(){
    int obj;
    float maxWeight, totalProfit;
    cout<<"Enter the no of objects to be put into the knapsack: ";
    cin>>obj;
    float *profit = new float[obj];
    float *weight = new float[obj];
    float *fraction = new float[obj];
    cout<<"Enter the weight associated with the objects: ";
    for(int i=0;i<obj;i++){
        cin>>weight[i];
    }
    cout<<"Enter the profit associated with the objects: ";
    for(int i=0;i<obj;i++){
        cin>>profit[i];
    }
    cout<<"Enter the maximum capacity of the knapsack: ";
    cin>>maxWeight;
    for(int i=0;i<obj;i++){
        fraction[i] = profit[i]/weight[i];
    }
    float *selObj = new float[obj];
    for(int i=0;i<obj;i++){
        selObj[i] = 0;
    }
    for(int i=0;i<obj-1;i++){
        for(int j=0;j<obj-1-i;j++){
            if(fraction[j]<fraction[j+1]){
                float t1 = fraction[j];
                fraction[j] = fraction[j+1];
                fraction[j+1] = t1;
                float t2 = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = t2;
                float t3 = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = t3;
            }
        }
    }
    totalProfit = FractionalKnapsack(profit,weight,fraction,selObj,maxWeight,obj);
    cout<<"Total profit in the knapsack is: "<<totalProfit<<endl;
    cout<<"The weight of the objects: ";
    for(int i=0;i<obj;i++){
        cout<<weight[i]<<" ";
    }
    cout<<endl;
    cout<<"The profit associated with the object: ";
    for(int i=0;i<obj;i++){
        cout<<profit[i]<<" ";
    }
    cout<<endl;
    cout<<"The objects selected for knapsack is: ";
    for(int i=0;i<obj;i++){
        cout<<selObj[i]<<" ";
    }
    delete profit;
    delete weight;
    delete fraction;
    delete selObj;
}
