#include<bits/stdc++.h>
using namespace std;

//Account Class
class Account{
    private:
        double amount;
        string password;
    public : 
        string name;
        Account *number , *next;

        Account(double x, string nm, string pwd ){
            number = this;
            name = nm;
            amount  = x;
            password = pwd;
            next = NULL;
        }

        void Update_name(string enteredname){
            name = enteredname;
        }

        void Update_password(string enteredpassword){
            password = enteredpassword;
        }

        void Withdraw(double money){
             if(amount>=money)
                amount = amount - money;
        }

        void Deposit(double money){
                amount = amount + money;
        }

        void view(void){
            cout << "Account Number : " << number << endl; 
            cout << "Account Holder : " << name << endl;
            cout << "Balance : " << amount << endl; 
            cout << "Password : " << password << endl; 

        }
};

//passwordhashing
long long int stringHashing(string s)
{
  
    hash<string> mystdhash;
    return mystdhash(s);
  
}


void RegisteredUserMenu(){
    cout << "**********************MENU**********************" << endl;
    cout << "1.Check Balance" << endl;
    cout << "2.Deposit" << endl;
    cout << "3.Withdraw" << endl;
    cout << "4.Exit" << endl;

}

void MainMenu(){
    cout << "**********************MENU**********************" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;

}

void create_user( vector<Account> &Accounts,double amount, string nm, string pwd){
       Accounts.push_back(Account(amount , nm, pwd));

}

void UserMenu(vector<Account> &Accounts){
    int option;
    cout << "**********************MENU**********************" << endl;
    cout << "1.Create Account" << endl;
    cout << "2.Already Registered" << endl;
    cout << "3.Exit" << endl;
    cin >> option;
        switch(option){
            case 1 : newuser(Accounts);
                     break;
            case 2 : RegisteredUserMenu();
                     break;
            case 3 : break;
        }

}

void newuser(vector<Account> &Accounts){
    double amount;
    string nm , pwd;
    cout << "**********************Account Creation**********************" << endl;
    cout << "Enter Account Holder's Name : " << endl;
    getline(cin,nm);
    cout << "Enter Account opening Amount : " << endl;
    cin >> amount;
    cout << "Enter Password for Account: " << endl;
    getline(cin,pwd);
    create_user(Accounts,amount, nm, pwd);

}

void admin(vector<Account> &Accounts){
    string pwd;
    int limit = 3;
    bool checkout = false; 
    
    while(limit)
    {

    cout << "Enter password : " ;
    cin >> pwd;
    cout << endl;

    if(!pwd.compare("Arman@13"))
    {
        cout << "Welcome Admin" << endl;

        checkout = true;
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

   vector<Account> Accounts;
   Accounts.push_back(Account(600,"Gaurav Yadav", "Arman@13"));
 
    int option;
   
        MainMenu();
        cin >> option;
        switch(option){
            case 1 : admin(Accounts);
                     break;
            case 2 : UserMenu(Accounts);
                     break;
        }
    

    return 0;
}