#include <iostream>
#include <fstream>

using namespace std;

bool isValidUser(const string &name, const string &password)
{
    // Function to validate user credentials
    string filename = name + ".txt";
    ifstream userFile(filename);
    if (!userFile.is_open())
    {
        return false; // User file does not exist
    }

    string storedPassword;
    getline(userFile, storedPassword);
    userFile.close();

    return storedPassword == password;
}

bool userExist(const string &name)
{
    // Function to check if user exists
    string filename = name + ".txt";
    ifstream userFile(filename);
    return userFile.is_open();
}

void login()
{
    // Function to handle user login
    cout << "Enter Your name." << endl;
    string name;
    cin >> name;
    // Validattion of name
    if (userExist(name))
    {
        cout << "Enter Your Password " << endl;
        string password;
        cin >> password;
        if (isValidUser(name, password))
        {
            cout << "Login Successful!" << endl;
        }
        else
        {
            cout << "Invalid Password." << endl;
        }
    }
}

void registerUser()
{
    // Function to handle user registration
    cout << "Enter Your name." << endl;
    string name;
    cin >> name;

    if (userExist(name))
    {
        cout << "User already exists." << endl;
        return;
    }

    cout << "Enter Your Password " << endl;
    string password;
    cin >> password;

    ofstream userFile(name + ".txt");
    userFile << name << endl;
    userFile << password << endl;
    userFile.close();

    cout << "Registration Successful!" << endl;
}
int main()
{

    return 0;
}