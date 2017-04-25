#include<iostream>
using namespace std;

struct process{
    int allocated[5];
    int max[5];
    int need[5];
    int isProcessed;
};

int main()
{
    int n, r;
    cout<<"\nEnter num of processes";
    cin>>n;
    cout<<"\nEnter num of resources";
    cin>>r;

    process q[n];
    int available[r], total[r];

    for(int i = 0; i < n; i++)
        q[i].isProcessed = 0;

    cout<<"\nEnter total num of each resources";
    for( int i = 0;  i < r; i++ )
        cin >> total[i];

    cout<<"\nEnter max allocation matrix";
    for( int i = 0;  i < n; i++ )
        for(int j = 0; j < r; j++)
            cin >> q[i].max[j];

    cout<<"\nEnter allocated matrix";
    for( int i = 0;  i < n; i++ )
        for(int j = 0; j < r; j++)
            cin >> q[i].allocated[j];

    //Need matrix
    for( int i = 0;  i < n; i++ )
        for(int j = 0; j < r; j++)
          q[i].need[j] = q[i].max[j] - q[i].allocated[j];

    cout<<"\nneed matrix\n";
    for( int i = 0;  i < n; i++ ){
      for(int j = 0; j < r; j++)
        cout<<q[i].need[j]<<"\t";
      cout<<endl;
    }

    //Available matrix
    for(int i = 0 ; i < r; i++)
    {
      available[i] = total[i];
      for(int j = 0; j < n; j++)
        available[i] -= q[j].allocated[i];
    }

    cout<<"\navailable matrix\n";
    for( int i = 0;  i < r; i++ ){
        cout<<available[i]<<"\t";
    }

    int i = 0, count;
    bool flag = false;
    while(i < n)
    {
      int select = -1;
      for(int p = 0; p < n; p++)
      {
        count = 0;
        if(!q[p].isProcessed)
        {
          for(int res = 0; res < r; res++)
          {
            if(q[p].need[res] <= available[res])
              count++;
            else
              break;
          }
        }
        if(count == r)
        {
          select = p;
          flag = true;
          break;
        }
      }

      if(flag)
      {
        flag = false;
        q[select].isProcessed = 1;
        cout<<"P" << select <<", ";

        for(int j = 0; j < r; j++)
          available[j] += q[select].allocated[j];

        // cout<<"\navailable matrix\n";
        // for( int k = 0;  k < r; k++ ){
        //     cout<<available[k]<<"\t";
        // }
        i++;
      }
      else
      {
          cout<<"\nno safe seq";
          return 0;
      }
    }
}
