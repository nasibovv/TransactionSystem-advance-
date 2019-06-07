#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#define REGISTER_FILE "register.txt"
#define FALSE 0
#define TRUE 1

bool loginStatus;

class userInfo{
    
public:
    string username;
    string password;
    string name;
    string surname;
    string gender;
    int age;
    
public:
    void mainMenu();
    void accLogin();
    void registrationFunc();
    void writingFunc();
};

void clear_screen(){
    
#ifdef WINDOWS
    std::system("cls");
#else
    std::system ("clear");
#endif
}

void userInfo::writingFunc(){
    
    string logging[] = {name, surname, gender, username, password};
    string logging_text[] = {"Name: ", "Surname: ", "Gender: ", "Username: ", "Password: "};
    
    ofstream log;
    log.open(REGISTER_FILE);
    
    int width = 50;
    
    int height = width / 2;
    
    for (size_t x = 0; x <= width; x++) {
        
        log << "*";
        
        if (x == width){
            for (size_t y = 0; y <= height; y++){
                log << endl;
                log << "*";
                log << logging_text[y];
                log << "\t \t";
                log << logging[y];
            }
        }
    }
    
    log.close();
}

void userInfo::accLogin(){
    
    clear_screen();
    
    string sys_username, sys_password;
    
    while (true){
        
        cout << "\t\nPlease, enter your username: ";
        cin >> sys_username;
        
        cout << "\t\nPlease enter your password: ";
        cin >> sys_password;
        
        if(sys_username != username || sys_password != password){
            
            char choice2;
            
            cout << "\n\t\t ERROR \t\t\n" << endl;
            cout << "Password is not correct! " << endl;
            cout << "Press 'r' to try again, Press 'q' to main menu."<< endl;
            cin >> choice2;
            
            switch (choice2){
                    
                case 'r': break;
                    
                case 'q': mainMenu();
            }
        }
        
        else{
            
            clear_screen();
            loginStatus = TRUE;
            mainMenu();
        }
    }
}

void userInfo::registrationFunc(){
    
    clear_screen();
    
    string passControl; //password confirmation
    
    cout << "\n\n\t\t\t ***  REGISTATION PAGE  ***\t"<<endl;
    cout << "=====================================================\n";
    cout << "\t\tPlease fill the gaps for registration.\t\n\n";
    cout << "Username: "; cin >> username;
    
    do{
        do{
            
            string passWeakness;
            
            cout << "Password: "; cin >> password;
            
            if (password.size() < 8) {cout<<"You password is too weak. (*password should contain at least 8 characters)\n\n";}
            
        }while (password.size() <= 8);
        
        cout << "Confirm Your Password: "; cin >> passControl;
        
        if (password != passControl){  //pass control
            
            cout << "\n\t\tPasswords do not match!";
            cout << " Please try again.\n\n";
        }
        
    }while (password != passControl);
    
    cout << "\n\n\t\tPersonal Informations\n\n";
    cout << "Name: "; cin >> name;
    cout << "Surname: "; cin >> surname;
    
    do{
        cout << "Gender: "; cin >> gender;
        
        if (gender != "Male" && gender != "Female" && gender != "male" && gender != "female"){
            
            cout<<"\n\t\tInvalid Input! ";
            cout<<"Try again.\t\t\n\n";
        }
    }while (gender != "Male" && gender != "Female" && gender != "male" && gender != "female"); // user can input with lowercase
    
    
    string title;
    
    if (gender == "Male" || gender == "male") {title = "Mr.";}
    
    else if (gender == "Female" || gender == "female") {title = "Ms.";}
    
    
    cout << "Age: "; cin >> age;
    
    if (age < 18){
        
        cout << "\t\t\nSorry, " << title << surname << ". You can not register!\t\t\n";
        cout << "*your age is less than 18*\n\n";
    }
    
    else{
        
        cout << "\n\t\t\tCongratulations " << title << surname << ". You have successfully registered!\n\n\n\n\n";
        sleep(2);  // Wait two (2) seconds - unistd.h
    }
    
    loginStatus = TRUE;
    
    writingFunc();
    mainMenu();
}


void userInfo::mainMenu(){
    
    clear_screen();
    
    int choice;
    
    cout<<"\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGMENT SYSTEM\t\t\t\n\n";
    
    cout<<"\t\t############ WELCOME TO THE MAIN MENU ############\n\n";
    
    cout<<"\t1.Create new account\n";
    
    cout<<"\t2.Update infotmation of existing account\n";
    
    cout<<"\t3.For transactions\n";
    
    cout<<"\t4.Check the details of existing account\n";
    
    cout<<"\t5.Exit\n";
    
    cout<<"\n\n\t   Enter your choice: "; cin>>choice;
    
    
    switch (choice){
        case 1:
            registrationFunc();
            break;
            
        case 2:
            if (loginStatus)
                accLogin();  // + we will add information uptader with else
            break;
            
        case 3:
            if (loginStatus)
                accLogin(); // + we will add transaction func with else
            break;
            
        default:
            cout<<"Invalid Input! ";
            break;
    }
    
}

int main(){
    
    userInfo userInfo;
    userInfo.mainMenu();
    
}
