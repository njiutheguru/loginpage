#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <conio.h>


using namespace std;
void ImputError();
void login();
void Registration();
void  ForgotPassword();
void delete_account();
void reset_password(string oldWord,string newWord);
void resetfuntion();
void clear();

int main()
{

    int choice;
    cout <<"----------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------" <<endl;
    cout <<"\t \t \t \t WELCOME TO THE SIGN IN/SIGN UP PAGE"<<endl;
    cout <<"\n _______________________________________________________________________________";
    cout <<"\n \t\t\t MENU ";
    cout <<"\n \t Press 1 to Login";
    cout <<"\n \t Press 2 to Register";
    cout <<"\n \t Press 3  if you forgot your password";
    cout <<"\n \t Press 4 to Reset Password ";
    cout <<"\n \t Press 5 to EXIT";
    

    cout << "\n";
    cout <<"\n Please Enter Your choice: ";
    cin >>choice;
    ImputError();

    cout <<endl;
        ImputError();
    switch(choice)
    {
        case 1: 
                login();
                break;

        case 2:
            Registration();
            break;

        case 3: 
            ForgotPassword();
            break;

        case 4:
                    resetfuntion();
                    break;

        case 5:
            cout<<"\n Logging out of the system................................................................";
            cout<<"---------------------------------------------------------------------------------------------";
            cout <<"\n ******************************Welcome********************************";
            exit(0);
            break;
        

        default:
            clear();
            cout <<"Invalid Imput, Please the option provided"<<endl;
            main();

    }
    return 0;
}

void ImputError()
{
    if(cin.fail())
    {
        cout <<"\n Invalid Input!!!" << endl;
        cout <<"\n Please Try Again!" << endl;
        getch();//for the purpose of the windows console app
        exit(1);
        
    }
}
void login()
{
    int count=0;
    string user_Id, ID, password,pass;
    clear();
    cout<<"\n Please Enter Your username and password To Login :";
    cout<< "\n USERNAME: ";
    cin>>user_Id;
    ImputError();
    cout<< "\n PASSWORD: ";
    cin>>password;
    ImputError();
    
    ifstream input("records.txt");
    while (input>>ID>>pass)
    {
        /* code */
        if(ID==user_Id && pass==password)
        {
            count =1;
            clear();
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\n You Have Log in successfully";
        cout <<"----------------------------------WELCOME------------------------------------\n\n";
        main();
    }
    else
    {
        cout <<"\n The password or Username You Entered is not correct! Please try Again!" << endl;
        main();
    }
    
}
void Registration()
{
    string rusername, rpassword, rid, rpass;//
    string rpassword_confirm;
    clear();
    cout <<"\n Please Enter your username and password: ";
    cout << "\n USERNAME: ";
    cin>>rusername;
    ImputError();
    cout <<endl;
    cout <<"\n PASSWORD: ";
    cin>>rpassword;
    ImputError();
    cout << "\n Enter Your PASSWORD AGAIN TO CONFIRM!:";
    cin>>rpassword_confirm;
    ImputError();
    cout << endl;
    if(rpassword_confirm==rpassword)
    {
        ofstream file1("records.txt",ios::app);
    file1<<rusername<<' '<<rpassword<<endl;
    clear();
    cout <<"\n REGISTRATION SUCCESSFUL!" << endl;
        main();
    }
    else 
    {
        cout <<"\n REGISTRATION FAILED! THE PASSWORDS ARE NOT MATCHING!" << endl;
        main();

    }

}
void  ForgotPassword()
{
    int option;
    clear();
    cout <<"\n Retrieve Your Password Faster than Before!" << endl;
    cout <<"\n Press 1 to search your ID  by the username:";
    cout << "\n Press 2 to go back to the Main Menu ";
    cout <<"\n Enter Your Choice:";
    cin>>option;
    ImputError();
      
       

        switch(option)
        {
            case 1:
            {
                 int count=0;
                string suserid, sID, spassword;
                cout <<"\n Enter the username You remember:" << endl;
                cin>>suserid;
                ImputError();
                ifstream file2("records.txt");
                while(file2>>sID>>spassword)
                {
                    if(sID==suserid)
                    {
                        count =1;
                        break;
                    }

                }
                file2.close();
                if(count==1)
                {
                    cout <<"\n YOur Account Have Been Found!" << endl;
                    cout <<"\n Your Password is: " << spassword << endl;
                    main();

                }
                else 
                {
                    cout <<"\n Sorry, there is no Account for the Provided username ID." << endl;
                    main();
                }
             break;
            }  
            case 2: 
            {
                main();
                break;
            }

            default:
                
                {
                        cout <<"\n Invalid Input." << endl;
                    cout <<"\n please Try Again." << endl;
                    main();
                }
       

        }
    


}


void reset_password(string oldWord,string newWord)
{
    ifstream inputFile("records.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }

    string line;
    string content;

    // Read the entire content of the file
    while (getline(inputFile, line)) {
        content += line + '\n';
    }

    inputFile.close();

    // Replace all occurrences of the old word with the new word in the content
    size_t pos = 0;
    while ((pos = content.find(oldWord, pos)) != string::npos) {
        content.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }

    ofstream outputFile("records.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Cannot open output file." << endl;
        return;
    }

    // Write the modified content back to the file
    outputFile << content;
    outputFile.close();

    cout << "Password Reset complete." << endl;
}
void resetfuntion()
{
    string sID,spassword;
    string word1, word2,newword1,newword2;
    int count=0;
     cout <<"\n Enter Your username: ";
    cin >> word1;
    ImputError();
    cout <<"\n Enter Your  New username: ";
      cin >> newword1;
      ImputError();
         cout <<"\n Enter Your password: ";
    cin>>word2;
    ImputError();
     cout <<"\n Enter Your New password: ";
       cin >> newword2;
       ImputError();
    ifstream file2("records.txt");
                while(file2>>sID>>spassword)
                {
                    if(sID==word1 && spassword==word2)
                    {
                        count=1;
                        break;
                        
                    }
                   

                }
                if(count==1)
                {
                    reset_password(word1,newword1);
                    reset_password(word2,newword2);
                }
                 else
                    {
                        cout <<"\n You must enter your Correct Username and password to reset, otherwise go to forgot password!" << endl;
                        getch();
                        main();
                    }
    
   
    
}


void clear()
{
    system("CLS");
}
