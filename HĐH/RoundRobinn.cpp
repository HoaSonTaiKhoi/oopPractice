#include<iostream>
#include<vector>
using namespace std;

struct Process{
    int pid;
    int burstTime;
    int waitingTime=0;
    int completeTime=0;
    int turnAroundTime=0;
};

struct Gantt{
    int pid;
    int startTime=0;
    int endTime=0;
};

void findTurnAroundTime(Process proc[], int n) {  
   for (int i = 0; i < n; i++)  
    proc[i].turnAroundTime=proc[i].waitingTime+proc[i].burstTime;
}  
void findWaitingTime(Process proc[], int n, int quantum, vector<Gantt> &list_Gantt)
{
    int rem_bt[n]; 
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] = proc[i].burstTime;
 
    int t = 0;
    while (1) 
    { 
        bool done = true; 
 
        // Traverse all processes one by one repeatedly 
        for (int i = 0 ; i < n; i++) 
        {  
            if (rem_bt[i] > 0) 
            {
                Gantt gantt;
                gantt.pid=proc[i].pid;
                gantt.startTime=t;
                done = false;
                if (rem_bt[i] > quantum) 
                {
                    t += quantum; 
                    gantt.endTime=t;
                    rem_bt[i] -= quantum;
                } 
                else
                { 
                    t = t + rem_bt[i]; 
                    gantt.endTime=t;
                    proc[i].waitingTime = t - proc[i].burstTime;
                    rem_bt[i] = 0;
                }
                list_Gantt.push_back(gantt);
            } 
        } 
 
        // If all processes are done 
        if (done == true) 
        break; 
    } 
}

void findavgTime(Process proc[], int n, int quantum) {  
   
   vector<Gantt> list_gantt;
   findWaitingTime(proc, n, quantum, list_gantt);
   findTurnAroundTime(proc, n);

    int total_waitingTime=0, total_turnAroundTime=0, total_Response_Time=0;
    cout<<"Gantt chart: \n";
   cout << "Processes " <<"StartTime"<<"\t\tEnd Time"<<endl;
   for (int i = 0; i < list_gantt.size(); i++) {    
      cout << " " << list_gantt[i].pid << "\t\t" << list_gantt[i].startTime <<"\t\t"<<list_gantt[i].endTime<<endl;
   }

    for(int i=0;  i<n; i++)
    {
        total_waitingTime += proc[i].waitingTime;  
      total_turnAroundTime += proc[i].turnAroundTime;
    }
   cout << "\nAverage waiting time = " << (float)total_waitingTime / (float)n;
   cout << "\nAverage turn around time = " << (float)total_turnAroundTime / (float)n<<endl;  
}  

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int quantum;
    cout<<"Enter the quantum time: ";
    cin>>quantum;

    Process proc[n];

    for(int i=0;i<n;i++){
        cout<<"ProcessName BurstTime"<<i+1<<": ";
        cin>>proc[i].pid>>proc[i].burstTime;
    }

    findavgTime(proc, n, quantum);
    return 0;
}
