#include "Queue.hpp"
#include <iostream>
using namespace std;

int main(){
    Queue order;

    order.enqueue("Latte");
    order.enqueue("Cappuccino");
    order.enqueue("Espresso");

    cout << "Current Queue Size: " << order.size() << endl;
    order.display();
    Order nextOrder = order.dequeue();
    cout << "Dequeued Order: num_order=" << nextOrder.num_order
         << " drinkType=\"" << nextOrder.drinkType << "\"" << endl;
    return 0;
}