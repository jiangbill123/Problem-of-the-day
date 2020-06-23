#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> s;
    for(unsigned long i = 0; i < input.size(); i++){
        if(input.at(i) == '(' || input.at(i) == '[' || input.at(i) == '{'){
            s.push(input[i]);
        }
        if(input.at(i) == ')' || input.at(i) == ']' || input.at(i) == '}'){
            if(s.empty()){
                return false;
            }
            else if(input.at(i) == ')' && s.top() == '('){
                s.pop();
            }
            else if(input.at(i) == ']' && s.top() == '['){
                s.pop();
            }
            else if(input.at(i) == '}' && s.top() == '{'){
                s.pop();
            }
            else {
                return false;
            }
                
            

        }
    
    }


    if(s.empty()){
      return true;
    }
    return false;
}   