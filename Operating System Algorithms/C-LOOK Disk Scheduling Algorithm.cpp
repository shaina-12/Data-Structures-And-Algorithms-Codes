#include <iostream>
#include <cmath>
using namespace std;
int finds(int a[],int n,int item){
    for(int i=0;i<=n;i++){
        if(a[i]==item){
            return i;
        }
    }
    return -1;
}
int main(){
    int request[51],news[51],comp,n;
    cout<<"Enter the current position of the pointer:";
    cin>>request[0];
    int cp=request[0];
    cout<<"Enter the number of pending requests:";
    cin>>n;
    cout<<"Enter the pending request entries:";
    for(int i=1;i<=n;i++){
        cin>>request[i];
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1-i;j++){
            if(request[j]>request[j+1]){
                int temp=request[j];
                request[j]=request[j+1];
                request[j+1]=temp;
            }
        }
    }
    int ind=finds(request,n,cp);
    int i=ind,j=0,pos1,pos2;
    news[0]=request[ind];
    pos1=i+1;
    pos2=i-1;
    j++;
    int ctr1=0,ctr2=0;
    for(int k=pos1;k<=n;k++){
        ctr1++;
    }
    for(int l=pos2;l>=0;l--){
        ctr2++;
    }
    if(ctr1>ctr2){
        for(int k=pos1;k<=n;k++){
            news[j]=request[k];
            j++;
        }
        for(int l=0;l<=pos2;l++){
            news[j]=request[l];
            j++;
        }
        comp=abs(cp-request[n])+(request[n]-request[0])+abs(request[0]-request[pos2]);
    }
    else{
        for(int l=pos2;l>=0;l--){
            news[j]=request[l];
            j++;
        }
        for(int k=n;k>=pos1;k--){
            news[j]=request[k];
            j++;
        }
        comp=abs(cp-request[0])+abs(request[0]-request[n])+abs(request[pos1]-request[n]);
    }
    cout<<"Pointer Movement: ";
    for(int i=0;i<j-1;i++){
        cout<<news[i]<<" -> ";
    }
    cout<<news[j-1]<<endl;
    cout<<"Total head movement: "<<comp<<" cylinders."<<endl;
}
