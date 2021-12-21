#include<iostream>
#include<iomanip>
using namespace std;
struct process{
    int PID;
    int bTime;
    int aTime;
    int cTime;
    int sTime;
    int tTime;
    int wTime;
};
int main(){
    process p[50];
    int n;
    cout<<"Enter the no of process: ";
    cin>>n;
    cout<<"Enter the arrival time of the processes: ";
    for(int i=0;i<n;i++){
        cin>>p[i].aTime;
    }
    cout<<"Enter the burst time of the process: ";
    for(int i=0;i<n;i++){
        cin>>p[i].bTime;
    }
    for(int i=0;i<n;i++){
        p[i].PID=i+1;
    }
    int isCompleted[50];
    for(int i=0;i<50;i++){
        isCompleted[i]=0;
    }
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
    int currTime=0;
    int compTime=0;
    int prevT=0;
    int totalTT=0;
    int totalWT=0;
    int br[50];
    int totalIT=0;
    for(int i=0;i<n;i++){
        br[i]=p[i].bTime;
    }
    while(compTime!=n){
        int idle=-1;
        int mini=10000000;
        //Checking for process for shortest burst time that are in ready queue at that time
        for(int i=0;i<n;i++){
            if(p[i].aTime<=currTime && isCompleted[i]==0){
                if(br[i]<mini){
                    mini=br[i];
                    idle=i;
                }
                if(br[i]==mini){
                    if(p[i].aTime<p[idle].aTime){
                        mini=br[i];
                        idle=i;
                    }
                }
            }
        }
        //To check whether the process is found or not
        if(idle!=-1){
            //To check whether the process arrives for the first time or not
            if(br[idle]==p[idle].bTime){
                p[idle].sTime=currTime;
                float it=p[idle].sTime-prevT;
                totalIT+=it;
            }
            br[idle]-=1;
            currTime++;
            prevT=currTime;
            if(br[idle]==0){
                p[idle].cTime=currTime;
                p[idle].tTime=p[idle].cTime-p[idle].aTime;
                p[idle].wTime=p[idle].tTime-p[idle].bTime;
                totalTT+=p[idle].tTime;
                totalWT+=p[idle].wTime;
                isCompleted[idle]=1;
                compTime++;
            }
        }
        else{
            currTime++;
        }
    }
    float avgTT=(float)totalTT/n;
    float avgWT=(float)totalWT/n;
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
    cout<<"Process"<<" "<<"Arrival Time"<<" "<<"Burst Time"<<" "<<"Turnaround Time"<<" "<<"Waiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(4)<<"P"<<i+1<<"            "<<p[i].aTime<<"            "<<p[i].bTime<<"            "<<p[i].tTime<<"            "<<p[i].wTime<<endl;
    }
    cout<<"The average turnaround time is = "<<avgTT<<endl;
    cout<<"The average waiting time is = "<<avgWT<<endl;
    return 0;
}
