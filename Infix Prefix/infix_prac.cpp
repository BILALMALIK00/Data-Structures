#include<iostream>
#include<string.h>
using namespace std;

class stack {
private:
    char* arr;
    int size;
    int top;
public:
    stack(int s) {
        size = s;
        arr = new char[size];
        top = -1;
    }
    void push(char c) {
        if (top == size - 1) {
            return;
}
        top++;
        arr[top] = c;
    }
    char pop() {
        if (top == -1) {
            return '\0';
        } else {
            char val = arr[top];
            top--;
            return val;
        }
    }
    bool isempty() {
        return top == -1;
    }
    char peek() {
        if (top == -1) {
            return '\0';
        } else {
            return arr[top];
        }
    }
};

	int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;
    }
}
bool isoperator(char c){
	return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
string infixtopostfix(const string&infix){
	string postfix=" ";
	stack s1(infix.size());
	for(int i=0;i<infix.size();i++){
		char c=infix[i];
		if(isalnum(c)){
			postfix+=c;
		}
		else if(c=='('){
			s1.push(c);
		}else if(c==')'){
			while(!s1.isempty()&&s1.peek()!='('){
				postfix+=s1.pop();
			}
			s1.pop();
		}
		else if(isoperator(c)){
			while(!s1.isempty()&&precedence(s1.peek())>=precedence(c)){
			postfix+=s1.pop();
		}
		s1.push(c);
	}
}
while(!s1.isempty()){
	postfix+=s1.pop();	
}
return postfix;
}
int main() {
    string eq = "A+B*(C^D-E)";
    cout << "Original string is " << eq << endl;
    string postfix = infixtopostfix(eq);
    cout << "Converted postfix expression is " << postfix << endl;
}

