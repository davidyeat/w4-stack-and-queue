#include<iostream>
#include<stdexcept>

using namespace std;

// This template definition for Node 
template <typename T>
struct Node{
    T data;
    Node* next;
};

// This template definition for Stack
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
        ~stack() {
            Node<T>* current = top;
            while (current != nullptr) {
                Node<T>* nextNode = current->next;
                delete current; // Free the memory for the current node
                current = nextNode; // Move to the next node
            }
            top = nullptr; // Ensure top is reset after cleanup
        }

        // push needs to accept a value of type T
        void push(T value){
            // Implementation goes here
            Node<T>* newNode = new Node<T>{value, top};
            top = newNode;
            cout<< "You just create \" " <<newNode->data <<" \" \n";

        }

        // T is now valid as a return type
        T pop(){
            // Implementation goes here
            if(top == nullptr){
                cout << "Stack Underflow" << endl;
                throw runtime_error("Cannot pop from empty stack");
            }
            Node<T> *temp = top;
            top = top->next;
            T val = temp->data;

            delete temp;
            return val;
        }
        T peek(){
            // Implementation goes here
            if(empty()){
                throw runtime_error("Cannot peek at empty stack");
            }
            return top->data;
        }
        bool empty(){
            // Implementation goes here
            if(top == nullptr){
                cout << "Stack is empty" << endl;
                return true;
            }
            return false;
        }
};