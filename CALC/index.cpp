#include<iostream>
using namespace std;

int main(){

    int mark;
    cout << "Enter your score:";
    cin >> mark;

    char grade = (mark >= 85) ? 'A' :
                 (mark >= 70) ? 'B' :
                 (mark >= 55) ? 'C' :
                 (mark >= 40) ? 'D' :
                 (mark >= 30) ? 'E' : 'F';

    cout << "You got " << grade << " grade" << endl;
    
    switch(grade){
    	case 'A': cout << "Excellent work!" << endl;
    	break;
    	case 'B':  cout << "Well done" << endl;
    	break;
    	case 'C': cout << "Good job" << endl;
    	break;
    	case 'D': cout << "You passed but you could do better" << endl;
    	break;
    	default:  cout << "you failed in exam" << endl;
    	break;
    	}
	if(grade == 'A'|| grade == 'B'|| grade == 'C'|| grade == 'D'){
        cout << "Congratulations! You are eligible for the next level" << endl;
        	}
	else{
        cout << "Please try again next time " << endl;
	}
    return 0;
}