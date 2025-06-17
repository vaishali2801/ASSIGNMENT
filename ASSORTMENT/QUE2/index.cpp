#include<iostream>
using namespace std;

int main(){
   
    int R, C;
	
	cout << "Enter the array's row size:";
	cin >> R;
	cout << "Enter the array's cols size:";
	cin >> C;
	
	
    int arr[R][C];

	for(int i=0 ;i<R ;i++){
		
		for(int j=0 ;j<C ;j++){
			 
			cout << "Arr["<< i << "][ "<< j << "]:";
			cin >> arr[i][j]; 
		}
		cout << endl;	
	}
	
    int largest = arr[0][0]; 
    
    for (int i = 0; i < R; i++) {

        for (int j = 0; j < C; j++) { 
        
            if (arr[i][j] > largest) {
                largest = arr[i][j];  
            }
        }
    }

    cout << "The largest element is: "<< largest << endl;

    return 0;
}
