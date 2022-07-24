#include<iostream>
using namespace std;
 
int *arr = new int[30], indx=0;
class bank{

    long acc_no; 
    int bal_amt=25000, pin;
    string usr_name;
    char name[20], acc_type[10];

public:
    int countDigit(long num){
        int rem, count=0;

        while(num > 0){
            num = num/10;
            count++;
        }
        return count;

    }

    void insert(){
        int flag=0;
        do{
            cout<<"\nAccount no: ";
            cin>>acc_no;
            int temp = countDigit(acc_no); 
                
            if(temp == 10){
                cout<<"Enter Name: ";
                cin>>name;

                cout<<"Account Type: ";
                cin>>acc_type;

                cout<<"Enter username: ";
                cin>>usr_name;

                cout<<"Set PIN: ";
                cin>>pin;
                flag=1;
            }
            else{
                cout<<"\nAccount number must be of 10 digit."<<endl;
            }
                
        }
        while(flag != 1);    

    }
    void deposit(){

            int amt;
            string cmp_usr;

            cout<<"Enter Username: ";
            cin>>cmp_usr;

            if(cmp_usr == usr_name){
                
                cout<<"Enter the amount to deposit: ";
                cin>>amt;
                arr[indx] = amt;
                indx++;
                bal_amt = bal_amt + amt;
            }
            else{
                cout<<"\nAccount doesnt exist\n";
            }

    }

    void withdraw(){
         int amt, cmp_acc;

        cout<<"Enter Pin to withdraw. ";
        cin>>cmp_acc;

        if(cmp_acc == pin){
            
            cout<<"Enter the amount to withdraw: ";
            cin>>amt;
            arr[indx] = -amt;
            indx++;
            bal_amt = bal_amt - amt;
            cout<<"\nRemaning balance: "<<bal_amt<<endl;
        }
        else{
            cout<<"\nIncorrect PIN\n";
        }
    }
    void display(){
        cout<<"\nAccount no: "<<acc_no<<endl;
        cout<<"Account Holder name: "<<name<<endl;
        cout<<"Account Type: "<<acc_type<<endl;
        cout<<"Balance: "<<bal_amt<<endl;
    }

    void history(){
        cout<<"\nTransaction History\n"<<endl;

        for(int i=0; i<indx; i++){
            cout<<arr[i]<<endl;
        }
        cout<<"\nCurrent Balance: "<<bal_amt<<endl;
    }
}; 

int main() {
    
    bank b1;

    int choice;

    do{
        cout<<"\n1. Create Account"<<endl;
        cout<<"2. Deposite"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Transaction History"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                b1.insert();
                break;
            case 2:
                b1.deposit();
                break;
            case 3:
                b1.withdraw();
                break;
            case 4:
                b1.display();
                break;
            case 5:
                b1.history();
                break;
        }
    }while(choice != 6);
    return 0;
}