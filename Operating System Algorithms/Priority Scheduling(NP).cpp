#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
class NPPriority{
    int n;
    int aTime[50];
    int bTime[50];
    int cTime[50];
    int PID[50];
    int tTime[50];
    int wTime[50];
    int sTime[50];
    int priority[50];
    int totalTT;
    int totalWT;
    float avgTT;
    float avgWT;
    public:
        NPPriority(){
            totalTT=0;
            totalWT=0;
        }
        void resort(){
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-i-1;j++)
                {
                    if(PID[j]>PID[j+1])
                    {
                        int temp1=PID[j];
                        PID[j]=PID[j+1];
                        PID[j+1]=temp1;
                        int temp2=tTime[j];
                        tTime[j]=tTime[j+1];
                        tTime[j+1]=temp2;
                        int temp3=wTime[j];
                        wTime[j]=wTime[j+1];
                        wTime[j+1]=temp3;
                        int temp4=aTime[j];
                        aTime[j]=aTime[j+1];
                        aTime[j+1]=temp4;
                        int temp5=bTime[j];
                        bTime[j]=bTime[j+1];
                        bTime[j+1]=temp5;
                        int temp6=priority[j];
                        priority[j]=priority[j+1];
                        priority[j+1]=temp6;
                    }
                }
            }
        }
         void findAvgTTAndAvgWT(){
             int currTime = 0;
             int complete = 0;
             int prevTime=0;
             int isCompleted[50];
             memset(isCompleted,0,sizeof(isCompleted));
             while(complete!=n){
                int ind = -1;
                int mx = 100000;
                for(int i=0;i<n;i++){
                    if(currTime>=aTime[i] && isCompleted[i]==0){
                        if(priority[i]<mx){
                            mx=priority[i];
                            ind=i;
                        }
                        if(priority[i]==mx){
                            if(aTime[i]<aTime[ind]){
                                mx=priority[i];
                                ind=i;
                            }
                        }
                    }
                }
                if(ind!=-1){
                        sTime[ind]=currTime;
                        cTime[ind]=sTime[ind]+bTime[ind];
                        tTime[ind]=abs(cTime[ind]-aTime[ind]);
                        wTime[ind]=abs(tTime[ind]-bTime[ind]);
                        totalTT+=tTime[ind];
                        totalWT+=wTime[ind];
                        isCompleted[ind]=1;
                        complete++;
                        currTime=cTime[ind];
                        prevTime=currTime;
                }
                else{
                    currTime++;
                }
             }
             avgTT=(float)totalTT/n;
             avgWT=(float)totalWT/n;
        }
        void sorting(){
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-1-i;j++){
                    if(aTime[j]>aTime[j+1]){
                        int temp1=aTime[j];
                        aTime[j]=aTime[j+1];
                        aTime[j+1]=temp1;
                        int temp2=bTime[j];
                        bTime[j]=bTime[j+1];
                        bTime[j+1]=temp2;
                        int temp3=priority[j];
                        priority[j]=priority[j+1];
                        priority[j+1]=temp3;
                        int temp4=PID[j];
                        PID[j]=PID[j+1];
                        PID[j+1]=temp4;
                    }
                }
            }
        }
        void getData(){
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
            cout<<"Enter the priority: ";
            for(int i=0;i<n;i++){
                cin>>priority[i];
            }
            for(int i=0;i<n;i++){
                PID[i]=i+1;
            }
        }
        void showData(){
            sorting();
            findAvgTTAndAvgWT();
            resort();
            cout<<"Process"<<" "<<"Arrival Time"<<" "<<"Burst Time"<<" "<<"Priority"<<" "<<"Turnaround Time"<<" "<<"Waiting Time"<<endl;
            for(int i=0;i<n;i++){
                cout<<setw(4)<<"P"<<i+1<<"            "<<aTime[i]<<"            "<<bTime[i]<<"            "<<priority[i]<<"            "<<tTime[i]<<"            "<<wTime[i]<<endl;
            }
            cout<<"The average turnaround time is = "<<avgTT<<endl;
            cout<<"The average waiting time is = "<<avgWT<<endl;
        }
};
int main(){
    NPPriority p;
    p.getData();
    p.showData();
    return 0;
}
