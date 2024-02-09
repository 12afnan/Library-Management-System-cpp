#include "Library.h" 
#include <iostream> 
#include <fstream> 

using namespace std; 

void main()
{
    Library library; 

    int choice, option;
    string title;

    library.fileToVector(); // Call the fileToVector function to insert all data from file into vector

    cout << R"(
                                                                                                           
 __    _ _                      _____                                   _      _____         _             
|  |  |_| |_ ___ ___ ___ _ _   |     |___ ___ ___ ___ ___ _____ ___ ___| |_   |   __|_ _ ___| |_ ___ _____ 
|  |__| | . |  _| .'|  _| | |  | | | | .'|   | .'| . | -_|     | -_|   |  _|  |__   | | |_ -|  _| -_|     |
|_____|_|___|_| |__,|_| |_  |  |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|    |_____|_  |___|_| |___|_|_|_|
                        |___|                    |___|                              |___|                  
)";
    while (true) 
    {
        library.sortBook(); 

        /* Display the menu options */ 
        cout << "\n\n+++++++++++++++     M E N U     +++++++++++++++\n";
        cout << "\n1. Display Books\n"; 
        cout << "2. Insert Book\n";
        cout << "3. Sort Books (Quick Sort)\n";
        cout << "4. Search Book (Binary / Sentinel Search)\n";
        cout << "5. Issue Book (By Book ID)\n";
        cout << "6. Return Book (By Book ID)\n";
        cout << "7. Display Issued Books\n";
        cout << "8. Exit\n";
        cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "\nSelect an option (1-8): ";
        cin >> choice; // Take user input for the menu choice

        /* Use a switch case to perform actions based on the user's choice */ 
        switch (choice)
        {
        case 1:
            // If the user chooses option 1, display the list of books
            library.displayBooks();
            break;

        case 2:
            // If the user chooses option 2, insert a new book
            cout << "\n\n+++++++++++++++     INSERT A BOOK     +++++++++++++++\n";
            library.insertBook();

            library.books.clear(); // Emptying existing vector
            library.fileToVector(); 
            break;

        case 3:
            // If the user chooses option 3, sort the books
            cout << "\n\n+++++++++++++++     SORT BOOKS     +++++++++++++++\n";
            library.showSortedBook();
            break;

        case 4:
            // If the user chooses option 4, search for a book
            cout << "\n\n+++++++++++++++     SEARCH A BOOK     +++++++++++++++\n";
            library.searchBook();
            break;

        case 5:
            // If the user chooses option 5, issue a book
            cout << "\n\n+++++++++++++++     ISSUE A BOOK     +++++++++++++++\n";
            library.issueBook();
            break;

        case 6:
            // If the user chooses option 6, return a book
            cout << "\n\n+++++++++++++++     RETURN A BOOK     +++++++++++++++\n";
            library.returnBook();
            break;

        case 7:
            // If the user chooses option 7, display the issued books
            cout << "\n\n+++++++++++++++      ISSUED BOOKS     +++++++++++++++\n";
            library.displayIssuedBook();
            break;

        case 8:
            // If the user chooses option 8, exit the program
            cout << "Exiting program." << endl;
            exit(0);

        default:
            // If the user enters an invalid choice, display an error message
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
}
