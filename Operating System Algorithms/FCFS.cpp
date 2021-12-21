#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void resort(float aTime[50],float bTime[50],float tTime[50],float wTime[50],int info[50],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(info[j]>info[j+1])
            {
                int temp1=info[j];
                info[j]=info[j+1];
                info[j+1]=temp1;
                float temp2=tTime[j];
                tTime[j]=tTime[j+1];
                tTime[j+1]=temp2;
                float temp3=wTime[j];
                wTime[j]=wTime[j+1];
                wTime[j+1]=temp3;
                float temp4=aTime[j];
                aTime[j]=aTime[j+1];
                aTime[j+1]=temp4;
                float temp5=bTime[j];
                bTime[j]=bTime[j+1];
                bTime[j+1]=temp5;
            }
        }
    }
}
void bandwTime(float aTime[50],float bTime[50],float wTime[50],float tTime[50],float gcTime[2][102],int n,int m){
    int i=0,k=0;
    float extra[50];
    while(i<n && k<m){
        if(gcTime[1][k]==0){
            extra[i]=gcTime[0][k+1];
            i++;
            k+=2;
        }
        else{
            extra[i]=gcTime[0][k];
            i++;
            k++;
        }
    }
    for(int i=0;i<n;i++){
        tTime[i]=abs(extra[i]-aTime[i]);
        wTime[i]=abs(tTime[i]-bTime[i]);
    }
}
int gangChart(float gcTime[2][102],float bTime[50],float aTime[50],int PID[50],int n)
{
    int i=0,k=0;
    if(aTime[0]!=0){
        gcTime[0][0]=aTime[0];
        gcTime[1][0]=0;
        gcTime[0][1]=gcTime[0][0]+bTime[0];
        gcTime[1][1]=PID[0];
        i++;
        k+=2;
    }
    else{
        gcTime[0][0]=bTime[0];
        gcTime[1][0]=PID[0];
        i++;
        k++;
    }
    while(i<n){
        if(gcTime[0][k-1]<aTime[i]){
            float IT=aTime[i]-gcTime[0][k-1];
            gcTime[0][k]=gcTime[0][k-1]+IT;
            gcTime[1][k]=0;
            k++;
        }
        gcTime[0][k]=gcTime[0][k-1]+bTime[i];
        gcTime[1][k]=PID[i];
        i++;
        k++;
    }
    return k;
}
void sorting(float aTime[50],float bTime[50],int PID[50],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(aTime[j]>aTime[j+1])
            {
                float temp1=aTime[j];
                aTime[j]=aTime[j+1];
                aTime[j+1]=temp1;
                float temp2=bTime[j];
                bTime[j]=bTime[j+1];
                bTime[j+1]=temp2;
                int temp3=PID[j];
                PID[j]=PID[j+1];
                PID[j+1]=temp3;
            }
        }
    }
}
int main(){
    float aTime[50],bTime[50],wTime[50],tTime[50],gcTime[2][102];
    int n,PID[50];
    cout<<"Enter the no of processes: ";
    cin>>n;
    cout<<"Enter the burst time: ";
    for(int i=0;i<n;i++){
        cin>>bTime[i];
    }
    cout<<"Enter the arrival time: ";
    for(int i=0;i<n;i++){
        cin>>aTime[i];
    }
    for(int i=0;i<n;i++){
        PID[i]=i+1;
    }
    sorting(aTime,bTime,PID,n);
    int m=gangChart(gcTime,bTime,aTime,PID,n);
    bandwTime(aTime,bTime,wTime,tTime,gcTime,n,m);
    float sum1=0,sum2=0,avgTT,avgWT;
    for(int i=0;i<n;i++){
        sum1+=tTime[i];
        sum2+=wTime[i];
    }
    avgTT=sum1/n;
    avgWT=sum2/n;
    int info[50];
    int i=0,k=0;
    while(i<n){
        if(gcTime[1][k]==0){
            k++;
        }
        info[i]=gcTime[1][k];
        i++;
        k++;
    }
    resort(aTime,bTime,tTime,wTime,info,n);
    cout<<"Process"<<" "<<"Arrival Time"<<" "<<"Burst Time"<<" "<<"Turnaround Time"<<" "<<"Waiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(4)<<"P"<<i+1<<"            "<<aTime[i]<<"            "<<bTime[i]<<"            "<<tTime[i]<<"            "<<wTime[i]<<endl;
    }
    cout<<"The average turnaround time is = "<<avgTT<<endl;
    cout<<"The average waiting time is = "<<avgWT<<endl;
    return 0;
}
