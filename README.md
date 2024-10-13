# Library Management System

## Overview
This project is a simple library management system implemented in C++. It allows users to manage a collection of books, including adding, removing, displaying, and searching for books. The system also supports pagination for displaying the inventory and saves the inventory to a file for persistence.

## Features
- **Add Books**: Insert new books into the library.
- **Remove Books**: Delete books from the library by title.
- **Display Inventory**: View the current inventory of books with pagination.
- **Search Books**: Search for books by title or author.
- **Save and Load Inventory**: Save the library inventory to a file and load it back when the program starts.

## Classes and Methods

### Book Class
- **Book(string t, string a, char g, int n)**: Constructor to initialize a book with title, author, genre, and number of copies.
- **string getTitle() const**: Returns the title of the book.
- **string getAuthor() const**: Returns the author of the book.
- **Genre getGenre() const**: Returns the genre of the book.
- **int getNumCopies() const**: Returns the number of copies available.

### Library Class
- **Library()**: Constructor to initialize the library.
- **void insertBook(Book& book)**: Adds a book to the library.
- **bool removeBook(string name)**: Removes a book by title.
- **void displayInventory(int page = 1) const**: Displays the inventory with pagination.
- **void sortInventory(char c)**: Sorts the inventory by title or author.
- **void saveInventory(string& filename) const**: Saves the inventory to a file.
- **void loadInventory(string& filename)**: Loads the inventory from a file.
- **void searchBook(string& query) const**: Searches for books by title or author.

## How to Run
1. **Clone the repository**:
    ```sh
    git clone https://github.com/nowtestify24/library-management-system.git
    cd library-management-system
    ```

2. **Compile the code**:
    ```sh
    g++ -std=c++11 -c Library.cpp
    g++ -std=c++11 -c LibraryDriver.cpp
    g++ -std=c++11 -o libraryProgram.exe Library.o LibraryDriver.o
    ```

3. **Run the program**:
    ```sh
    ./libraryProgram.exe
    ```

## Usage
- **D**: Display inventory
- **I**: Insert a book
- **R**: Delete a book
- **S**: Search for a book
- **Q**: Quit and save inventory

## Example
```sh
Menu:
D - Display inventory
I - Insert a book
R - Delete a book
S - Search for a book
Q - Quit

Enter your choice: I
Enter book title: Harry Potter and Chamber of Secrets
Enter book author: JK Rowling
Enter book genre (F for Fiction, N for Non-Fiction): F
Enter number of copies: 3

Book inserted successfully!

Menu:
D - Display inventory
I - Insert a book
R - Delete a book
S - Search for a book
Q - Quit

Enter your choice: D

Display By:
T - Title
A - Author
Enter your choice: A
Current inventory:


Page 1
Star Wars by George Lucas - 1 copies available
Harry Potter and Sorcerer's Stone by JK Rowling - 1 copies available
Harry Potter and Chamber of Secrets by JK Rowling - 3 copies available

Enter 'n' for next page, 'p' for previous page, or 'q' to quit: q

Menu:
D - Display inventory
I - Insert a book
R - Delete a book
S - Search for a book
Q - Quit

Enter your choice: q

Exiting the program. Goodbye!
