#include<iostream>
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

int precedence(char c){
	if(c=='+'||c=='-'){
		return 1;
	}else if(c=='*'||c=='/'){
		return 2;
	}else if(c=='^'){
		return 3;
	}else{
		return -1;
	}
}
bool isoperator(char c){
	return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
string infixtoprefix(string infix){
	string prefix="";
	stack s1(infix.length());
	for(int i=infix.length()-1;i>=0;i--){
		char c=infix[i];
		if(isalnum(c)){
            prefix = c + prefix;
		}
		
		else if(c==')'){
			s1.push(c);
		}
		else if(c=='('){
			while(!s1.isempty()&&s1.peek()!=')'){
                prefix = s1.pop() + prefix;
			}
			s1.pop();
		}
		else if(isoperator(c)){
			while(!s1.isempty()&&precedence(s1.peek())>=precedence(c)){
                prefix = s1.pop() + prefix;
			}
			s1.push(c);
		}
	}
	while(!s1.isempty()){
		prefix=s1.pop()+prefix;
	}
	return prefix;
}
int main(){
	string eq = "(A-B/C)*(A/K-L)";
    cout << "Original infix expression: " << eq << endl;
    string prefix = infixtoprefix(eq);
    cout << "Converted prefix expression: " << prefix << endl;
}
