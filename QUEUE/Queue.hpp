#include<iostream>
#include<string>
using namespace std;

#define Max_Size 8

struct CoffeeOrder{
    int num_order;
    string drinkType="";

};
class Queue{
    private:
        CoffeeOrder QueueList[Max_Size];
        int front;
        int rear;
    public:
        Queue():front(0), rear(0){}
        bool isEmpty() const {
            return front == rear;}
        bool isFull()const { 
            return (rear == Max_Size) &&(front == 0 );
        }
        int size() const {
            return rear - front;
        }

        int capacity() const {
            return Max_Size;
        }

        bool enqueue(){

        }

        CoffeeOrder dequeue(){

        };
        CoffeeOrder peek(){

        };

        void display(){

        };
};

