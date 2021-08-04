#include <iostream>
using namespace std;
void Merge(int *arr, int si, int ei, int mid){
    int a[100],b[100],c[100];
    int m=0,n=0;
    for(int i=si;i<=mid;i++){
        a[m]=arr[i];
        m++;
    }
    for(int i=mid+1;i<=ei;i++){
        b[n]=arr[i];
        n++;
    }
    int j=0,k=0,l=0;
    while(j<m && k<n){
        if(a[j]<=b[k]){
            c[l]=a[j];
            l++;
            j++;
        }
        else{
            c[l]=b[k];
            l++;
            k++;
        }
    }
    if(j==m){
        while(k<=n){
            c[l]=b[k];
            l++;
            k++;
        }
    }
    else{
        while(j<=m){
            c[l]=a[j];
            l++;
            j++;
        }
    }
    int p=0;
    for(int i=si;i<=ei;i++){
        arr[i]=c[p];
        p++;
    }
}
void Split(int *arr,int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=(si+ei)/2;
    Split(arr,si,mid);
    Split(arr,mid+1,ei);
    Merge(arr,si,ei,mid);
}
void Merge_Sort(int *arr, int n){
    int si=0,ei=n-1;
    Split(arr,si,ei);
}
int main(){
    int n;
    cout<<"Bubble Sort Algorithm"<<endl;
    cout<<"Best Case Time Complexity is: O(n*logn)"<<endl;
    cout<<"Worst Case Time Complexity is: O(n*logn)"<<endl;
    cout<<"Space Complexity is: O(n)"<<endl;
    cout<<"Enter the size of an array (Total entries should not be more than 100): ";
    cin>>n;
    int *arr = new int [100];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The original array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    Merge_Sort(arr,n);
    cout<<"The sorted array in ascending order is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete arr;
}
