#include<iostream>
#include<iomanip>
#include<queue>
#include<algorithm>
using namespace std;
struct Process{
    int PID;
    float aTime;
    float bTime;
    float cTime;
    float sTime;
    float tTime;
    float wTime;
};
void resort(Process p[50],int n){
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].PID>p[j+1].PID)
            {
                int temp1=p[j].PID;
                p[j].PID=p[j+1].PID;
                p[j+1].PID=temp1;
                int temp2=p[j].tTime;
                p[j].tTime=p[j+1].tTime;
                p[j+1].tTime=temp2;
                int temp3=p[j].wTime;
                p[j].wTime=p[j+1].wTime;
                p[j+1].wTime=temp3;
                int temp4=p[j].aTime;
                p[j].aTime=p[j+1].aTime;
                p[j+1].aTime=temp4;
                int temp5=p[j].bTime;
                p[j].bTime=p[j+1].bTime;
                p[j+1].bTime=temp5;
            }
        }
    }
}
void sorting(Process p[50],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j].aTime>p[j+1].aTime){
                int temp1=p[j].aTime;
                p[j].aTime=p[j+1].aTime;
                p[j+1].aTime=temp1;
                int temp2=p[j].bTime;
                p[j].bTime=p[j+1].bTime;
                p[j+1].bTime=temp2;
                int temp3=p[j].PID;
                p[j].PID=p[j+1].PID;
                p[j+1].PID=temp3;
            }
        }
    }
}
void findAvgTime(Process p[50],int n,float tq){
    queue <int> q;
    float br[50];
    int complete=0;
    float curr=0;
    int mark[50];
    for(int i=0;i<50;i++){
        mark[i]=0;
    }
    sorting(p,n);
    for(int i=0;i<n;i++){
        br[i]=p[i].bTime;
    }
    float totalTT=0;
    float totalWT=0;
    float totalIT=0;
    q.push(0);
    int ind=0;
    mark[0]=0;
    while(complete!=n){
        ind=q.front();
        q.pop();
        if(br[ind]==p[ind].bTime){
            p[ind].sTime=max(curr,p[ind].aTime);
            totalIT+=(p[ind].sTime-curr);
            curr=p[ind].sTime;
        }
        if((br[ind]-tq)>0){
            br[ind]-=tq;
            curr+=tq;
        }
        else{
            curr+=br[ind];
            br[ind]=0;
            complete++;
            p[ind].cTime=curr;
            p[ind].tTime=p[ind].cTime-p[ind].aTime;
            p[ind].wTime=p[ind].tTime-p[ind].bTime;
            totalTT+=p[ind].tTime;
            totalWT+=p[ind].wTime;
        }
        for(int i=1;i<n;i++){
            if(br[i]>0 && p[i].aTime<=curr && mark[i]==0){
                q.push(i);
                mark[i]=1;
            }
        }
        if(br[ind]>0){
            q.push(ind);
        }
        if(q.empty()){
            for(int i=1;i<n;i++){
                if(br[i]>0){
                    q.push(i);
                }
            }
        }
    }
    float avgTT=totalTT/n;
    float avgWT=totalWT/n;
    resort(p,n);
    cout<<"Process"<<" "<<"Arrival Time"<<" "<<"Burst Time"<<" "<<"Turnaround Time"<<" "<<"Waiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(4)<<"P"<<i+1<<"            "<<p[i].aTime<<"            "<<p[i].bTime<<"            "<<p[i].tTime<<"            "<<p[i].wTime<<endl;
    }
    cout<<"The average turnaround time is = "<<avgTT<<endl;
    cout<<"The average waiting time is = "<<avgWT<<endl;
}
int main(){
    Process p[50];
    int n;
    float tq;
    cout<<"Enter the no of processes: ";
    cin>>n;
    cout<<"Enter the arrival time: ";
    for(int i=0;i<n;i++){
        cin>>p[i].aTime;
    }
    cout<<"Enter the burst time: ";
    for(int i=0;i<n;i++){
        cin>>p[i].bTime;
    }
    cout<<"Enter the time quantum: ";
    cin>>tq;
    for(int i=0;i<n;i++){
        p[i].PID=i+1;
    }
    findAvgTime(p,n,tq);
    return 0;
}
