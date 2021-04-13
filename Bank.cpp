//Command Line Banking System Code written in C++ 
// By Gaurav Yadav

// Let's Connect 
//https://www.instagram.com/idark.devil/
//https://in.linkedin.com/in/gaurav-yadav-a5966b190
//https://github.com/theydvgaurav


//Admin Password : Admin@12345

//Requirements : C++ Compiler

// For Windows replace system("clear") with system("CLS")

#include<bits/stdc++.h>
using namespace std;

//Account Class
class Account{
    private:
        double amount;          //private data member account balance
        string password;       //private data member password
    public : 
        int number;              // Account Number
        string name;            // Account Holder's Name

        Account(int y , double x, string nm, string pwd ){          //Constructor Account
            number = y;
            name = nm;
            amount  = x;
            password = pwd;
        }


        void Update_name(){                         // Upadate Name Function
            cout << "Enter New Name : ";
            string enteredname;
            cin >> enteredname;
            name = enteredname;
        }

        string passwd(){                            // Function to access private data member password
            string pwd = password;
            return pwd;
        }

        double bal(){                            // Function to access private data member Account Balance
            double bal = amount;
            return bal;
        }

        void Update_password(){                                 // Upadate password Function
            cout << "Enter New Password : ";
            string enteredpassword;
            cin >> enteredpassword;
            password = enteredpassword;
            cout << "Password Updated" << endl;
        }

        void Withdraw(){                                            // Withdraw Amount Function
            cout << "Enter Amount : ";
            double money;
            cin >> money;
            if(amount>=money){
                amount = amount - money;
                cout << "Withdrawal Successful" << endl;
        }
            view_bal();
        }

        void Deposit(){                                           // Amount Deposition Function
            cout << "Enter Amount : ";
            double money;
            cin >> money;
            amount = amount + money;
            cout << "Credit Successful" << endl;
            view_bal();
        }

        void tranfer(double x){                                           // Amount Transfer Function
            amount = amount + x;
        }

        void tranfer_(double money){                                           // Amount Transfer (deduction) Function
            amount = amount - money;
            cout << "Transfer Successful" << endl;
            view_bal();
        }

        void view(void){                                             //  Function to view all Account Details 
            cout << "Account Number : " << number << endl; 
            cout << "Account Holder : " << name << endl;
            cout << "Balance : " << amount << endl; 
            cout << "Password : " << password << endl; 

        }

        void view_bal(void){                                            // Check Balance Function
            cout << "Balance : " << amount << endl; 

        }

        void view_Admin(void){                                             //  Function to view all Account Details 
            cout << "Account Number : " << number << endl; 
            cout << "Account Holder : " << name << endl;
            cout << "Balance : " << amount << endl;  

        }

};


long long int stringHashing(string s)           //passwordhashing
{
  
    hash<string> mystdhash;
    return mystdhash(s);
  
}

void Transfer_fund(vector<Account> &Accounts, int i){                // Function to transfer money
    int num1 , num2;
    double money;
    string s , pwd;

    cout << "Enter the Benificiary's Account Number : " ;
    cin >> num1;
    cout << "Re-Enter the Benificiary's Account Number : " ;
    cin >> num2;

    while(num2!=num1){
        cout << "Both Account Numbers aren't same" << endl;
        cout << "Enter the Benificiary's Account Number : " ;
        cin >> num1;
        cout << "Re-Enter the Benificiary's Account Number : " ;
        cin >> num2;
        
    }
    bool check = false;
    
    for(int i = 0; i<Accounts.size();i++){                                  // Checking Whether The Account Exist or Not
        if(Accounts[i].number==num1)
            check = true; 
    }

    if(!check){
        cout << "Sorry, the Account Doesn't exist" << endl;
        return;
    }

    cout << "Enter the Amount to be tranferred : " ;
    cin >> money; 

    while(Accounts[i].bal() < money){
        cout << "Your Balance isn't enough to carry out this transaction " << endl;
        cout << "Account Balance : " << Accounts[i].bal() << endl;
        cout << "Enter the Amount to be tranferred : " ;
        cin >> money; 
    }
   
    for(int j = 0 ; j < Accounts.size() ; j++){
        if(Accounts[j].number==num1){
            cout << "Enter Your Password : ";
            cin >> pwd;
            while(!(stringHashing(Accounts[i].passwd()) == stringHashing(pwd))){       // Checking Whether the password of the account is correct or not
                cout << "Wrong Password, try again : "<< endl;
                cin >> pwd;
            }
            Accounts[j].tranfer(money);
            Accounts[i].tranfer_(money);
            break;
        }
    }
    return;

}




void reguser(vector<Account> &Accounts,int i){                      // Features for Registered User
    system("clear");
    int option;
    cout << "1.Check Balance" << endl;
    cout << "2.Deposit" << endl;
    cout << "3.Withdraw" << endl;
    cout << "4.Update Name" << endl;
    cout << "5.Update Password" << endl;
    cout << "6.View All Details" << endl;
    cout << "7.Money Transfer to an Account" << endl;
    cout << "8.Exit" << endl;
    cin >> option;
        switch(option){
            case 1 : Accounts[i].view_bal();
                     break;
            case 2 : Accounts[i].Deposit();
                     break;
            case 3 : Accounts[i].Withdraw();
                     break;
            case 4 : Accounts[i].Update_name();
                     break;
            case 5 : Accounts[i].Update_password();
                     break;
            case 6 : Accounts[i].view();
                     break;
            case 7 : Transfer_fund(Accounts,i);
                     break;
            case 8 : break;
        }
    return;
}


void RegisteredUserMenu(vector<Account> &Accounts){                       // Registered User Menu
    int x;
    string pwd;
    system("clear");
    cout << "**********************MENU**********************" << endl;
    cout << "Enter Your Account Number : " << endl;
    cin >> x;
    bool check = false;
    
    for(int i = 0; i<Accounts.size();i++){                                  // Checking Whether The Account Exist or Not
        if(Accounts[i].number==x)
            check = true; 
    }

    if(!check){
        cout << "Sorry, the Account Doesn't exist" << endl;
        return;
    }
        
    for(int i = 0; i<Accounts.size();i++){
        if(Accounts[i].number==x){
            cout << "Enter Your Password : " << endl;
            cin >> pwd;
            while(!(Accounts[i].number==x && stringHashing(Accounts[i].passwd()) == stringHashing(pwd))){       // Checking Whether the password of the account is correct or not
                cout << "Wrong Password, try again : "<< endl;
                cin >> pwd;
            }
            cout << "*********Welcome " << Accounts[i].name << " *********" << endl;
            reguser(Accounts,i);
            break;
            }    
         
    }
    return;
    

}

void MainMenu(){             // Main Menu
    cout << "**********************MENU**********************" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;

}

void create_user( vector<Account> &Accounts,int num , double amount, string nm, string pwd){                // Account Creation Function
       Accounts.push_back(Account(num, amount , nm, pwd));

}

void newuser(vector<Account> &Accounts){                // Input Details for Account Creation
    system("clear");
    int num;
    double amount;
    string nm , pwd;
    cout << "**********************Account Creation**********************" << endl;
    cout << "Enter Account Holder's Name : " << endl;
    cin >> nm;
    cout << "Enter any 5-digit Account Number : " << endl;
    cin >> num;
    while(!(num/10000 >0 && num/10000<10)){
        cout << num/1000 << endl;
        cout << "Account Number isn't of 5 digits, Please Choose Another One : " << endl;
        cin >> num;
    }
    for(auto it : Accounts){
        if(it.number == num){
            cout << "This Account Number Already Exists, Please Choose Another One : " << endl;
            cin >> num;
            while(!(num/10000 >0 && num/10000<10)){
                cout << "Account Number isn't of 5 digits, Please Choose Another One : " << endl;
                cin >> num; }
            it = Accounts.front();
        }
        
    }
    cout << "Enter Account opening Amount : " << endl;
    cin >> amount;
    cout << "Enter Password for Account: " << endl;
    cin >> pwd;
    
    
    create_user(Accounts, num ,amount, nm, pwd);
    return;

}




void UserMenu(vector<Account> &Accounts){           // User Menu
    system("clear");
    int option;
    cout << "**********************MENU**********************" << endl;
    cout << "1.Create Account" << endl;
    cout << "2.Already Registered" << endl;
    cout << "3.Exit" << endl;
    cin >> option;
        switch(option){
            case 1 : newuser(Accounts);
                     break;
            case 2 : RegisteredUserMenu(Accounts);
                     break;
            case 3 : break;
        }

}

void Delete_Account(vector<Account> &Accounts){
    int acc;
    bool check = false;
    cout << "Enter the Account Number : ";
    cin >> acc;
    
    for(int i = 0; i<Accounts.size();i++){                                  // Checking Whether The Account Exist or Not
        if(Accounts[i].number==acc)
        check = true; }

    if(!check){
        cout << "Sorry, the Account Doesn't exist" << endl;
        return;
        }

    auto it = Accounts.begin();

    while(it != Accounts.end())
    {
        if((*it).number==acc)
        {
            // delete *it;
            Accounts.erase(it);
            break;
        }
        it++;
    }


}

void Admin_Menu(vector<Account> &Accounts){
    
    system("clear");
    int option;
    cout << "**********************Welcome Admin**********************" << endl;
    cout << "1.View All Account Details" << endl;
    cout << "2.View Total Number of Accounts" << endl;
    cout << "3.Delete an Account" << endl;
    cout << "4.Exit" << endl;
    cin >> option;
        switch(option){
            case 1 : for(auto it : Accounts){
                        it.view_Admin();
                    }
                     break;
            case 2 : cout << "Total Number of Accounts : " << Accounts.size();
                     break;
            case 3 : Delete_Account(Accounts);
                    break;
            case 4 : break;
        }



}


void admin(vector<Account> &Accounts){          // Features for Admin
    system("clear");
    string pwd;
    int limit = 3;
    bool checkout = false; 
    
    while(limit)
    {

    cout << "Enter password : " ;
    cin >> pwd;
    cout << endl;

    if(stringHashing(pwd)==3574586834487498609)
    {
        cout << "Welcome Admin" << endl;
        checkout = true;
        Admin_Menu(Accounts);
        break;
    }

    else{
        limit--;
        cout << "Wrong Password" << endl;
        cout << "You only have " << limit << " attempts left" << endl;

    }}

    if(limit<=0)
        checkout = true;

    if(checkout)
        return;
}



int main()
{   

   vector<Account> Accounts;        // Vector of class type Account
 
    int option;
        do{
            MainMenu();
        cin >> option;
        switch(option){
            case 1 : admin(Accounts);
                     break;
            case 2 : UserMenu(Accounts);
                     break;
        }
        }while(option);
        


    return 0;
}