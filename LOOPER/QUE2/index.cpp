#include<iostream>

using namespace std;

int main(){
     
    int num;
    int count =0;

    cout << "Enter any number:";
    cin >> num;

    while(num>=1){
        num/=10;
        count++;
    }
    cout << "Total number of digit:"<< count << endl;

    return 0;
}