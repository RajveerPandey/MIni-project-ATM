#include<conio.h>   // This C programmng header, we are using this use the function getch(). getch() is used to hold the screen until the user press any key. 
#include<iostream>  // Used to take user input and showing the output
#include<string>
using namespace std;

/*
Mini Project - ATM
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    -> Update Mobile No.
*/

class atm                        // class atm
{
private:                         // private member variables
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:                          // public member function

    // setData function is setting the Data into the private member variables
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;  // assigning the formal arguments to the private member var's
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    
    // getAccountNo function is returning the user's account no.
    long int getAccountNo()
    {
        return account_No;
    }

    // getName function is returning the user's Name
    string getName()
    {
        return name;
    }

    // getPIN function is returning the user's PIN
    int getPIN() 
    {
        return PIN;
    }

    // getBalance function is returning the user's Bank Balance
    double getBalance() 
    {
        return balance;
    }

    // getMobileNo function is returning the user's Mobile No.
    string getMobileNo()
    {
        return mobile_No;
    }
    
    // setMobile function is Updating the user mobile no.
    void setMobile(string mob_prev, string mob_new)
    {
        if(mob_prev == mobile_No)     // it will check old Mobile No
        {
            mobile_No = mob_new;     // and Update with the new, if old matches
            cout<<"\n"<<"Your new Mobile No. is successfully updated!!!";
            cout<<"\n"<<"Your new Mobile No. : "<<mobile_No;
            _getch();           // getch is to hold the screen(Until the user press any key)
        }
        
        else
        {
            cout<<"\n Incorrect old Moblie No. \n Please enter the correct old Mobile No. and try again.";
            _getch();
        }
    }

    // cashWithDraw function is used to withdraw the money from ATM
    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0 && amount_a < balance)   // check entred amount validity
        {
            balance -= amount_a;     // balance = balance - amount_a;
            cout<< "\n Please Collect Your Cash";
            cout<<"\n Available Balance : "<<balance;
            _getch();
        }

        else
        {
            cout<<"\n Invalid Input or Insufficient Balance";
            _getch();
        }
    }
};

//*****************************************************************************************************//

int main()
{
    int choice = 0, enterPIN;        // enterPIN and enterAccountNo. --> user authentication
    long int enterAccountNo;

    system("cls");

    // Create User (Object)
    atm user1;
    // Set User Details (into object)  (Setting Default Data)   // for custom input We have to use File Handling
    user1.setData(1234567, "Rajveer", 1111, 92000.67, "9007634765");


    do
    {
        system("cls");                               // Clear the screen

        cout<<"\n ***** Welcome to ATM ***** \n";
        cout<<"\n Enter Your Account No. ";          // asking user to enter the account no
        cin>>enterAccountNo;

        cout<<"\n Enter PIN ";                       // asking user to enter PIN
        cin>>enterPIN;



        // Check whether the entered values matches with the User Details
        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("clr");
                // User Interface
                cout <<"\n ***** Welcome to ATM ***** \n";
                cout << "\n Select Options ";
                cout << "\n 1. Check Balance ";
                cout << "\n 2. Cash Withdraw ";
                cout << "\n 3. Show User Details ";
                cout << "\n 4. Update Mobile No ";
                cout << "\n 5. Exit \n ";
                cin>> choice;                                            // Taking User choice

                switch(choice)                                           // switch condition
                {
                case 1:                                                  // If user presss 1
                    cout<<"Your Bank balance is : "<<user1.getBalance(); // getBalance is.. Printing the user's 
                                                                         // bank balance
                    _getch();
                    break;

                case 2:                                                  // If user presss 2 
                    cout<<"\n Enter the amount : ";
                    cin>>amount;
                    user1.cashWithDraw(amount);                         // calling the cashWithdraw function
                                                                        // passing the withdraw amount
                    break;

                case 3:                                                // If user presss 3
                    cout<<"\n *** User Details are:- ";                // Getting and Printing the user details
                    cout<< "\n -> Account No. "<<user1.getAccountNo();
                    cout<< "\n -> Name        "<<user1.getName();
                    cout<< "\n -> Balance     "<<user1.getBalance();
                    cout<< "\n -> Mobile No.  "<<user1.getMobileNo();

                    _getch();
                    break;

                case 4:                                             // If user presss 4
                    cout<<"\n Enter Old Mobile No. ";
                    cin>>oldMobileNo;                                 // Take old mobile no

                    cout<<"\n Enter new mobile no ";                  // Take old mobile no
                    cin>>newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo);       // Now set the new mobile no
                    break;

                case 5:                                            // If user presss 4
                    exit(0);                                       // exit application

                default:                                            // handle the invalid user inputs
                    cout<<"\n Enter Valid Data!!!";

                }
            }while(1);  // MENU    // Condition will always TRUE and loop is capable of running infinity times
        }


    }while(1);

}

