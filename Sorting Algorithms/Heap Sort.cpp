#include<iostream>
using namespace std;
//maintaining of a heap
void maxHeapify(int *a, int i, int hSize){
    int l = (2*i)+1;
    int r = (2*i)+2;
    int largest = i;
    if(l<hSize && a[l]>a[largest]){
        largest = l;
    }
    if(r<hSize && a[r]>a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i],a[largest]);
        maxHeapify(a,largest,hSize);
    }
}
//building a heap
void buildMaxHeap(int *a, int n){
    int hSize = n;
    for(int i=(n/2)-1;i>=0;i--){
        maxHeapify(a,i,hSize);
    }
}
//driver code for heap sort
void heapSort(int *a,int n){
    buildMaxHeap(a,n);
    int hSize = n;
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        hSize -= 1;
        maxHeapify(a,0,hSize);
    }
}
int main(){
    int n;
    cin>>n;
    int *a = new int [n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapSort(a,n);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
