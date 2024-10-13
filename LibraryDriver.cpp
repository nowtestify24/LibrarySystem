#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

void showMenu();
void showDisplayMenu();
bool sortHelper(char c);
void displayInventory(Library& library,int page);
void insertBook(Library& library);                              //function declarations
void removeBook(Library& library);
void saveAndExit(Library& library, string& filename);
void searchForBook(Library& library);

int main() {
    Library library;
    string filename = "library.txt";
    library.loadInventory(filename);
    char choice = 'd';
    while (choice != 'q') 
    {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
        choice = tolower(choice);                            //switch statement and menu for input allowing user to 
        switch (choice) {                                    //display, insert, remove or search for what is in the library
            case 'd':
                displayInventory(library,1);
                break;
            case 'i':
                insertBook(library);
                break;
            case 'r':
                removeBook(library);
                break;
            case 's':
                searchForBook(library);
                break;
            case 'q':
                saveAndExit(library, filename);
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }

    return 0;
}

void showMenu() {
    cout << "\nMenu:" << endl;
    cout << "D - Display inventory" << endl;
    cout << "I - Insert a book" << endl;                    //function to show menu input
    cout << "R - Delete a book" << endl;
    cout << "S - Search for a book"<<endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

void showDisplayMenu() {
    cout << "\nDisplay By:" << endl;
    cout << "T - Title" << endl;                        //gives user option of Display Menu
    cout << "A - Author" << endl;
    cout << "Enter your choice: ";
}

bool sortHelper(char c) 
{
    return (c == 'a' || c == 't');
}

void displayInventory(Library& library,int page) {
    char sortChoice;
    showDisplayMenu();
    cin >> sortChoice;
    cin.ignore();                   // Clear the newline character from the input buffer
    sortChoice = tolower(sortChoice);

    while (!sortHelper(sortChoice)) {
        cout << "Invalid Display option!" << endl;              //error check our sorting option
        cout << endl;
        showDisplayMenu();
        cin >> sortChoice;
    }

    library.sortInventory(sortChoice);                      //print out the inventory
    cout << "Current inventory:" << endl;
    library.displayInventory(page);
}

void insertBook(Library& library) {
    string title, author;
    char genreChar;
    int numCopies;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";                                  //enter in the title, author, genre and num of copies to add to library
    getline(cin, author);
    cout << "Enter book genre (F for Fiction, N for Non-Fiction): ";
    cin >> genreChar;
    cout << "Enter number of copies: ";
    cin >> numCopies;
    Book inputBook(title, author, genreChar, numCopies);

    library.insertBook(inputBook);
    cout << "\nBook inserted successfully!" << endl;
}

void removeBook(Library& library) {
    string title;
    cout << "\nEnter book title to delete: ";                       //enter in the name of book to remove from library system
    getline(cin, title);
    if (library.removeBook(title)) {
        cout << "\nBook deleted successfully!" << endl;
    } else {
        cout << "\nBook not found!" << endl;
    }
}

void saveAndExit(Library& library, string& filename) 
{                                                               //print goodbye message and call the save function
    cout << "\nExiting the program. Goodbye!" << endl;
    library.saveInventory(filename);
}


void searchForBook(Library& library)
{                                                  //function to search for book
    string name;
    cout<<"\nEnter in a Book Title or Author: ";
    getline(cin,name);
    library.searchBook(name);
}
