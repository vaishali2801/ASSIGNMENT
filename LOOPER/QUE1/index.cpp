#include<iostream>

using namespace std;

int main(){
    int i='A';

   do{
     cout << (char)i << endl;
     i+=4;

   }while(i<='Z');
    return 0;
}