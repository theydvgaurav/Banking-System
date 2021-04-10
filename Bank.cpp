#include<bits/stdc++.h>
using namespace std;

class Account{
    public : 
        int number;
        string name;
        double amount;
        string password;
        Account *link;

        Account(int y,int x, string n, string pwd ){
            number = y;
            name = n;
            amount  = x;
            password = pwd;
            link = NULL;
        }

};

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

void UserMenu(){
    cout << "**********************MENU**********************" << endl;
    cout << "1.Create Account" << endl;
    cout << "2.Already Registered" << endl;
    cout << "3.Exit" << endl;

}

void admin(){
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
void user(Account *A1)
{       cout << "**********Account Details**********" << endl;
        cout << A1->number << endl;
        cout << A1->name<< endl;
        cout << stringHashing(A1->password) << endl;
        cout << A1->amount << endl;
    
}


int main()
{   

   Account *A1 = new Account(5,600,"Gaurav Yadav", "arman@13");
 

    

    int option;

   
        MainMenu();
        cin >> option;
        switch(option){
            case 1 : admin();
                     break;
            case 2 : user(A1);
                     break;
        }
    

    return 0;
}