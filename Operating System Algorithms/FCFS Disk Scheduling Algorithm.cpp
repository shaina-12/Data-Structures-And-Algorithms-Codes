#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int request[51],rcomp[50],moves=0,nr;
    cout<<"Enter the current position of the pointer:";
    cin>>request[0];
    cout<<"Enter the number of pending requests:";
    cin>>nr;
    cout<<"Enter the pending request entries:";
    for(int i=1;i<=nr;i++){
        cin>>request[i];
    }
    for(int i=1,j=i-1;i<=nr;i++,j++){
        rcomp[j]=abs(request[j]-request[i]);
        moves+=rcomp[j];
    }
    cout<<"Pointer Movement: ";
    for(int i=0;i<nr;i++){
        cout<<request[i]<<" -> ";
    }
    cout<<request[nr]<<endl;
    cout<<"Total head movement: "<<moves<<" cylinders."<<endl;
}
