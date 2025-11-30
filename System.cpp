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
    else
    {
        cout << "User does not exist. Please register first." << endl;
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
    userFile << password << endl;
    userFile.close();

    cout << "Registration Successful!" << endl;
}

void exitSystem()
{
    cout << "Thank you for using Apexcify Technology's School Management System. Goodbye!" << endl;
}
void displayMenu()
{
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
}
void handleUserChoice(int choice)
{
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registerUser();
        break;
    case 3:
        exitSystem();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}
void runSystem()
{
    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        handleUserChoice(choice);
    } while (choice != 3);
}


int main()
{
    cout << "Welcome to Apexcify Technology's School Management System!" << endl;

    runSystem();

    return 0;
}