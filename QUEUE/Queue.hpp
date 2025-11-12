#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

#define Max_Size 8

struct Order{
    int num_order;
    string drinkType="";

};
class Queue{
    private:
        Order QueueList[Max_Size];
        int front;
        int rear;
    public:
        Queue():front(0), rear(0){}
        bool isEmpty() const {
            return front == rear;}
        bool isFull()const { 
            return (rear + 1) % Max_Size == front;
        }
        int size() const {
            return (rear - front + Max_Size) % Max_Size;
        }

        int capacity() const {
            return Max_Size;
        }

        bool enqueue(string drink){
            //  Check for Overflow (Full Queue)
            if (isFull()) {
                cout << "Error: Queue is full (Overflow)." << endl;
                return false;
            }
            QueueList[rear] = Order{rear, drink};
            rear = (rear + 1) % Max_Size;
            return true;
        }

        Order dequeue(){
            if (isEmpty()) {
                throw runtime_error("Queue is empty");
            }
            Order item = QueueList[front];
            front = (front + 1) % Max_Size;
            return item;

        };
        Order peek(){
            if (isEmpty()) throw runtime_error("Queue is empty");
            return QueueList[front];
        };

        void display(){
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }

            int cnt = size();
            cout << "Queue contents (" << cnt << "):\n";
            int idx = front;
            for (int i = 0; i < cnt; ++i){
                const Order &o = QueueList[idx];
                cout << "  [" << i << "] num_order=" << o.num_order
                     << " drinkType=\"" << o.drinkType << "\"\n";
                idx = (idx + 1) % Max_Size;
            }
        };
};

