#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void read();
void write();
void clearData(); 

// Function to get the user's choice, validate it and store it in the reference parameter 'choice'
bool getUserChoice(int &choice) {
    // Declare a string variable to store the user's input
    string input;
    
    // Prompt the user to enter their choice
    cout << "\t\t\t Your choice: ";
    
    // Read the line of input from the user and store it in 'input'
    getline(cin, input);

    // Try to convert the input string to an integer
    try {
        // Attempt to convert the string 'input' to an integer and assign it to 'choice'
        choice = stoi(input);
        
        // If conversion is successful, return true indicating valid input
        return true;
    }
    // Catch block to handle the case where the input string is not a valid integer
    catch (invalid_argument const &e) {
        // Inform the user that the input was invalid and prompt to enter a number
        cout << "Invalid input, please enter a number." << endl;
        
        // Return false indicating invalid input
        return false;
    }
    // Catch block to handle the case where the input string represents a number out of the range of int
    catch (out_of_range const &e) {
        // Inform the user that the input number was out of range and prompt to try again
        cout << "Number out of range, please try again." << endl;
        
        // Return false indicating invalid input
        return false;
    }
}


int main()
{
    int choice;
    while (true) {
        //Prompt the options
        cout << "\t\t\t Type 1 to read" << endl;
        cout << "\t\t\t Type 2 to write " << endl;
        cout << "\t\t\t Type 3 to clear data " << endl;
        cout << "\t\t\t Type 4 to exit " << endl;
        
        if (!getUserChoice(choice)) {
            continue; // Invalid input, skip rest of the code and ask again
        }

        //switch statement for various choices 
        switch (choice)
        {
        case 1:
            system("cls");
            read();
            break;

        case 2:
            system("cls");
            write();
            break;

        case 3:
            system("cls");
            clearData();
            break;

        case 4:
            cout << "Thank You" << endl;
            return 0;

        default:
            system("cls");
            cout << "Invalid choice, please try again." << endl;
            main();
        }
    }
    return 0;
}

void read()
{
    // Create an ifstream object to read from the file "data.txt"
    ifstream dataStore("data.txt");
    string lines;
    
    // Check if the file was successfully opened
    if (dataStore.is_open())
    {
        // Read the file line by line until the end of the file is reached
        while (getline(dataStore, lines))
        {
            // Print each line to the console
            cout << "\t\t" << lines << endl;
        }
        // Close the file after reading all lines
        dataStore.close();
    }
    else
    {
        // Print an error message if the file could not be opened
        cout << "Unable to open file to retrieve data." << endl;
    }
}


void write()
{
    // String variable to take input
    string userInput;
    // Create an ofstream object to store lines of strings from top to bottom in the text file
    ofstream dataStore("data.txt", ios::app);

    // Check if the file is open
    if (dataStore.is_open())
    {
        cout << "Enter text data to store in data file, type 'exit' to quit." << endl;
        // Infinite loop to continuously take input from the user
        while (true)
        {
            cout << "> ";
            // Get string line inputs from user
            getline(cin, userInput);

            // Type 'exit' to exit and save inputs
            if (userInput == "exit")
            {
                break;
            }

            // Store the user input into the text file
            dataStore << userInput << endl;
        }
        // Close the file
        dataStore.close();
        // Clear screen
        system("cls");
        cout << "Data stored successfully!" << endl;
    }
    else
    {
        cout << "Unable to open data file to provide inputs." << endl;
    }
}

void clearData()
{
    // Open the file in trunc mode to clear its contents
    ofstream dataStore("data.txt", ios::trunc);

    // Check if the file is open
    if (dataStore.is_open())
    {
        dataStore.close();
        cout << "Data file contents cleared successfully!" << endl;
    }
    else
    {
        cout << "Unable to open data file to clear its contents." << endl;
    }
}
