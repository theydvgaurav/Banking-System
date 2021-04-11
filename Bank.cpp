#include<bits/stdc++.h>
using namespace std;

//Account Class
class Account{
    private:
        double amount;
        string password;
    public : 
        int number;
        string name;
        Account *next;

        Account(int y , double x, string nm, string pwd ){
            number = y;
            name = nm;
            amount  = x;
            password = pwd;
            next = NULL;
        }

        void Update_name(){
            cout << "Enter New Name : ";
            string enteredname;
            cin >> enteredname;
            name = enteredname;
        }

        string passwd(){
            string pwd = password;
            return pwd;
        }

        void Update_password(){
            cout << "Enter New Password : ";
            string enteredpassword;
            cin >> enteredpassword;
            password = enteredpassword;
            cout << "Password Updated" << endl;
        }

        void Withdraw(){
            cout << "Enter Amount : ";
            double money;
            cin >> money;
            if(amount>=money){
                amount = amount - money;
                cout << "Withdrawal Successful" << endl;
        }
            view_bal();
        }

        void Deposit(){
            cout << "Enter Amount : ";
            double money;
            cin >> money;
            amount = amount + money;
            cout << "Credit Successful" << endl;
            view_bal();
        }

        void view(void){
            cout << "Account Number : " << number << endl; 
            cout << "Account Holder : " << name << endl;
            cout << "Balance : " << amount << endl; 
            cout << "Password : " << password << endl; 

        }
        void view_bal(void){
            cout << "Balance : " << amount << endl; 

        }
};

//passwordhashing
long long int stringHashing(string s)
{
  
    hash<string> mystdhash;
    return mystdhash(s);
  
}

void reguser(vector<Account> &Accounts,int i){
    system("clear");
    int option;
    cout << "1.Check Balance" << endl;
    cout << "2.Deposit" << endl;
    cout << "3.Withdraw" << endl;
    cout << "4.Update Name" << endl;
    cout << "5.Update Password" << endl;
    cout << "6.View All Details" << endl;
    cout << "7.Exit" << endl;
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
            case 7 : break;
        }
}


void RegisteredUserMenu(vector<Account> &Accounts){
    int x;
    string pwd;
    system("clear");
    cout << "**********************MENU**********************" << endl;
    cout << "Enter Your Account Number : " << endl;
    cin >> x;
    
    for(int i = 0; i<Accounts.size();i++){
        if(Accounts[i].number==x){
            cout << "Enter Your Password : " << endl;
            cin >> pwd;
            while(!(Accounts[i].number==x && Accounts[i].passwd() == pwd)){
                cout << "Wrong Password, try again : "<< endl;
                cin >> pwd;
            }
            cout << "*********Welcome " << Accounts[i].name << " *********" << endl;
            reguser(Accounts,i);
            break;
            }    
         
    }
    cout << "Account Doesn't Exist" << endl;

}

void MainMenu(){
    cout << "**********************MENU**********************" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;

}

void create_user( vector<Account> &Accounts,int num , double amount, string nm, string pwd){
       Accounts.push_back(Account(num, amount , nm, pwd));

}

void newuser(vector<Account> &Accounts){
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

}




void UserMenu(vector<Account> &Accounts){
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



void admin(vector<Account> &Accounts){
    system("clear");
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