#include<iostream>
using namespace std;

struct Process{
    int pid;
    int arrTime;
    int burstTime;
    int responseTime=0;
    int waitingTime=0;
    int completeTime=0;
    int turnAroundTime=0;
};

void findTurnAroundTime(Process proc[], int n) {  
   for (int i = 0; i < n; i++)  
    proc[i].turnAroundTime=proc[i].waitingTime+proc[i].burstTime;
}  
void findWaitingTime(Process proc[], int n)
{
    int restTime[n];
    bool callfirsttime[n]={};
    for (int i=0; i<n; i++)
    {
        restTime[i]=proc[i].burstTime;
    }

    //
    int num_complete=0, t=0, min=INT_MAX;
    int shortestIndex=0, finishTime;

    bool check=false;

    while(num_complete!=n)
    {
        //Tìm cái restTime nhỏ nhất
        for (int i = 0; i < n; i++) {  
         if ((proc[i].arrTime <= t) && (restTime[i] < min) && restTime[i] > 0) {  
            min= restTime[i];  
            shortestIndex =i;
            check = true;
         }
        }
        // Response time
        if(callfirsttime[shortestIndex]==false)
            {
                proc[shortestIndex].responseTime=t-proc[shortestIndex].arrTime;
                callfirsttime[shortestIndex]=true;
            }

        if (check == false) {  
         t++;
         continue;  
        }

        restTime[shortestIndex]--;
        
        if(restTime[shortestIndex]==0)
        {
            min=INT_MAX;
            num_complete++;  
            check = false;  
            finishTime = t + 1;  
            proc[shortestIndex].completeTime=finishTime;
            
            // Calculate waiting time  
            proc[shortestIndex].waitingTime = finishTime -  
            proc[shortestIndex].burstTime -  
            proc[shortestIndex].arrTime;  

            

            if (proc[shortestIndex].waitingTime < 0)  
               proc[shortestIndex].waitingTime = 0;
        }
        t++;
    }
}

void findavgTime(Process proc[], int n) {  
   
   findWaitingTime(proc, n);
   findTurnAroundTime(proc, n);

    int total_waitingTime=0, total_turnAroundTime=0, total_Response_Time=0;
   cout << "Processes " <<" Arrival Time "<< " Burst time " <<" Response Time "<< "    Waiting time " << " Turn around time\n";  
   for (int i = 0; i < n; i++) {  
      total_Response_Time +=proc[i].responseTime;
      total_waitingTime += proc[i].waitingTime;  
      total_turnAroundTime += proc[i].turnAroundTime;  
      cout << " " << proc[i].pid << "\t\t" << proc[i].arrTime << "\t\t " << proc[i].burstTime <<"\t\t"<<proc[i].responseTime <<"\t\t " << proc[i].waitingTime <<"\t\t"<< proc[i].turnAroundTime << endl;  
   }  
   cout<<"\nAverage response time = "<<(float)total_Response_Time/(float)n;
   cout << "\nAverage waiting time = " << (float)total_waitingTime / (float)n; cout << "\nAverage turn around time = " << (float)total_turnAroundTime / (float)n;  
}  

int main()
{
    int n;
    cout<<"Nhập số tiến trình ";
    cin>>n;
    Process proc[n];
    for(int i=0;i<n;i++){
        cout<<"PID ArrivalTime BurstTime"<<i+1<<": ";
        cin>>proc[i].pid>>proc[i].arrTime>>proc[i].burstTime;
    }
    findavgTime(proc, n);
    return 0;
}