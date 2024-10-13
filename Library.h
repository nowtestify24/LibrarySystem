#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum genre { Fiction, NonFiction };             //enum for book genre

class Book {
public:
    Book(string t, string a, char g, int numCopies);  //constructor
    std::string getTitle() const;
    std::string getAuthor() const;              //accessors for member data
    genre getGenre() const;
    int getNumCopies() const;
    bool isAvailable() const;
    void checkOut();                        //functions for checkingOut and returning book. 
    void returnBook();

private:
    std::string title;
    std::string author;
    genre genre;
    int numCopies;
    bool available;
};

class Library
{
    public: 
        Library();
        void insertBook(Book& book);
        bool removeBook(string bookName);
        void displayInventory(int page) const;
        void sortInventory(char c);
        void loadInventory(string& filename);
        void saveInventory(string & filename) const;
        void searchBook(string& query) const;


    private:
        vector<Book> books;
};
