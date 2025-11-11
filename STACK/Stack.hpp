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
            Node<T>* newNode = new Node{value, top};
            top = newNode;
            cout<< "You just create \" "<<newNode <<" \" \n";

        }

        // T is now valid as a return type
        T pop(){
            // Implementation goes here
            if(top == nullptr){
                count << "Stack Underflow" << endl;
                return -1;
            }
            Node<T> *temp = top;
            top = top->next;
            T val = temp->data;

            delete temp;
            return val;
        }

        T peek(){
            // Implementation goes here
            if(top == nullptr){
                count << "Stack is empty" << endl;
                return false;
            }
            return top->data;
        }

        bool empty(){
            // Implementation goes here
            if(top == nullptr){
                return true;
            }
            return false;
        }
};