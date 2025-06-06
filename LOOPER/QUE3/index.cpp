#include<iostream>
using namespace std;

int main(){

    int first_digit,last_digit,num;
    int sum =0;
    cout << "ENter number:"; // 678453
    cin >> num;

    last_digit=num%10;
    while(num >=10){
       
       num = num/10;
    }
    first_digit = num;
    sum = first_digit+ last_digit;
     cout << sum << endl;
   
    return 0;
}