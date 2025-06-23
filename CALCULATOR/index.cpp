#include<iostream>
using namespace std;

int sum(int a,int b){

    return a+b;
}
int sub(int a,int b){

    return a-b;
}
int mul(int a,int b){

    return a*b;
}
int dividation(int a,int b){

    return a/b;
}
int mol(int a,int b){

    return a%b;
}

int main(){
    int choice, a ,b;

    do{

    cout << "input/output:" << endl;
    cout << "Press 1 for addition(+)"<< endl;
    cout << "Press 2 for subtraction(-)"<< endl;
    cout << "Press 3 for multiplication(*)"<< endl;
    cout << "Press 4 for dividation(/)"<< endl;
    cout << "Press 5 for modulus(%)"<< endl;
    cout << "Press 0 for exit" << endl;

    cout << "Enter your choice:";
    cin >> choice;
    cout << endl;
    cout << "Enter first number:";
    cin >> a;
    cout << endl;
    cout << "Enter second number:";
    cin >> b;
    cout << endl;

        switch (choice)
        {
        case 1:
            cout << "addition of " << a << " & " << b << " is:" << sum(a,b) << endl;
            break;
        
        case 2:
            cout << "subtraction of " << a << " & " << b << " is:" << sub(a,b) << endl;
            break;
        
        case 3:
            cout << "multiplication of " << a << " & " << b << " is:" << mul(a,b) << endl;
            break;
        
        case 4:
            cout << "dividation of " << a << " & " << b << " is:" << dividation(a,b) << endl;
            break;
        case 5:
            cout << "modulus of " << a << " & " << b << " is:" << mol(a,b) << endl;
            break;
        
        default: cout << "you enter invalid number" << endl;
            break;
        }
    }while(choice!=0);
    return 0;
}