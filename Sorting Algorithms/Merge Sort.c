# include <stdio.h>
void merge(int *arr, int si, int ei, int mid){
    int a[10],b[10],c[10];
    int m=0,n=0;
    for(int i=si;i<=mid;i++){
        a[m] = arr[i];
        m++;
    }
    for(int i=mid+1;i<=ei;i++){
        b[n] = arr[i];
        n++;
    }
    int j=0,k=0,l=0;
    while(j<m && k<n){
        if(a[j]<=b[k]){
            c[l] = a[j];
            j++;
            l++;
        }
        else{
            c[l] = b[k];
            k++;
            l++;
        }
    }
    if(j==m){
        while(k<n){
            c[l] = b[k];
            k++;
            l++;
        }
    }
    else{
        while(j<m){
            c[l] = a[j];
            j++;
            l++;
        }
    }
    int d = 0;
    for(int i=si;i<=ei;i++){
        arr[i] = c[d];
        d++;
    }
}
void helper(int *arr, int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    helper(arr,si,mid);
    helper(arr,mid+1,ei);
    merge(arr,si,ei,mid);
}
void mergeSort(int *arr, int n){
    int si = 0;
    int ei = n-1;
    helper(arr,si,ei);
}
int main(){
    int arr[10] = {2,3,0,5,2,1,9,2,6,8};
    printf("The original array is:");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    mergeSort(arr,10);
    printf("The sorted array using Merge Sort algorithm is: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}