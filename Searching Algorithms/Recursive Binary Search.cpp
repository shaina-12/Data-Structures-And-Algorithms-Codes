#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
int helper(int a[],int si,int ei,int item){
    int ind = -1;
    if(si > ei){
        return ind;
    }
    int mid = (si+ei)/2;
    if(a[mid] == item){
        return mid;
    }
    else if(a[mid] > item){
        ind = helper(a,si,mid-1,item);
    }
    else{
        ind = helper(a,mid+1,ei,item);
    }
    return ind;
}
int recursiveBinarySearch(int a[],int n,int item){
    int si = 0;
    int ei = n-1;
    int ind = helper(a,si,ei,item);
    return ind;
}
int main(){
    int n;
    cout<<"Recursive Binary Search Algorithm"<<endl;
    cout<<"Worst Case Time Complexity is O(lgn)"<<endl;
    cout<<"Best Case Time Complexity is O(1)"<<endl;
    cout<<"Space complexity is O(1)"<<endl;
    cout<<"Enter the array limit: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    int *a = new int[n];
    for (int i=0;i<n;i++){
        a[i] = rand()%100;
    }
    int item;
    /*for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }*/
    cout<<"Enter the item to be searched: ";
    cin>>item;
    sort(a,a+n);
    //int m = n/2;
    //item = rand()%100;
    //cout<<item<<endl;
    //auto s = high_resolution_clock::now();
    int index = recursiveBinarySearch(a,n,item);
    //auto f = high_resolution_clock::now();
    if(index != -1){
        cout<<"The element is found in the array at: "<<index<<".";
    }
    else{
        cout<<"The element is not found in the array";
    }
    //auto duration = duration_cast<nanoseconds>(f-s);
    //cout<<"The time required : "<< duration.count()<<" nanosecondsseconds."<<endl;
    delete a;
}
