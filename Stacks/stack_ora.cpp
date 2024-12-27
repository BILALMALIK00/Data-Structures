#include<iostream>
using namespace std;

class stack {
public:
    int top;
    int size;
    int *arr;

public:
    stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int v) {
        if (size - top > 1) {
            top++;
            arr[top] = v;

        } else {
            cout << "stack is full" << endl;
        }
    }

    int pop() {
        if (top != -1) {
            int t = arr[top];
            top--;
            return t;
        } else {
            cout << "empty" << endl;
            return -1;  
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isfull() {
        return (top == size - 1);
    }

    int max() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;  // Returning -1 if stack is empty
        }
        int maxVal = arr[0];
        for (int i = 1; i <= top; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    int peek() {
        if (top != -1) {
            return arr[top];
        } else {
            return -1;  // Returning -1 if stack is empty
        }
    }
    bool isempty(){
    	if(top==-1){
    		return true;
		}
		return false;
	}
};
void sort(stack&s1,int num){
	if(s1.isempty()||s1.peek()<num){
		s1.push(num);
		return;
	}
	int n=s1.peek();
	s1.pop();
	sort(s1,num);
	s1.push(n);
}
void max(stack&s1,int &maxi){
	if(s1.isempty()){
		return;
	}
	int num=s1.peek();
	s1.pop();
	max(s1,maxi);
	if(num>maxi){
		maxi=num;
	}
	s1.push(num);
}
void sort_stack(stack&s1){
	if(s1.isempty()){
		return;
	}
	int num=s1.peek();
	s1.pop();
	sort_stack(s1);
	sort(s1,num);
}
bool validparenthesis(stack&s1,string exp){
	for(int i=0;i<exp.length();i++){
	char ch=exp[i];
	if(ch=='('||ch=='{'||ch=='['){
		s1.push(ch);
	}else{
		if(!s1.isempty()){
		char sp=s1.peek();
		if(ch==')'&&sp=='('||ch=='}'&&sp=='{'||ch==']'&&sp=='['){
			s1.pop();
		}else{
			return false;
		}
	}else{
	return false;
	}
}
	}
	if(s1.isempty()){
		return true;
	}
	return false;
}

// Recursive function to delete the middle element
void solve(stack &s1, int n, int cnt) {
    if (cnt == n / 2) {
        s1.pop();
        return;
    }
    int temp = s1.peek();
    s1.pop();
    solve(s1, n, cnt + 1);
    s1.push(temp);  // Restoring the elements back
}

// Function to delete the middle element from the stack
void deletion(stack &s1, int size) {
    int cnt = 0;
    solve(s1, size, cnt);
}
void insertatbottom(stack&s1,int n){
	if(s1.isempty()){
		s1.push(n);
		return;
	}
	int num=s1.peek();
	s1.pop();
	insertatbottom(s1,n);
	s1.push(num);
}
void reverse(stack&s1){
	if(s1.isempty()){
		return;
	}
	int num=s1.peek();
	s1.pop();
	reverse(s1);
	insertatbottom(s1,num);
}

int main() {
    stack s1(6);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(6);
    s1.push(8);

    bool in = s1.isfull();
    if (in) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is not full" << endl;
    }

    cout << "Stack before deletion: ";
    s1.display();

    int d = s1.max();
    cout << "MAX VAL: " << d << endl;

    deletion(s1, s1.top + 1);

    cout << "Stack after deletion: ";
    s1.display();
    stack s2(6);
	bool ini=validparenthesis(s2,"{()}");
	if(ini){
		cout<<"valid"<<endl;
	}
	reverse(s1);
	insertatbottom(s1,10);
	sort_stack(s1);
	s1.display();
    int maxi=INT_MIN;
    max(s1,maxi);
    cout<<endl;
    cout<<"value:"<<maxi<<endl;
}

