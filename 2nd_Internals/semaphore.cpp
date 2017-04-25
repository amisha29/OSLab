#include <stdlib.h>
#include <iostream>
using namespace std;

int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int s)
{
  return (--s);
}

int signal(int s)
{
  return (++s);
}

void producer()
{
  empty = wait(empty);
  mutex = wait(mutex);
  x++;
  cout<<"\nProducer produces the item "<<x;
  mutex = signal(mutex);
  full = signal(full);
}

void consumer()
{
  full = wait(full);
  mutex = wait(mutex);
  cout<<"\nConsumer consumes the item "<<x;
  x--;
  mutex = signal(mutex);
  empty = signal(empty);
}

int main()
{
  int n;
  cout<<"\n1)p\n2)C\n3)e\n";
  while(1)
  {
    cout<<"\nEnter ";
    cin>>n;
    switch(n)
    {
      case 1:
        if(mutex==1 && empty != 0)
          producer();
        else
          cout<<"\nBuffer full";
        break;
      case 2:
        if(mutex == 1 && full != 0)
          consumer();
        else
          cout<<"\nempty Buffer";
        break;
      case 3:
        exit(0);
      default:
        exit(0);
    }
  }
}
