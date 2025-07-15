#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
    string Accountholdername ;
    long long int accountnumber;
    double balance = 5000;

    public:
    void deposite(double amt){
        if(amt>0)
        {
            balance += amt;
            cout << "Deposited succesfully...!" << endl;
        }else{
            cout << "Invalid deposit amount!" << endl;
        }
    }

    double getBalance(){
        return balance;
    }

    void withdrawal(double amt){
        if(amt<=balance)
        {
            balance -= amt;
            cout << "withdrawal succesfully...!" << endl;
        }else{
            cout << "Insufficient Balance!" << endl;
        }
    }
    void Displayinfo(){
        cout << "=======Account Information=======" << endl;
        cout << "Account number : " << accountnumber << endl;
        cout << "Account Holder Name : " << Accountholdername << endl;
        cout << "Your Balance is : " << balance << endl;
    }

     void setAccountDetails(long long int acNo, string name ,double bal) {
        accountnumber = acNo;
        Accountholdername = name;
        balance = (bal >= 0) ? bal : 0;
    }
    
};

class SavingsAccount : public BankAccount {
public:
    double Interestrate;

    void CalculateInterest() {
        double Interest = getBalance() * Interestrate / 100;
        cout << "Total simple Interest is : " << Interest << endl;
    }
};


class CheckingAccount : public BankAccount {
public:
    double OverdraftLimit;

    void checkOverdraft(double amount) {
        if (amount > getBalance() + OverdraftLimit){
            cout << "Amount exceeds overdraft limit....!!!" << endl;
        }   
        else{
            cout << "Overdraft OK. Proceeding with withdrawal." << endl;
        }
    }
};


class FixedDepositeAccount : public BankAccount{
    public:

    void calculateInterest(int time){
        float rate = 8.5;
        cout << "Fixed Deposite Interest: " << (getBalance()* rate * time) / (12 * 100) << endl;
    }
};



int main(){

     SavingsAccount sa;
    sa.setAccountDetails(6498492847, "Bhoomi", 50000);
    sa.Interestrate = 4.75;

    CheckingAccount ca;
    ca.setAccountDetails(9834759875, "Krishna", 35000);

    FixedDepositeAccount fda;
    fda.setAccountDetails(8402849745, "Darshan", 78000);


    int choice = -1, in = -1, amount;

    while (choice != 0) {
        cout << "==============Bank System==============" << endl;
        cout << "Enter 1 to access Saving Account" << endl;
        cout << "Enter 2 to access Checking Account" << endl;
        cout << "Enter 3 to access Fixed Deposite Account" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1){

            while(in != 0){

                cout << "=======================" << endl;
                cout << "Enter 1 to check balance" << endl;
                cout << "Enter 2 to withdraw" << endl;
                cout << "Enter 3 to deposit" << endl;
                cout << "Enter 4 to calculate Fixed interest" << endl;
                cout << "Enter 5 to see profile" << endl;
                cout << "=======================" << endl;
                cout << "Enter your choice: ";
                cin >> in;
                switch (in) {
                    case 1:
                        cout << "Your Balance: " << sa.getBalance() << endl;
                        break;
                    case 2:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        sa.withdrawal(amount);
                        break;
                    case 3:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        sa.deposite(amount);
                        break;
                    case 4:
                        sa.CalculateInterest();
                        break;
                    case 5:
                        sa.Displayinfo();
                        break;
                    default:
                        cout << "Invalid choice...!" << endl;
                }
            }
            in = -1;
        }
        else if(choice == 2){

            while(in != 0){

                cout << "=====================" << endl;
                cout << endl;
                cout << "Enter 1 to check balance" << endl;
                cout << "Enter 2 to withdraw" << endl;
                cout << "Enter 3 to deposit" << endl;
                cout << "Enter 4 to see profile" << endl;
                cout << "=======================" << endl;
                cout << "Enter your choice: ";
                cin >> in;
                
                switch (in) {
                    case 1:
                        cout << "Your Balance: " << ca.getBalance() << endl;
                        break;
                    case 2:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        ca.checkOverdraft(amount);
                        break;
                    case 3:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        ca.deposite(amount);
                        break;
                    case 4:
                        ca.Displayinfo();
                        break;
                    default:
                           cout << "Invalid choice...!" << endl;
                }
            }
            in = -1;
        }
        else if(choice == 3){

            while(in != 0){

                cout << "=======================" << endl;
                cout << endl;
                cout << "Enter 1 to check balance" << endl;
                cout << "Enter 2 to withdraw" << endl;
                cout << "Enter 3 to deposit" << endl;
                cout << "Enter 4 to calculate interest" << endl;
                cout << "Enter 5 to see profile" << endl;
                cout << "=========================" << endl;
                cout << "Enter your choice: ";
                cin >> in;
                
                switch (in) {
                    case 1:
                        cout << "Your Balance: " << fda.getBalance() << endl;
                        break;
                    case 2:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        fda.withdrawal(amount);
                        break;
                    case 3:
                        cout << "Enter Amount: ";
                        cin >> amount;
                        fda.deposite(amount);
                        break;
                    case 4:
                        int time;
                        cout << "Enter time (in months): ";
                        cin >> time;
                        fda.calculateInterest(time);
                        break;
                    case 5:
                        fda.Displayinfo();
                        break;
                    default:
                           cout << "Invalid choice...!" << endl;
                }
            }
            in = -1;
        }
        else{
            cout << "Not available...!";
        }
    }
    return 0;
}