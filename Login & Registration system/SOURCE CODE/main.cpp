#include<iostream>
#include<fstream>
using namespace std;

class A{
    public:
    void login();
    void registration();
    void forget();
};

int main(){
    A a;
    int c;
    cout<<"\t\t\t______________________________________________________________\n\n\n";
    cout<<"\t\t\t                      Welcome to Login page                   \n\n\n";
    cout<<"\t\t\t_______________________        MENU        ___________________\n\n\n";
    cout<<"                                                                      \n\n";
    cout<<"\t| Press 1 to REGISTER                     |"<<endl;
    cout<<"\t| Press 2 to LOGIN                        |"<<endl;
    cout<<"\t| Press 3 if you forgot your password     |"<<endl;
    cout<<"\t| Press 4 to EXIT                         |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
        a.registration();
        break;
        case 2:
        a.login();
        break;
        case 3:
        a.forget();
        break;
        case 4:
        cout<<"\t\t\t Thank You! \n\n";
        break;
        default:
        system("cls");
        cout<<"\t\t\t Please select from the options given above  \n"<<endl;
        main();
    }
    
}
void A::registration(){
    string ruserId,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f1("record.txt", ios::app); //for writing
    //input-output-stream open the file and app mode will append the output in the file.
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n Registration is successfull! \n";
    main();
}

void A::login(){
    int count;
    string userID, password, id ,pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userID;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("record.txt"); //file handling operator to read the data

    while(input>>id>>pass) //reading id & password
    {
        if(id==userID && pass==password){
            count =1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<userID<<"\n Your LOGIN is successfull \n Thanks for logging in ! \n";
        main();
    }
    else {
        cout<<"\n ! LOGIN ERROR !  \n Please check your username and password\n";
        main();
    }
}


void A::forget(){
    int option;
    system("cls");
    cout<<"\t\t\t You forget the password!! \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice :";
    cin>>option;
    switch(option){
        case 1: {
            int count=0;
            string suserid,sid,spass;
            cout<<"\n\t\t\tEnter your username : ";
            cin>>suserid;
             
            ifstream f2("record.txt");
            while(f2>>sid>>spass){
                if(sid==suserid){
                    count++;
                    }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n Your password is : "<<spass;
                cout<<"\n\n";
                main();
            }
            else{
                cout<<"\n\t Sorry! Your account is not found! \n";
                main();
                }
                break;
        }
        case 2:
        {   
            main(); 
        }   
        default:
        cout<<"\t\t\t Wrong choice ! PLease try again "<<endl;
        A::forget();
    }
}