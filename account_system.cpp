/*
File name: Account system
Author name: Omar Adel Badawy
Date created: 5/5/2022
Date modified: 15/5/2022
Description: account system take information from user like(email, user name, phne number, password) and save it in external taking into consideration encrypt the password,
check the strength of password, check if email is exist before, check the format of phone number, then user can sign in and check his information if it correct, can change password to
Version number: 2.1
*/


#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include<conio.h>
#include<stdio.h>

using namespace std;


class regeseration
{
private:
    string email;
    string userName;
    string password;
    string phoneNumber;
public:
    bool taking_email_from_User();
    bool taking_username_from_User();
    bool taking_phonenumber_from_User();
    bool taking_password_from_User();
    bool taking_email_exist();
    bool taking_password_exist();
    bool change_exist_password();
    string returning_email();
    string returning_username();
    string returning_password();
    string returning_phonenumber();
    int line_password_search;
    int line_user_search = 0 ;
    int counter = 0;
    string check;
};



regeseration r1;
fstream nameFile;
char input[81];
void create();
void ragister1();
void change_password();
void cipher();
bool strong_password(string password);



//main function for registered
int main()
{
    int choose;
    cout<<"\n*****\tWELCOME\t***** "<<endl;
    cout<<endl;
    cout<<"--------------------------\n| 1.Create a new account |\n--------------------------\n| 2.login to account     |\n--------------------------\n| 3.change password      |\n--------------------------"<<endl;
    cin>>choose;

    if (choose == 1 )
    {
        create();
        cout<<"\n\t\tYou have created account successfully "<<endl;
    }
    if(choose == 2 )
    {
        ragister1();
        cout<<endl;
        cout<<"\t\t>>>successful login<<<\t\t"<<endl;

    }
    if(choose == 3)
    {
        change_password();

    }


}

//___________________________________________________________________________________________________________

bool regeseration::taking_email_from_User()
{
    cout<<"\nEnter your email"<<endl;
    cin>>email;
    regex valid_mail("[a-z A-Z]+([- # ! % $ & + * / = ? ^ _ ` { | } ~ . .,]*[a-z A-Z])*([0-9]*[a-z A-Z]*)*[@][0-9]*[a-z A-Z]+(-*[0-9]*[a-z A-Z])*.com");
    while(regex_match(email,valid_mail) ==0)
    {
        cout<<"wrong email format"<<endl;
        cin.ignore();
        cin>>email;
    }
    nameFile.open("Emails.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    nameFile>>input;
    while (!nameFile.eof())
    {
        if (email == input)
        {
            break;
        }
        else
        {
            nameFile>>input;
        }
    }
    if (email == input)
    {
        cout<<"This Email is already used !"<<endl;
        nameFile.close();
        regeseration r1;
        r1.taking_email_from_User();
        return true;
    }
    nameFile.close();
    return true;
}

//___________________________________________________________________________________________________________

bool regeseration::taking_username_from_User()
{
    cout<<"\nEnter your username"<<endl;
    cin>>userName;
    regex valid_user_name("[a-z A-Z]+(_*[a-z A-Z])*");
    while(regex_match(userName,valid_user_name) == 0)
    {
        cout<<"wrong username format"<<endl;
        cin.ignore();
        cin>>userName;
    }
    nameFile.open("UserName.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    nameFile>>input;
    while (!nameFile.eof())
    {
        if (userName == input)
        {
            break;
        }
        else
        {
            nameFile>>input;
        }
    }
    if (userName == input)
    {
        cout<<"This UserName is already used !"<<endl;
        nameFile.close();
        regeseration r1;
        r1.taking_username_from_User();
        return true;
    }
    nameFile.close();
    return true;
}

//___________________________________________________________________________________________________________

bool regeseration::taking_phonenumber_from_User()
{
    cout<<"\nEnter your phone number"<<endl;
    cin>>phoneNumber;
    regex valid_phone_number("[0][1][0125][0-9]+");
    while(regex_match(phoneNumber,valid_phone_number) ==0 || phoneNumber.length()!=11)
    {
        cout<<"wrong phonenum format"<<endl;
        cin.ignore();
        cin>>phoneNumber;
    }
    nameFile.open("phonenumber.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    nameFile>>input;
    while (!nameFile.eof())
    {
        if (phoneNumber == input)
        {
            break;
        }
        else
        {
            nameFile>>input;
        }
    }
    if (phoneNumber == input)
    {
        cout<<"This phone number is already used !"<<endl;
        nameFile.close();
        regeseration r1;
        r1.taking_phonenumber_from_User();
        return true;
    }
    nameFile.close();
    return true;
}

//___________________________________________________________________________________________________________

bool regeseration::taking_password_from_User()
{

    regex valid_password("[A-z]+(#*@*\\$*\\?*!*%*&*=*[0-9]*[A-z]*)*");           // The Formal syntex for Passwords
    string  password2;


    cout<<"\nEnter the Password Please:   !! The Valid Password contain : letters, numbers, symbol like(!,@,#,$,%,&,?,=) Between 8,25"<<endl;

    int ch = getch();
    password.clear();

    while(ch != 13)                                                             // Replace passwords when write it with (*)
    {
        password.push_back(ch);
        cout<<"*";
        ch = getch();
    }

    nameFile.open("Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);       // open the password file

    while(!regex_match(password,valid_password) || password.length() < 8 || password.length() > 25){
        cout<<"\n!! The Valid Password contain : letters, numbers, symbol like(!,@,#,$,%,&,?,=) Between 8,25"<<endl;
        cout<<"NOT VALID Password Try again: "<<endl;

        int ch = getch();
        password.clear();

        while(ch != 13)                                                         // Replace passwords when write it with (*)
        {
            password.push_back(ch);
            cout<<"*";
            ch = getch();
        }
    }

    cout<<"\nRepeat The Password Please:";

    int ch2 = getch();
    while(ch2 != 13)                                                            // Replace passwords when write it with (*)
    {
        password2.push_back(ch2);
        cout<<"*";
        ch2 = getch();
    }


    while(password != password2){
        int ch2 = getch();
        password2.clear();

        cout<<"\npassword is not matching !! Try again: ";

        while(ch2 != 13)                                                       // Replace passwords when write it with (*)
        {
            password2.push_back(ch2);
            cout<<"*";
            ch2 = getch();
        }
    }

    // Ensure the password is a strong password to save it
    if(strong_password(password)){
        cout<<"\n\nStrong password DONE"<<endl;
    }else{taking_password_from_User();}




    for (int i = 0; i < password.length(); i++)
    {
        char encrypting;
        encrypting = password[i];/* getting the value of letters in asci*/
        if(int(encrypting) == 120) /* if the letter = x it must be replaced by a*/
        {
            nameFile<<"a";
        }
        else if (int(encrypting) == 121)/* if the letter = y it must be replaced by b*/
        {
            nameFile<<"b";
        }
        else if (int(encrypting) == 122)/* if the letter = z it must be replaced by c*/
        {
            nameFile<<"c";
        }
        else if (int(encrypting) == 88)/* if the letter = X it must be replaced by A*/
        {
            nameFile<<"A";
        }
        else if (int(encrypting) == 89)/* if the letter = Y it must be replaced by B*/
        {
            nameFile<<"B";
        }
        else if (int(encrypting) == 90)/* if the letter = Z it must be replaced by C*/
        {
            nameFile<<"C";
        }
        else if (int(encrypting) == 32)/* if the letter = " " it must be  " " C*/
        {
            nameFile<<" ";
        }
        else
        {
            nameFile<<char(int(encrypting)+1);   /*adding the previous value to 3 and getting the letter of the new asci number*/
        }
    }
    nameFile<<endl;
    nameFile.close();
    return true;
}

//___________________________________________________________________________________________________________


string regeseration::returning_email()
{
    return email;
}
string regeseration::returning_username()
{
    return userName;
}
string regeseration::returning_password()
{
    return password;
}
string regeseration::returning_phonenumber()
{
    return phoneNumber;
}
void create()
{

    int x = r1.taking_email_from_User();
    int y = r1.taking_username_from_User();
    int z = r1.taking_phonenumber_from_User();
    int h = r1.taking_password_from_User();
    string email = r1.returning_email();
    string password = r1.returning_password();
    string userName = r1.returning_username();
    string phoneNumber = r1.returning_phonenumber();
    if ((x == 1 && x == y ) && y == h)
    {
        nameFile.open("Emails.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        nameFile<<email<<"\n";
        nameFile.close();
        nameFile.open("UserName.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        nameFile<<userName<<"\n";
        nameFile.close();
        nameFile.open("phonenumber.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        nameFile<<phoneNumber<<"\n";
        nameFile.close();
    }
}
//
//_____________________________________________________
//_____________________________________________________
//

bool regeseration::taking_email_exist()
{
    line_user_search=0;
    cout<<"Enter your email :"<<endl;
    cin>>email;
    regex valid_mail("[a-z A-Z]+([- # ! % $ & + * / = ? ^ _ ` { | } ~ . .,]*[a-z A-Z])*([0-9]*[a-z A-Z]*)*[@][0-9]*[a-z A-Z]+(-*[0-9]*[a-z A-Z])*.com");
    while(regex_match(email,valid_mail) == 0)
    {
        cout<<"wrong email format"<<endl;
        cin.ignore();
        cin>>email;
    }
    nameFile.open("Emails.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    nameFile>>input;
    string line;
    int offset;
    ifstream nameFile;
    nameFile.open ("Emails.txt");

    if (nameFile.is_open())
    {
        while (!nameFile.eof())
        {

            line_user_search++;
            getline(nameFile,line);
            if ((offset = line.find(email, 0)) != string::npos)
            {
                nameFile.close();
                return true;
            }
            if (nameFile.eof())
            {
                cout<<"Wrong Email"<<endl;
                taking_email_exist();
            }
            else
            {
                continue;
            }


        }
        nameFile.close();
    }
    return true;
}

//___________________________________________________________________________________________________________

bool regeseration::taking_password_exist()
{
    counter = 0;
    bool flaag = true;
    while (flaag = true)
    {
        counter++;
        if ( counter <= 3 )
        {
            cout<<"Enter your password :"<<endl;

            int ch = getch();
            string password="",user;
            while(ch != 13 )
            {
                password.push_back(ch);
                cout<<"*";
                ch = getch();
            }
            cout<<endl;
            nameFile.open("passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
            nameFile>>input;
            string line , pass_enc = "";
            ifstream nameFile;
            nameFile.open ("passwords.txt");
            line_password_search = 0;
            while (!nameFile.eof())
            {
                line_password_search++;
                getline(nameFile,line);
                if (line_password_search == line_user_search){
                    for (int i = 0; i < password.length(); i++){
                        char encrypting;
                        encrypting = password[i];//getting the value of letters in asci
                        if(int(encrypting) == 120)//if the letter = x it must be replaced by a
                            pass_enc += "a";
                        else if (int(encrypting) == 121)// if the letter = y it must be replaced by b
                            pass_enc +="b";
                        else if (int(encrypting) == 122)// if the letter = z it must be replaced by c
                            pass_enc +="c";
                        else if (int(encrypting) == 88)// if the letter = X it must be replaced by A
                            pass_enc +="A";
                        else if (int(encrypting) == 89)// if the letter = Y it must be replaced by B
                            pass_enc +="B";
                        else if (int(encrypting) == 90)// if the letter = Z it must be replaced by C
                            pass_enc +="C";
                        else if (int(encrypting) == 32)// if the letter = " " it must be  " " C
                            pass_enc +=" ";
                        else
                            pass_enc +=char(int(encrypting)+1);   //adding the previous value to 3 and getting the letter of the new asci number
                    }
                    cout<<pass_enc<<endl;
                    cout<<line<<endl;
                }
                    if (pass_enc == line ){
                        break;
                        nameFile.close();
                        break;
                    }
                    if (pass_enc != line){
                        cout<<counter<<endl;
                        cout<<"Wrong password"<<endl;
                        nameFile.close();
                        taking_password_exist();
                    }
            }
        }else if (counter >= 4){
            flaag = false;
            cout<<"\t\tSORRY,you Entered wrong password three times"<<endl<<"\t\t>>>BYE<<<\n";
            break;
        }
    }
    nameFile.close();
    return 0;
}

void ragister1()
{
    int x = r1.taking_email_exist();
    int y = r1.taking_password_exist();
}

bool regeseration::change_exist_password()
{
    cout<<"Enter your password :"<<endl;
    password="";
    int ch = getch();
    while(ch != 13 )
    {
        password.push_back(ch);
        cout<<"*";
        ch = getch();
    }
    cout<<endl;
    nameFile.open("Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    nameFile>>input;
    string line;
    fstream nameFile;
    nameFile.open("Passwords.txt");
    line_password_search = 0;
    string check= "" ;
    while (!nameFile.eof())
    {
        getline(nameFile,line);
        for (int i = 0; i < password.length(); i++){
                    char encrypting;
                    encrypting = password[i];//getting the value of letters in asci
                    if(int(encrypting) == 120) //if the letter = x it must be replaced by a
                        check+="a";
                    else if (int(encrypting) == 121)// if the letter = y it must be replaced by b
                        check+="b";
                    else if (int(encrypting) == 122)// if the letter = z it must be replaced by c
                        check+="c";
                    else if (int(encrypting) == 88)// if the letter = X it must be replaced by A
                        check+="A";
                    else if (int(encrypting) == 89)// if the letter = Y it must be replaced by B
                        check+="B";
                    else if (int(encrypting) == 90)// if the letter = Z it must be replaced by C
                        check+="C";
                    else if (int(encrypting) == 32)// if the letter = " " it must be  " " C
                        check+=" ";
                    else
                    {check+=char(int(encrypting)+1);}//adding the previous value to 3 and getting the letter of the new asci number
        }
        line_password_search++;
        if (line_password_search == line_user_search){
            if (check == line ){
                nameFile.close();
                break;
            }
            if (check != line){
                cout<<check<<"\n"<<line<<'\n';
                cout<<"Wrong password"<<endl;
                nameFile.close();
                change_exist_password();
            }
            else{
                nameFile.close();
                change_exist_password();
            }
        }
        else{
            check="";
        }
    }
    nameFile.close();fstream nameFile2;fstream temp;
    string line2,password2;
    nameFile2.open("Passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    temp.open("temp.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    password = check;
    while(!nameFile2.eof()){
        getline(nameFile2,line2);
        if(password == line2){
            cout<<line2<<"  line 2"<<endl;
            cout<<"Enter the New password : ";
            int ch1 = getch();
            string password2 = "";
            string password = "";
            while(ch1 != 13 ){
                password.push_back(ch1);
                cout<<"*";
                ch1 = getch();
            }
            cout<<endl;
            cout<<"Enter the New password again : ";
            int ch2 = getch();
            while(ch2 != 13 )
            {
                password2.push_back(ch2);
                cout<<"*";
                ch2 = getch();
            }
            while(password2 != password)
            {
                cout<<"\n";
                cout<<"\tTRY AGAIN\n";
                password ="";
                password2="";
                cout<<"Enter the New password : ";
                int ch1 = getch();
                while(ch1 != 13 ){
                password.push_back(ch1);
                cout<<"*";
                ch1 = getch();
                }
                cout<<"Enter the New password again : ";
                int ch2 = getch();
                while(ch2 != 13 )
                {
                password2.push_back(ch2);
                cout<<"*";
                ch2 = getch();
                }
            }
            if (password2 == password)
            {
                for (int i = 0; i < password.length(); i++){
                    char encrypting;
                    encrypting = password[i];//getting the value of letters in asci
                    if(int(encrypting) == 120) //if the letter = x it must be replaced by a
                        temp<<"a";
                    else if (int(encrypting) == 121)// if the letter = y it must be replaced by b
                        temp<<"b";
                    else if (int(encrypting) == 122)// if the letter = z it must be replaced by c
                        temp<<"c";
                    else if (int(encrypting) == 88)// if the letter = X it must be replaced by A
                        temp<<"A";
                    else if (int(encrypting) == 89)// if the letter = Y it must be replaced by B
                        temp<<"B";
                    else if (int(encrypting) == 90)// if the letter = Z it must be replaced by C
                        temp<<"C";
                    else if (int(encrypting) == 32)// if the letter = " " it must be  " " C
                        temp<<" ";
                    else
                    {temp<<char(int(encrypting)+1);}        //adding the previous value to 3 and getting the letter of the new asci number
                }
                temp<<endl;
            }
        }
        else{
            temp<<line2<<endl;
        }


    }
    temp.close();
    nameFile2.close();
    nameFile2.open("Passwords.txt",std::fstream::out | std::fstream::trunc );
    temp.open("temp.txt",ios::in);
    string line3;
    while(!temp.eof())
    {
        getline(temp,line3);
        nameFile2<<line3<<endl;

    }

    temp.close();
    nameFile2.close();
    remove("temp.txt");
    cout<<"\n\t Done !!! \n";
    exit(0);
}

//___________________________________________________________________________________________________________

bool strong_password(string password){
    bool isuppercase = false;
    bool islowercase = false;
    bool isnumber = false;
    bool issymbol = false;

    for (char  i : password)
    {
        if(char(i) >= 65 & char(i) <= 90){
            isuppercase = true;
        }
        if(char(i) >= 97 & char(i) <= 122){
            islowercase = true;
        }
        if(char(i) >= 48 & char(i) <= 57){
            isnumber = true;
        }
        if(char(i) >= 33 & char(i) <= 38 || char(i) >= 61 & char(i) <= 64 ){
            issymbol = true;
        }
    }

    if(isuppercase & islowercase & isnumber & issymbol){
        return true;
    }else{
        cout<<"\n\nThis password is not strong try again !!  \nrules of strong password is :\n- Uppercase\n- Lowercase\n- Numbers\n- Symbols\n";
        return false;
    }

}

//___________________________________________________________________________________________________________

void change_password()
{
    int y = r1.taking_email_exist();
    int x = r1.change_exist_password();
}


