#include <iostream>
using namespace std;
int Pivot(int *arr, int si, int ei){
    int x = arr[si];
    int c = 0;
    for(int i=si+1; i<=ei; i++){
        if(x>=arr[i]){
            c++;
        }
    }
    int p = si+c;
    int temp = arr[si];
    arr[si] = arr[p];
    arr[p] = temp;
    int i = si, j = ei;
    while(i<p && j>p){
        if(arr[i] <= x){
            i++;
        }
        else if(arr[j] > x){
            j--;
        }
        else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return p;
}
void Quick(int *arr, int si, int ei){
    if(si >= ei){
       return;
    }
    int c = Pivot(arr,si,ei);
    Quick(arr,si,c-1);
    Quick(arr,c+1,ei);
}
void Quick_Sort(int * arr, int n){
    int si = 0, ei = n-1;
    Quick(arr,si,ei);
}
int main(){
    int n;
    cout<<"Quick Sort Algorithm"<<endl;
    cout<<"Best Case Time Complexity is: O(n*logn)"<<endl;
    cout<<"Worst Case Time Complexity is: O(n^2)"<<endl;
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
    Quick_Sort(arr,n);
    cout<<"The sorted array in ascending order is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete arr;
}
