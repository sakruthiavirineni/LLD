#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BlockQueue
{
    public:
        queue<T> q;
        size_t s;
        condition_variable q_not_empty;
        condition_variable q_not_full;
        mutex m;
       
        BlockQueue( size_t s )
        {
            this->s = s;
        }
       
    void push( T &t )
    {
        unique_lock<mutex> lock(m);
        q_not_full.wait(lock, [this] { return q.size() < s; });
        q.push(t);
        cout<<"produced - >"<<t<<endl;
        q_not_empty.notify_one();
    }
   
    void pop()
    {
        unique_lock<mutex> lock(m);
        q_not_empty.wait(lock, [this] { return !q.empty(); });
        cout<<"consumed - >"<<q.front()<<endl;
        q.pop();
        q_not_full.notify_one();
    }
   
    size_t size()
    {
        lock_guard<mutex>lock(m);
        return q.size();
    }
   
    bool empty()
    {
        lock_guard<mutex>lock(m);
        return q.empty();        
    }
};

int main()
{
     BlockQueue<int> bq(3);
     
     std::thread consumer( [&bq]()
     {
         for( int i = 0; i<10; i++ )
         {
             bq.pop();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
         }
     });
     
         
     std::thread producer( [&bq]()
     {
         for( int i = 0; i<10; i++ )
         {
             bq.push(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
         }
     });
     
     
     producer.join();
     consumer.join();
}
