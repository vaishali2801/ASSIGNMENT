#include<iostream>
using namespace std;
#define size 5
class Stack{
    int Arr[size];
    int top;
    public:
    Stack(){
        top = -1;
    }
    void Push(int value){
        if(top==(size-1)){
            cout << "Stack is full..!" << endl;
        }
        else{
            Arr[++top] = value;
            cout << value << " pushed into Stack" << endl;
        }
    }
    void Pop(){
        if(top==-1){
            cout << "Stack is empty" << endl;
        }
        else{
           cout << Arr[top] << " removed from stack" << endl;
           top--;
        }
    }
    void Peek(){
        if(top==-1){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << Arr[top] << " is top elemant in stack" << endl;
        }
    }
    void isEmpty(){
        if(top==-1){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Stack is not empty" << endl;
        }
    }
    void isFull(){
         if(top==(size-1)){
            cout << "Stack is full..!" << endl;
        }
        else{
            cout << "Stack is not full...!" << endl;
        }

    }
    void Display(){
        if(top == -1){
            cout << "Stack is empty...!" << endl;
        }
        else{
            cout << "Stack elements are :";
            for(int i=0;i<=top;i++){
               cout << Arr[i] << " " ;
            }
            cout << endl;
        }
    }

};
int main(){
    Stack s;
    int choice,value;
    do{
        cout << endl;
        cout << "-----------Stack menu-----------" << endl;
        cout << "Press 1 for Push element" << endl;
        cout << "Press 2 for pop element" << endl;
        cout << "Press 3 for top element" << endl;
        cout << "Press 4 for check empty stack" << endl;
        cout << "Press 5 for check full stack" << endl;
        cout << "Press 6 for display" << endl;
        cout << "Press 0 for Exit" << endl;
        cout << endl;
        cout << "Enter your choice :" ;
        cin >> choice;

        switch(choice){
            case 1: 
                cout << "Enter value :" ;
                cin >> value;
                s.Push(value);
                break;
            case 2: 
                s.Pop();
                break;
            case 3:
                s.Peek();   
                break;
            case 4:
                s.isEmpty();
                break;
            case 5:
                s.isFull();
                break;
            case 6:
                s.Display();
                break;
            default:
                cout << "Invalid choice...!please enter another key." << endl;
                break;                 
        }
    }while(choice != 0);
    return 0;
}