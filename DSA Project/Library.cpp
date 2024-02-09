#include "Library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

Library::Library() {}

// Method to insert a new book into the library
void Library::insertBook()
{

    // Prompt the user for book details
    cout << "Enter book's ID (max 6 numbers): ";
    cin.ignore();
    getline(cin, book.id);

    cout << "Enter book's title (use '_' for space): ";
    getline(cin, book.title);
    transform(book.title.begin(), book.title.end(), book.title.begin(), ::toupper); // Convert title to uppercase

    cout << "Enter book's author (use '_' for space): ";
    getline(cin, book.author);
    transform(book.author.begin(), book.author.end(), book.author.begin(), ::toupper); // Convert author to uppercase

    /* Open the file for appending and write book details */ 
    ofstream file_out;
    file_out.open("C:\\Users\\afnan\\Downloads\\databook.txt", ofstream::out | ofstream::app); // PLEASE CHANGE FILE PATH 

    file_out << book.id << "\n" << book.title << "\n" << book.author << endl;

    if (!file_out)
    {
        cout << "\nError while inserting book =( " << endl;
    }
    else
    {
        cout << "\nBook inserted successfully !" << endl;
    }

    file_out.close();
}

// Method to display all books in the library
void Library::displayBooks()
{
    ifstream file_in;
    file_in.open("C:\\Users\\afnan\\Downloads\\databook.txt"); // PLEASE CHANGE FILE PATH 

    if (file_in.fail()) // Check if the file opening fails
    {
        cout << "\nError opening file =(" << endl;
        exit(1);
    }

    cout << "\n\n\n+++++++++++++++     BOOK LIST     +++++++++++++++\n";

    while (file_in >> book.id >> book.title >> book.author)
    {
        // Display book details in a formatted way
        cout << setw(96) << setfill('-') << endl;
        cout << "\n| ID: " << setw(6) << setfill('0') << book.id << " | TITLE: " << book.title << " | AUTHOR: " << book.author << " |";
    }
    cout << setw(139) << setfill('-') << endl;

    file_in.close();
}

// Method to read book data from the file and populate a vector
void Library::fileToVector()
{
    ifstream copy("C:\\Users\\afnan\\Downloads\\databook.txt"); // PLEASE CHANGE FILE PATH 

    string id;
    string title;
    string author;


    while (copy >> id >> title >> author)
    {
        // Create Book objects and add them to the 'books' vector
        Book book = { id, title, author };
        books.push_back(book);
    }
    copy.close();
}

// Function to compare two books by their titles (used for sorting)
bool Library::compareBook(const Book& a, const Book& b)
{
    return a.title < b.title;
}

// Quick sort partition function for sorting books by title
int Library::partition(vector<Book>& books, int low, int high)
{
    Book pivot = books[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (compareBook(books[j], pivot))
        {
            i++;
            swap(books[i], books[j]);
        }
    }
    swap(books[i + 1], books[high]);
    return (i + 1);
}

// Quick sort algorithm to sort books by title
void Library::quickSort(vector<Book>& books, int low, int high)
{
    if (low < high)
    {
        int pi = partition(books, low, high);

        quickSort(books, low, pi - 1);
        quickSort(books, pi + 1, high);
    }
}

// Method to sort books by title and display them
void Library::sortBook()
{
    quickSort(books, 0, books.size() - 1);
}

// Display sorted book
void Library::showSortedBook()
{
    sortBook(); // call sortBook function

    for (int i = 0; i < books.size(); i++)
    {
        // Display sorted books in a formatted way
        cout << setw(115) << setfill('-') << endl;
        cout << "\n| ID: " << setw(6) << setfill('0') << books[i].id << " | TITLE: " << books[i].title << " | AUTHOR: " << books[i].author << " | ISSUED: " << (books[i].issued ? "Yes" : "No") << " |";
    }
    cout << setw(159) << setfill('-') << endl;

    cout << "\n\n++++++++++  BOOKS SORTED SUCCESSFULLY ++++++++++\n";
}

// Binary search for a book by title
int Library::binarySearch(string title, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (books[mid].title == title)
            return mid;

        if (books[mid].title > title)
            return binarySearch(title, low, mid - 1);
        return binarySearch(title, mid + 1, high);
    }
    return -1;
}

// Sentinel search for a book by author
int Library::sentinelSearch(string author)
{
    int n = books.size();
    if (n == 0)
        return -1;

    string lastAuthor = books[n - 1].author;
    books[n - 1].author = author; // Set the last element as the sentinel

    int i = 0;
    while (books[i].author != author)
    {
        i++;
    }
    books[n - 1].author = lastAuthor; // Restore the last element

    if (i < n - 1 || books[n - 1].author == author)
    {
        return i; // Book found
    }
    return -1; // Book not found
}

// Method to search for a book by title or author
void Library::searchBook()
{
    int option, result;
    string title, author;

    do
    {
        cout << "\nBinary Search by title [0] | Sentinel Search by author [1] " << endl;
        cout << "Select an option : ";
        cin >> option;

        if (option == 0) // Search book's title using binary search
        {
            cout << "\nEnter book's title: ";
            cin.ignore();
            getline(cin, title);
            transform(title.begin(), title.end(), title.begin(), ::toupper); // Convert title to uppercase

            result = binarySearch(title, 0, books.size() - 1);

            if (result == -1)
                cout << "\nBook not found :(" << endl;
            else
            {
                cout << "\nBook found !" << endl;
                cout << setw(56) << setfill('-') << endl;
                cout << "\n| ID: " << setw(6) << setfill('0') << books[result].id << " | TITLE: " << books[result].title << " | AUTHOR: " << books[result].author << " |";
                cout << setw(99) << setfill('-') << endl;
            }
        }
        else if (option == 1) // Search book's author using sentinel search
        {
            cout << "\nEnter book's author: ";
            cin.ignore();
            getline(cin, author);
            transform(author.begin(), author.end(), author.begin(), ::toupper); // Convert author to uppercase

            result = sentinelSearch(author);

            if (result == -1)
                cout << "\nBook not found :(" << endl;
            else
            {
                cout << "\nBook found !" << endl;
                cout << setw(56) << setfill('-') << endl;
                cout << "\n| ID: " << setw(6) << setfill('0') << books[result].id << " | TITLE: " << books[result].title << " | AUTHOR: " << books[result].author;
                cout << setw(99) << setfill('-') << endl;
            }
        }
        else
        {
            cout << "Error! " << endl;
        }
    } while (option != 0 && option != 1);
}

 //Method to mark a book as issued
void Library::issueBook()
{
    string id;
    cout << "Enter book's ID: ";
    cin.ignore();
    getline(cin, id);

    for (auto& book : books)
    {
        if (book.id == id)
        {
            if (book.issued == false)
            {
                book.issued = true;
                for (int i = 0; i < books.size(); i++)
                {
                    cout << setw(115) << setfill('-') << endl;
                    cout << "\n| ID: " << setw(6) << setfill('0') << books[i].id << " | TITLE: " << books[i].title << " | AUTHOR: " << books[i].author << " | ISSUED: " << (books[i].issued ? "Yes" : "No") << " |";
                }
                cout << setw(135) << setfill('-') << endl;
                cout << "\nBook issued successfully.\n";
                return;
            }
            else
            {
                cout << "\nBook is already issued." << endl;
                return;
            }
        }
    }
    cout << "Book not found :(\n";
}

// Method to mark a book as returned
void Library::returnBook()
{
    string id;
    cout << "Enter book's ID: ";
    cin.ignore();
    getline(cin, id);

    for (auto& book : books)
    {
        if (book.id == id)
        {
            if (book.issued == true)
            {
                book.issued = false;
                for (int i = 0; i < books.size(); i++)
                {
                    cout << setw(120) << setfill('-') << endl;
                    cout << "\n| ID: " << setw(6) << setfill('0') << books[i].id << " | TITLE: " << books[i].title << " | AUTHOR: " << books[i].author << " | ISSUED: " << (books[i].issued ? "Yes" : "No") << " |";
                }
                cout << setw(120) << setfill('-') << endl;
                cout << "\nBook returned successfully.\n";
                return;
            }
            else
            {
                cout << "\nBook is already returned." << endl;
                return;
            }
        }
    }
    cout << "Wrong book ID.\n";
}

// Method to display information about issued books
void Library::displayIssuedBook()
{
    bool checkBook = false;

    for (const auto& b : books)
    {
        if (b.issued)
        {
            checkBook = true;
            cout << setw(96) << setfill('-') << endl;
            cout << "\n| ID: " << setw(6) << setfill('0') << b.id << " | TITLE: " << b.title << " | AUTHOR: " << b.author << " |";
        }
    }
    cout << setw(139) << setfill('-') << endl;

    if (!checkBook)
        cout << "No issued book yet." << endl;
}


