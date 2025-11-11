#include<iostream>

using namespace std;

// This template definition for Node is correct
template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T> 
class stack{
    private:
        // Now 'T' is recognized here because the class is a template
        Node<T> *top; 
        
    public:
        // Constructor to initialize the stack
        stack() {
            top = nullptr; // Always initialize pointers!
        }

        // push needs to accept a value of type T
        void push(T value){
            // Implementation goes here
        }

        // T is now valid as a return type
        T pop(){
            // Implementation goes here
        }

        T peek(){
            // Implementation goes here
        }

        bool empty(){
            // Implementation goes here
        }
};