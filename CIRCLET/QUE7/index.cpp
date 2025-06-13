#include<iostream>

using namespace std;

int main(){

    for (int i = 1; i <= 5; i++) {
        cout << "* ";

        if (i == 1 || i == 3) {

            for (int j = 1; j <= 4; j++) {
                cout << "* ";
            }
        }
        else if (i < 3) {
           
            for (int j = 1; j <= 3; j++) {
                cout << "  ";
            }
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}