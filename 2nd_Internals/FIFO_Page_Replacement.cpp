#include<iostream>
using namespace std;

class FIFO
{
    private :
        int frame_size, pages_count, page_faults, firstIn, frame_pos;
        int* frames;
        int* ref_string;
    public :
        FIFO(int x, int y)
        {
            frame_size = x;
            pages_count = y;
            ref_string = new int[pages_count];
            frames = new int[frame_size];
            frame_pos = 0;
            page_faults = 0;
            firstIn = 0;
            for(int i = 0; i < frame_size; i++)
                frames[i] = -1;
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
                    return 1;
            }
            return 0;
        }

        void display()
        {
            cout<<endl;
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
            for(int i = 0; i < pages_count; i++)
            {
                if(frame_pos < frame_size)
                {
                    if(found(ref_string[i]))
                    {
                        display();
                        continue;
                    }
                        
                    frames[frame_pos] = ref_string[i];
                    frame_pos++;
                    page_faults++;
                    display();
                }

                else
                {
                    if(found(ref_string[i]))
                    {
                        display();
                        continue;
                    }
                    frames[firstIn] = ref_string[i];
                    page_faults++;
                    firstIn = (firstIn+1)%frame_size;
                    display();
                }
            }

            cout<<"\nNum of page faults : "<<page_faults;
            delete[] ref_string;
            delete[] frames;
        }
        

};

int main()
{
    int frame_size, pages_count;
    cout<<"\nEnter num of frames : ";
    cin>>frame_size;
    cout<<"\nEnter num of pages : ";
    cin>>pages_count;
    FIFO fifo(frame_size, pages_count);
    fifo.getData();
    fifo.process();
}