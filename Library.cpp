#include "Library.h"

Book::Book(string t, string a, char g,int n)
{
    if(numCopies<=0)
    {
        numCopies=1;
    }
    else
    {
        numCopies=n;
    }
    if (g == 'F' || g == 'f')
    {
        genre = Fiction;                                //choose genre of the book
    }
    else if (g == 'N' || g == 'n')
    {
        genre = NonFiction;
    }
    else
    {
        genre = Fiction;
    }
    author = a;
    title = t;
}

string Book::getTitle() const
{  return title;    }
string Book::getAuthor() const
{   return author;  }                           //accessor definitions for our Book class member data

genre Book::getGenre() const
{   return genre;   }

int Book::getNumCopies() const
{return numCopies;}

Library::Library()
{
                        // Library Constructor
}

void Library::insertBook(Book& book)
{   books.push_back(book);  }

bool Library::removeBook(string name)
{
    for (auto itr = books.begin(); itr != books.end(); itr++)
    {
        Book myBook = *itr;
        if (myBook.getTitle() == name)                  //loop through the books we have and if we find it, remove it from our vector
        {
            books.erase(itr);
            return true;
        }
    }
    return false;                       //return false, letting user know the book wasn't found and thus wasn't removed
}

void Library::displayInventory(int page) const 
{
    const int itemsPerPage = 3;
    int totalPages = (books.size() + itemsPerPage - 1) / itemsPerPage;
   
    int start = (page - 1) * itemsPerPage;
    int end = std::min(start + itemsPerPage, static_cast<int>(books.size()));

    if (books.empty()) 
    {
        std::cout << "\nLibrary Inventory is Empty!" << std::endl;
        return;
    }

                                                    
    streamsize prevPrecision = cout.precision();    // Set the new precision and save old one
    cout <<fixed << setprecision(2);
    cout<<'\n';
    for (int i = start; i < end; ++i) 
    {
        if(totalPages>1 && i==start)
        {
            cout<<"\nPage "<<page<<endl;
        }
        
        const Book& book = books[i];
        cout << book.getTitle() << " by " << book.getAuthor()
                  << " - " << book.getNumCopies() << " copies available" << endl;
    }

    // Restore the previous precision
    cout.precision(prevPrecision);
    if (end < books.size() || start > 0) 
    {
        cout << "\nEnter 'n' for next page, 'p' for previous page, or 'q' to quit: ";
        char choice;
        cin >> choice;
        choice = tolower(choice); // Convert choice to lowercase for consistency

        // Error checking for valid input
        while (choice != 'n' && choice != 'p' && choice != 'q') 
        {
            cout << "\nInvalid input! Please enter 'n' for next page, 'p' for previous page, or 'q' to quit: ";
            cin >> choice;
            choice = tolower(choice);
        }

        if (choice == 'n' && end < books.size()) {
            displayInventory(page + 1);
        } else if (choice == 'p' && start > 0) {
            displayInventory(page - 1);
        }
    }
}


bool compareByTitle(const Book& a, const Book& b)
{
    return a.getTitle() < b.getTitle();
}                                                               //comparison functions used in sorting our inventory

bool compareByAuthor(const Book& a, const Book& b)
{
    return a.getAuthor() < b.getAuthor();
}

string toLower(const string str) 
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Library::sortInventory(char c)
{
    if (c == 'T' || c == 't')
    {
        sort(books.begin(), books.end(), compareByTitle);
    }
    else if (c == 'a' || c == 'A')
    {
        sort(books.begin(), books.end(), compareByAuthor);
    }
}


void Library::saveInventory(string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) 
    {                                           //if theres an error in saving, let user know
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (const auto& book : books) 
    {                                       //print out the updated library to the user
        outFile << book.getTitle() << '\n'
                << book.getAuthor() << '\n'
                << book.getGenre() << '\n'
                <<book.getNumCopies()<< '\n';
    }
    outFile.close();
}

void Library::loadInventory(string& filename) 
{
    std::ifstream inFile(filename);
    if (!inFile) 
    {
        std::cerr << "Error opening file for reading: " << filename << std::endl;               //if there's no file to load from, inform user 
        return;
    }
    string title, author;
    char genreChar;
    int numCopies;
    while (getline(inFile, title) && getline(inFile, author) && inFile >> genreChar && inFile >>numCopies) 
    {
        inFile.ignore(); // Ignore the newline character after genreChar
        Book book(title, author, genreChar, numCopies);                         //read in each line and make our book objects and 
        books.push_back(book);                                                  //insert them into the books vector. 
    }
    inFile.close();
}

void Book::checkOut() 
{
    if (numCopies > 0)                 //check out our book in the system
    {
        numCopies--;
        available = (numCopies > 0);
    }
}

void Book::returnBook() {
    numCopies++;                    //return our book in the system
    available = true;
}


void Library::searchBook(string& query) const 
{
    bool found = false;                     //boolean to check if we found our book our not;
    for (auto book : books) 
    {
            string authorName=toLower(book.getAuthor());
            string bookTitle=toLower(book.getTitle());
        if (bookTitle.find(query)!= string::npos || authorName.find(query)!=string::npos) 
        {
            cout << book.getTitle() << " by " << book.getAuthor()                           //print out matching title or author. 
                      << " - " << book.getNumCopies() << " copies available" << std::endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "No books found matching the query: " << query << endl;
    }
}
