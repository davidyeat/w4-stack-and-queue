#include<iostream>
#include<string>
#include<stdexcept>
#ifndef QUEUE_HPP
#define QUEUE_HPP
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
        int count; 
        
    public:

        Queue():front(0), rear(0), count(0){} 
        
        // : Update isEmpty to use count
        bool isEmpty() const {
            return count == 0; // return front == rear is now ambiguous
        }
        
        //  Update isFull to use count
        bool isFull()const { 
            return count == Max_Size; // Queue is full when count equals Max_Size
            //  return (rear + 1) % Max_Size == front; (limits capacity to 7)
        }
        
        //  Update size to simply return count
        int size() const {
            return count;
            // Original: return (rear - front + Max_Size) % Max_Size;
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
            // FIX 6: Increment count
            count++; 
            return true;
        }

        Order dequeue(){
            if (isEmpty()) {
                throw runtime_error("Queue is empty");
            }
            Order item = QueueList[front];
            front = (front + 1) % Max_Size;
            //  Decrement count
            count--; 
            return item;
        }
        
        Order peek(){
            if (isEmpty()) throw runtime_error("Queue is empty");
            return QueueList[front];
        }

        void display(){
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }

            // size() is now simply count, which is correct
            int cnt = size(); 
            cout << "Queue contents (" << cnt << "):\n";
            int idx = front;
            for (int i = 0; i < cnt; ++i){
                const Order &o = QueueList[idx];
                cout << "  [" << i << "] num_order=" << o.num_order
                     << " drinkType=\"" << o.drinkType << "\"\n";
                idx = (idx + 1) % Max_Size;
            }
        }
};

#endif // QUEUE_HPP