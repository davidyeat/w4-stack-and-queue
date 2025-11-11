#include "stack.hpp"
#include <iostream>
#include <string>
using namespace std;


bool isOpened( char sign){
    if( sign == '(' ||
        sign == '[' ||
        sign == '{'){
            return true;
        }
    return false;
}
bool isClosed( char sign){
    if( sign == ')' ||
        sign == ']' ||
        sign == '}'){
            return true;
        }
    return false;
}
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
bool isBalanced(string s){
    int i = 0 ;
    stack<char> stack;
    
    for(char sign : s){
        if(isClosed(sign)){
            if (stack.empty()) {
                cout << "Error at position " << i + 1 << ": No matching opening bracket.\n";
                return false;
            }
            if (!isMatching(stack.peek(), sign)) {
                cout << "Error at position " << i + 1 << ": Mismatched bracket.\n";
                return false;
            }
            stack.pop();
        }
        if (isOpened(sign)) {
            stack.push(sign);
            i++;
        } 
    }
    if (!stack.empty()) {
        cout << "Error: Missing closing bracket(s).\n";
        return false;
    }

    cout << "Brackets are balanced!\n";
    return true;
}

int main(){
    string test1 = "{[()]()}";   // valid
    string test2 = "{[(])}";     // invalid
    string test3 = "func(a[3+2])"; // valid
    string test4 = "{[(])";      // invalid (missing close)

    cout << "Test 1: " << test1 << endl;
    isBalanced(test1);
    cout << "\nTest 2: " << test2 << endl;
    isBalanced(test2);
    cout << "\nTest 3: " << test3 << endl;
    isBalanced(test3);
    cout << "\nTest 4: " << test4 << endl;
    isBalanced(test4);


    return 0;
}