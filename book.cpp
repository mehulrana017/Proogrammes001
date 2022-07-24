#include<iostream>
using namespace std;


int arr[20], indx=0;

class book{

    int price;
    string bname;

public:
    void insert(){
        cout<<"Enter Book name: ";
        cin>>bname;

        cout<<"Enter price: ";
        cin>>price;

        arr[indx] = price;
        indx++;
    }

    void display(){
        cout<<"\nName: "<<bname<<endl;
        cout<<"Price: "<<price<<endl;
    }

    void compare(book temp[]){
        int cmp = 0;
        int i=0;
        for(i=0; i<indx; i++){

            if(arr[i] < 200){
                continue;
            }

            else{
                cmp = i; 
            }
        temp[cmp].display();
        }
    }

};



int main() {
 
    book *objB;
    objB = new book[10];

 
    int choice, num=0;

    do{
        cout<<"\n1. Insert"<<endl;
        cout<<"2. display"<<endl;
        cout<<"3. Less than 200"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"\nEnter your choice: "<<endl;

        cin>>choice;

        switch (choice)
        {
        case 1:
       
            cout<<"Enter no of Enteries: ";
            cin>>num;

            for(int i=0; i<num; i++){
                objB[i].insert();
            }
            break;
        case 2:
           
            for(int i=0; i<num; i++){
                objB[i].display();
            }
            break;
        
        case 3:
           
            for(int i=0; i<num; i++){
                objB[i].compare(objB);
            }
            break;
        

        }

    }while(choice != 4);


    return 0;
}