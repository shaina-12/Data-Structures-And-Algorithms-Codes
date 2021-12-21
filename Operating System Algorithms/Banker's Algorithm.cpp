#include <iostream>
using namespace std;
int bankersAlgorithm(int available[1][50],int need[50][50],int nump,int numr,int a[50],int allocated[50][50]){
    int ctr=0,m=0;
    int work[1][50];
    bool finish[50];
    bool flag=false;
    for(int j=0;j<numr;j++){
        work[0][j]=available[0][j];
    }
    for(int i=0;i<nump;i++){
        finish[i]=false;
    }
    for(int k=0;k<nump;k++){
        for(int i=0;i<nump;i++){
            if(finish[i]==0){
                flag=false;
            }
            for(int j=0;j<numr;j++){
                if(need[i][j]>work[0][j]){
                    flag=true;
                }
            }
            if(flag==0 && finish[i]==0){
                for(int j=0;j<numr;j++){
                    work[0][j]+=allocated[i][j];
                }
                finish[i]=true;
                ctr++;
                a[m]=i;
                m++;
            }
        }
    }
    //cout<<ctr<<endl;
    if(ctr==nump){
        return 1;
    }
    return 0;
}
int main(){
    int nump,numr,maximum[50][50],allocated[50][50],need[50][50],available[1][50],x[50],y[50];
    char ch;
    cout<<"Enter the number of proceses: ";
    cin>>nump;
    cout<<"Enter the number of resources that each process require: ";
    cin>>numr;
    cout<<"Enter the entries of maximum requirement matrix: ";
    for(int i=0;i<nump;i++){
        for(int j=0;j<numr;j++){
                cin>>maximum[i][j];
        }
    }
    cout<<"Enter the entries of allocation matrix: ";
    for(int i=0;i<nump;i++){
        for(int j=0;j<numr;j++){
                cin>>allocated[i][j];
        }
    }
    for(int i=0;i<nump;i++){
        for(int j=0;j<numr;j++){
                need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }
    cout<<"Enter the available resources: "<<endl;
    for(int j=0;j<numr;j++){
        cin>>available[0][j];
    }
    cout<<"Allocation Matrix:"<<endl;
        for(int i=0;i<nump;i++){
            for(int j=0;j<numr;j++){
                cout<<allocated[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Maximum Requirement Matrix:"<<endl;
        for(int i=0;i<nump;i++){
            for(int j=0;j<numr;j++){
                cout<<maximum[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Need Matrix:"<<endl;
        for(int i=0;i<nump;i++){
            for(int j=0;j<numr;j++){
                cout<<need[i][j]<<" ";
            }
            cout<<endl;
        }
    int ctr=bankersAlgorithm(available,need,nump,numr,x,allocated);
    if(ctr==1){

        cout<<"The sequence is in the safe state."<<endl;
        for(int i=0;i<nump;i++){
            cout<<"P"<<x[i]+1<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"The safe sequence is not formed. The system is in deadlock state."<<endl;
        exit(0);
    }
    cout<<"Do you want to add new request (yes-y/no-n)? ";
    cin>>ch;
    if(ch=='y'){
        int request[1][50],a;
        cout<<"Enter the process number: ";
        cin>>a;
        cout<<"Enter the process request: ";
        for(int j=0;j<numr;j++){
            cin>>request[0][j];
        }
        bool flag1=false;
        for(int j=0;j<numr;j++){
            if(request[0][j]>need[a-1][j]){
                flag1=true;
            }
        }
        if(flag1){
            cout<<"The process has exceeded its maximum claim."<<endl;
            exit(0);
        }
        bool flag2=false;
        for(int j=0;j<numr;j++){
            if(request[0][j]>available[0][j]){
                flag2=true;
            }
        }
        if(flag2){
            cout<<"The process P"<<a<<"must wait, since the resources are not available."<<endl;
            exit(0);
        }
        for(int j=0;j<numr;j++){
            available[0][j]-=request[0][j];
            allocated[a-1][j]+=request[0][j];
            need[a-1][j]-=request[0][j];
        }
        int ctr1=bankersAlgorithm(available,need,nump,numr,y,allocated);
        if(ctr1==1){
            cout<<"The sequence is in the safe state."<<endl;
            for(int i=0;i<nump;i++){
                cout<<"P"<<y[i]+1<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"The safe sequence is not formed. The system is in deadlock state."<<endl;
        }
    }
    return 0;
}
