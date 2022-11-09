#include <iostream>


class process{
  public:
    int process_no;
    int arrival_time;
    int burst_time; 

    int completion_time;
    int overall_time;
    int waiting_time;
    int response_time;

    int start_time;
/*     process();
    process(int,int,int); */

      
};

/* process::process(int no,int AT,int BT){
    process_no = no;
    arrival_time = AT;
    burst_time = BT;
}
 */


int main(){
process p[5];
int n;

std::cout<<"input no of processes less than 5\n";
std::cin>>n;

for (int i = 0; i < n; i++)
{
    int AT,BT;
    p[i].process_no=i+1;
    std::cout<<"enter arrival time for process "<<i+1<<" :";
    std::cin>>AT;
    std::cout<<"enter burst time for process "<<i+1<<" :";
    std::cin>>BT;
    p[i].arrival_time=AT;
    p[i].burst_time=BT;
}

for(int i=0;i<n;i++)
{
    std::cout<<p[i].process_no<<"\t";
    std::cout<<p[i].arrival_time<<"\t";
    std::cout<<p[i].burst_time<<"\n";
}


return 0;
}