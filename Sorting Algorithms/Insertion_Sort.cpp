#include <iostream>
#include <ctime>
using namespace std;
int pass=0,comp=0,swaps=0;
void Insertion_Sort(int *a, int n){
    for(int i=1;i<n;i++){
        pass++;
        int temp = a[i];
        int j = i-1;
        while(j>=0){
            comp++;
            if(temp<a[j]){
                a[j+1]=a[j];
                swaps++;
            }
            else{
                break;
            }
            j--;
        }
        a[j+1]=temp;
    }
}
int main(){
    int n;
    clock_t s,f;
    cout<<"Insertion Sort Algorithm"<<endl;
    cout<<"Best Case Time Complexity is: O(n)"<<endl;
    cout<<"Worst Case Time Complexity is: O(n^2)"<<endl;
    cout<<"Space Complexity is: O(n)"<<endl;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int *arr = new int [100];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];//=rand()%100;
    }
    cout<<"The original array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    s=clock();
    //cout<<s;
    Insertion_Sort(arr,n);
    f=clock();
    //cout<<" "<<f<<endl;
    cout<<"The sorted array in ascending order is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"No of passes is: "<<pass<<endl;
    cout<<"No of comparisons is: "<<comp<<endl;
    cout<<"No of swaps is: "<<swaps<<endl;
    //cout<<"The time required for insertion sort is: "<< ((double)(f-s))/CLOCKS_PER_SEC <<" seconds."<<endl;
    delete arr;
}
