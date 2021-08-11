#include <iostream>
using namespace std;
int pass=0, comp=0, swaps=0;
void Bubble_Sort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        pass++;
        cout<<"The array after pass "<<i+1<<" is: ";
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Bubble Sort Algorithm"<<endl;
    cout<<"Best Case Time Complexity is: O(n)"<<endl;
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
    Bubble_Sort(arr,n);
    cout<<"The sorted array in ascending order is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"No of passes is: "<<pass<<endl;
    cout<<"No of comparisons is: "<<comp<<endl;
    cout<<"No of swaps is: "<<swaps<<endl;
    delete arr;
}
