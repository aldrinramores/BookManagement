#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    int year;
};

int numBooks = 0;
Book library[MAX_BOOKS];

void addBook() {
    if (numBooks == MAX_BOOKS) {
        cout << "Library is full.\n";
        return;
    }
    Book book;
    cout << "Enter book title: ";
    getline(cin, book.title);
    cout << "Enter book author: ";
    getline(cin, book.author);
    cout << "Enter publication year: ";
    cin >> book.year;
    cin.ignore(); // Ignore the newline character left by cin
    library[numBooks++] = book;
    cout << "Book added to library.\n";
}

int findBookIndex(const string& title) {
    for (int i = 0; i < numBooks; i++) {
        if (library[i].title == title) {
            return i;
        }
    }
    return -1;
}

void editBook() {
    string title;
    cout << "Enter book title to edit: ";
    getline(cin, title);
    int index = findBookIndex(title);
    if (index == -1) {
        cout << "Book not found in library.\n";
        return;
    }
    cout << "Enter new book title: ";
    getline(cin, library[index].title);
    cout << "Enter new book author: ";
    getline(cin, library[index].author);
    cout << "Enter new publication year: ";
    cin >> library[index].year;
    cin.ignore(); // Ignore the newline character left by cin
    cout << "Book updated.\n";
}

void deleteBook() {
    string title;
    cout << "Enter book title to delete: ";
    getline(cin, title);
    int index = findBookIndex(title);
    if (index == -1) {
        cout << "Book not found in library.\n";
        return;
    }
    for (int i = index; i < numBooks - 1; i++) {
        library[i] = library[i + 1];
    }
    numBooks--;
    cout << "Book deleted from library.\n";
}

void viewBook() {
    string title;
    cout << "Enter book title to view: ";
    getline(cin, title);
    int index = findBookIndex(title);
    if (index == -1) {
        cout << "Book not found in library.\n";
        return;
    }
    cout << "Title: " << library[index].title << endl;
    cout << "Author: " << library[index].author << endl;
    cout << "Publication year: " << library[index].year << endl;
}

void printLibrary() {
    cout << "Library contents:\n";
    for (int i = 0; i < numBooks; i++) {
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Publication year: " << library[i].year << endl;
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Library Management System\n";
        cout << "-------------------------\n";
        cout << "1. Add book\n";
        cout << "2. Edit book\n";
        cout << "3. Delete book\n";
        cout << "4. View book\n";
        cout << "5. Print library\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character left by cin
    switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            editBook();
            break;
        case 3:
            deleteBook();
            break;
        case 4:
            viewBook();
            break;
        case 5:
            printLibrary();
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
} while (choice != 6);
return 0;

}