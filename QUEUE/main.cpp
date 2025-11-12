#include "Queue.hpp"
#include <iostream>
using namespace std;

int main(){
    Queue order;
    // Enqueue some orders
    order.enqueue("Latte");
    order.enqueue("Cappuccino");
    order.enqueue("Espresso");

    cout << "Current Queue Size: " << order.size() << endl;

    // Dequeue and display orders
    order.display();

    return 0;
}