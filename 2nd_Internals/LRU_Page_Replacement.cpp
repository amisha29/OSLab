#include<iostream>
using namespace std;

class LRU
{
    private :
        int frame_size, pages_count, page_faults, frame_pos;
        int* frames;
        int* time1;
        int* ref_string;
    public :
        LRU(int x, int y)
        {
            frame_size = x;
            pages_count = y;
            ref_string = new int[pages_count];
            frames = new int[frame_size];
            time1 = new int[frame_size];
            frame_pos = 0;
            page_faults = 0;
            
            for(int i = 0; i < frame_size; i++)
            {
                frames[i] = -1;
                time1[i] = -1;
            }
                
        }

        void getData()
        {
            cout<<"\nEnter the reference string : ";
            for(int i = 0; i < pages_count; i++)
                cin>>ref_string[i];
        }

        int found(int n)
        {
            for(int i = 0; i < frame_size; i++)
            {  
                if(frames[i] == n)
                    return i;
            }
            return -1;
        }

        int nextPos()
        {
            int min = 0;
            for(int j = 1; j < frame_size; j++)
            {
                if(time1[j] < time1[min])
                    min = j;
            }
            return min;
        }

        void display()
        {
            cout<<endl;
            cout<<"\nframe ";
            for(int i = 0; i < frame_size; i++)
            {
                if(frames[i] == -1 )
                    cout<<"\t";
                else
                    cout<<frames[i]<<"\t";
            }
        }


        void process()
        {
            int pos;
            for(int i = 0; i < pages_count; i++)
            {
                if(frame_pos < frame_size)
                {
                    pos = found(ref_string[i]);

                    if(pos != -1)
                    {
                        time1[pos] = i;
                        display();
                        continue;
                    }
                        
                    frames[frame_pos] = ref_string[i];
                    time1[frame_pos] = i;
                    frame_pos++;
                    page_faults++;
                    display();
                }

                else
                {
                    pos = found(ref_string[i]);
                    if(pos != -1)
                    {
                        time1[pos] = i;
                        display();
                        continue;
                    }

                    int next_pos = nextPos();
                    frames[next_pos] = ref_string[i];
                    time1[next_pos] = i;
                    page_faults++;
                    display();
                }
            }

            cout<<"\nNum of page faults : "<<page_faults;
        }
        

};

int main()
{
    int frame_size, pages_count;
    cout<<"\nEnter num of frames : ";
    cin>>frame_size;
    cout<<"\nEnter num of pages : ";
    cin>>pages_count;
    LRU lru(frame_size, pages_count);
    lru.getData();
    lru.process();
}