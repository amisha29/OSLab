#include<iostream>
#include<cstdlib>
using namespace std;

struct process
{
  int no;
  int arrival;
  int waiting;
  int burst;
  int turnaround;
};

static int cmp_process(const void *p1, const void *p2)
{
  process *a = (process *)p1;
  process *b = (process *)p2;
  if(a->arrival < b->arrival)
    return -1;
  if(a->arrival == b->arrival)
    return 0;
  else
    return 1;
}

void display(process *q, int n)
{
  float avgwait = 0, avgturn = 0;
  cout<<"\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
  for(int i = 0; i < n; i++)
  {
    cout<<"P"<<q[i].no<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<"\t"<<q[i].waiting<<"\t"<<q[i].turnaround<<endl;
    avgwait += q[i].waiting;
    avgturn += q[i].turnaround;
  }

  cout<<"\nAvg waiting :  "<<avgwait/(float)n;
  cout<<"\nAvg turnaround :  "<<avgturn/(float)n;
}

int main()
{
  int num;
  cout<<"\nEnter num of processes : ";
  cin>>num;
  process q[num];
  cout<<"\nEnter arrival and burst time of "<<num<<" processes : ";
  for(int i = 0; i < num; i++)
  {
      q[i].no = i+1;
      cin>>q[i].arrival;
      cin>>q[i].burst;

  }
  cout<<"\nProcess\tArrival\tBurst\n";
  for(int i = 0; i < num; i++)
  {
    cout<<"P"<<q[i].no<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<endl;
  }

  qsort(q,num,sizeof(process), cmp_process);
  int current = 0;
  for(int i = 0; i < num; i++)
  {
    current = q[i].arrival>current ? q[i].arrival : current;
    q[i].waiting = current - q[i].arrival;
    q[i].turnaround = q[i].waiting + q[i].burst;
    current += q[i].burst;
  }

  cout<<"\nFCFS order\n";
  display(q,num);

}
