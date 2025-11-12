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
    bool insideSingleQoute = false;
    stack<char> stack;
    
    for(char sign : s){
        i++;

        if(sign == '\''){ // if meet single qoute
            insideSingleQoute = !insideSingleQoute;
            continue;
        }
        if(insideSingleQoute) continue; // if inside single qoute

        if(isClosed(sign)){
            if (stack.empty()) {
                cout << "Error at position " << i + 1 << ": No matching opening bracket.\n";
                return false;
            }
            if (!isMatching(stack.peek(), sign)) {
                cout << "Error at position " << i << ": Mismatched bracket.\n";
                return false;
            }
            stack.pop();
        }
        if (isOpened(sign)) {
            stack.push(sign);
        } 
    }
    if (!stack.empty()) {
        cout << "Error at position " << i + 1 << ": missing closing bracket.\n";
        return false;
    }

    cout << "Brackets are balanced!\n";
    return true;
}

int main(){
    string test1 = "()[]{}";   // valid
    string test2 = "({[]})";     // invalid
    string test3 = "([)]"; // invalid
    string test4 = "(((";      // invalid 
    string test5 = "()))";      // invalid 
    string test6 = "if(a[0] == '{')";      // VALID

    cout << "Test 1: " << test1 << endl;
    isBalanced(test1);

    cout << "\nTest 2: " << test2 << endl;
    isBalanced(test2);

    cout << "\nTest 3: " << test3 << endl;
    isBalanced(test3);

    cout << "\nTest 4: " << test4 << endl;
    isBalanced(test4);

    cout << "\nTest 5: " << test5 << endl;
    isBalanced(test5);

    cout << "\nTest 6: " << test6 << endl;
    isBalanced(test6);


    return 0;
}