# include <stdio.h>
void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr[10] = {2,3,0,5,2,1,9,2,6,8};
    printf("The original array is:");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    bubbleSort(arr,10);
    printf("The sorted array using Bubble Sort algorithm is: ");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}