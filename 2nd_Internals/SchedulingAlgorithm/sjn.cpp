#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

struct process
{
  int no;
  int arrival;
  int waiting;
  int burst;
  int turnaround;
  int scheduled;
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
  cout<<"\nProcess\tArrival\tBurst\tStart\tWaiting\tTurnaround\n";
  int current = 0;
  for(int i = 0; i < n; i++)
  {
    current = (q[i].arrival>current ? q[i].arrival : current);
    cout<<"P"<<q[i].no<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<"\t"<<current<<"\t"<<q[i].waiting<<"\t"<<q[i].turnaround<<endl;
    current += q[i].burst;
    avgwait += q[i].waiting;
    avgturn += q[i].turnaround;
  }

  cout<<"\nAvg waiting :  "<<avgwait/(float)n;
  cout<<"\nAvg turnaround :  "<<avgturn/(float)n;
}

void calc_times(process *q, int n)
{
  int current = 0;
  for(int i = 0; i < n; i++)
  {
    current = (q[i].arrival>current?q[i].arrival:current);
    q[i].waiting = current - q[i].arrival;
    q[i].turnaround = q[i].waiting+q[i].burst;
    current+=q[i].burst;
  }
}

process getMinBurst(process* q, int n, int arrival, int burst)
{
  int min = -1;
  // int burst = INT_MAX;
  for(int i = 0; i < n; i++)
  {
    if(q[i].scheduled)
      continue;
    if(q[i].arrival <= arrival && q[i].burst <= burst)
    {

      min = i;
      burst = q[i].burst;
      cout<<"\nif cond : burst "<<burst;
    }
  }

  if(min == -1)
  {
    for(int i = 0; i < n; i++)
    {
      if(q[i].scheduled)
        continue;
      arrival = q[i].arrival;
      return getMinBurst(q, n, arrival, burst);
    }
  }

  q[min].scheduled = 1;
  return q[min];
}

process* schedule(process* q, int n)
{
  process* order = new process[n];
  int current = q[0].arrival;
  for(int i = 0; i < n; i++)
  {
    order[i] = getMinBurst(q,n,current, INT_MAX);
    current += order[i].burst;
  }
  return order;
}

int main()
{
  int n;
  cout<<"\nEnter num of processes : ";
  cin>>n;
  process q[n];
  cout<<"\nEnter arrival and burst time of "<<n<<" processes : ";
  for(int i = 0; i < n; i++)
  {
      q[i].no = i+1;
      cin>>q[i].arrival;
      cin>>q[i].burst;
      q[i].scheduled = 0;

  }
  qsort(q,n,sizeof(process), cmp_process);
  cout<<"\nProcess\tArrival\tBurst\n";
  for(int i = 0; i < n; i++)
  {
    cout<<"P"<<q[i].no<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<endl;
  }


  process *order = schedule(q,n);
  calc_times(order, n);
  display(order,n);
  delete[] order;

}
