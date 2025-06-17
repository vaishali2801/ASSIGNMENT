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
		
		for(int j=0 ;j<C ;j++)
        {
			cout << "Arr["<< i << "][ "<< j << "]:";
			cin >> arr[i][j]; 
		}
		cout << endl;	
	}
	
	int rowNum;
    cout << "Enter the row number : (0 to " << R-1 << "): ";
    cin >> rowNum;

    if (rowNum >= 0 && rowNum < R) {
        int Sum = 0;
        cout << "Elements of row " << rowNum << ": ";
        for (int j = 0; j < C; j++)
         {
            cout << arr[rowNum][j] << " ,";
            Sum += arr[rowNum][j];
        }
        cout << endl << "Sum of row " << rowNum << ": " << Sum << endl;
    }
    else 
    {
     cout << "Invalid row number!" << endl;
    }

  
    int colNum;
    cout << "Enter the column number : (0 to " << C-1 << "): ";
    cin >> colNum;

    if (colNum >= 0 && colNum < C) {
        int Sum = 0;
        cout << "Elements of column " << colNum << ": ";
        for (int i = 0; i < R; i++) 
        {
            cout << arr[i][colNum] << " ,";
            Sum += arr[i][colNum];
        }
        cout << endl << "Sum of column " << colNum << ": " << Sum << endl;
    } 
    else 
    {
        cout << "Invalid column number!" << endl;
    }
    return 0;
}