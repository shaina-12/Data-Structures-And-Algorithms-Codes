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
    int request[51],r[51],news[51],comp[51],moves=0,n;
    cout<<"Enter the current position of the pointer:";
    cin>>request[0];
    r[0]=request[0];
    cout<<"Enter the number of pending requests:";
    cin>>n;
    cout<<"Enter the pending request entries:";
    for(int i=1;i<=n;i++){
        cin>>request[i];
        r[i]=request[i];
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1-i;j++){
            if(r[j]>r[j+1]){
                int temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
    int cp=request[0];
    int ind=finds(r,n,cp);
    int i=ind,j=0,k=0,pos1,pos2;
    news[0]=r[ind];
    int pos=i;
    pos1=i+1;
    pos2=i-1;
    k++;
    while(i>0 && i<n){
        while(r[pos1]==-1){
            pos1++;
        }
        while(r[pos2]==-1){
            pos2--;
        }
        int a=abs(r[pos]-r[pos1]);
        int b=abs(r[pos]-r[pos2]);
        r[pos]=-1;
        if(a>b){
            comp[j]=b;
            j++;
            i=pos2;
        }
        else if(a<b){
            comp[j]=a;
            j++;
            i=pos1;
        }
        else{
            int p1=finds(request,n,r[pos1]);
            int p2=finds(request,n,r[pos2]);
            if(p1<p2){
                comp[j]=a;
                j++;
                i=pos1;
            }
            if(p1>p2){
                comp[j]=b;
                j++;
                i=pos2;
            }
        }
        news[k]=r[i];
        k++;
        pos=i;
        pos1=i+1;
        pos2=i-1;
    }
    if(i==0){
        int l=1;
        while(r[l]==-1){
            l++;
        }
        for(int p=l;p<=n;p++){
            news[k]=r[p];
            k++;
        }
        comp[j]=abs(r[i]-r[n]);
        j++;
    }
    else{
        int l=0;
        while(r[l]!=-1){
            l++;
        }
        for(int p=l-1;p>=0;p--){
            news[k]=r[p];
            k++;
        }
        comp[j]=abs(r[i]-r[0]);
        j++;
    }
    for(int i=0;i<j;i++){
        moves+=comp[i];
    }
    cout<<"Pointer Movement: ";
    for(int i=0;i<k-1;i++){
        cout<<news[i]<<" -> ";
    }
    cout<<news[k-1]<<endl;
    cout<<"Total head movement: "<<moves<<" cylinders."<<endl;
}
