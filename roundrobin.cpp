#include <iostream>
#define quantum 20
using namespace std;

class process{
    public:
    int process_no;
    int burst_time;

    int start_time=0;
    int end_time=0;
    int bbt;

    int completion_time;
    int Overall_time;
    int waiting_time=0;

};


int main(){
    process p[5];
    int n;
    int pr;
    int clock=0;
    int average_completion=0;
    int average_overall = 0;
    int average_waiting =0;
cout<<"Enter no of process(should be < =5) :"<<endl;
cin>> n;
pr=n;
for (int i = 0; i < n; i++)
{
    int BT;
    p[i].process_no=i+1;
    cout<<"enter burst time for process "<<i+1<<" :";
    cin>>BT;
    p[i].burst_time=BT;
    p[i].bbt = BT;
}


while (pr!=0)
{
    for(int i=0;i<n;i++)
    {
        if (p[i].bbt!=0)
        {
            if (p[i].bbt>quantum)
            {
                p[i].start_time=clock;
                clock= clock+ quantum;
                p[i].waiting_time=p[i].waiting_time+(p[i].start_time-p[i].end_time);
                p[i].end_time=clock;
                p[i].bbt = p[i].bbt - quantum;
            }
            else
            {
                p[i].start_time = clock;
                clock = clock + p[i].bbt;
                p[i].waiting_time = p[i].waiting_time+(p[i].start_time-p[i].end_time);
                p[i].end_time=clock;
                p[i].bbt=0;
                pr-=1;
            }
            

        }
        
    }
}
cout<<"process"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"wt"<<"\t"<<"Ot"<<"\t"<<endl;

for (int i = 0; i < n; i++)
{   
    p[i].completion_time=p[i].end_time; 
    p[i].Overall_time = p[i].burst_time +p[i].waiting_time;
    average_completion = average_completion + p[i].completion_time;
    average_overall = average_overall + p[i].Overall_time;
    average_waiting = average_waiting + p[i].waiting_time;
    cout<<p[i].process_no<<"\t"<<p[i].burst_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].Overall_time<<"\t"<<endl;
}
average_waiting = average_waiting/n;
average_completion = average_completion/n;
average_overall = average_overall/n;
cout<<"The average waiting time is :"<<average_waiting<<endl;
cout<<"The average overall time is :"<<average_overall<<endl;
cout<<"The average completion time is :"<<average_completion<<endl;

}


