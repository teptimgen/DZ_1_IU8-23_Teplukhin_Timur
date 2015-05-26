// Copyright 2015 <Timur Teplukhin>
#include "Library.h"

int main() {
    Book temp;
    Library lib("Library #1", "Student books");

    cout << endl << "*** CREATING THREE BOOKS" << endl << endl;

    Book bookOne("Book 1", "Author 1.1", 111, false);
    cout << bookOne << endl;
    lib += bookOne;

    Book bookTwo;
    bookTwo.SetTitle("Book 2");
    bookTwo.SetAuthors("Author 2.1, Author 2.2");
    bookTwo.SetPages(222);
    bookTwo.SetCheckOut(false);
    cout << bookTwo << endl;
    lib.AddBook(bookTwo);

    Book bookThree("Book 3", "Author 3.1", 333, false);
    cout << bookThree << endl;
    lib += bookThree;

    cout << endl << "*** LIBRARY #1:" << endl << lib << endl;

    cout << endl << "*** EDITING THE AUTHORS OF BOOK #2" << endl;
    lib.EditBook(2).SetAuthors("Edited: Author 2.1");
    cout << endl << "*** LIBRARY #1:" << endl << lib << endl;

    try {
        cout << endl << "*** SUCCESSFUL TRYING TO TAKE BOOK #1" << endl;
        lib.TakeBook(1);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** FAILED TRYING TO TAKE BOOK #1" << endl;
        lib.TakeBook(1);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** SUCCESSFUL TRYING TO PASS BOOK #1" << endl;
        lib.PassBook(1);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** FAILED TRYING TO PASS BOOK #1" << endl;
        lib.PassBook(1);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        lib.TakeBook(1);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** SUCCESSFUL REMOVAL OF BOOK #2" << endl;
        lib.RemoveBook(2);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** FAILED REMOVAL OF BOOK #2" << endl;
        lib.RemoveBook(2);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** SEARCH FOR THE BOOK #2" << endl;
        temp = lib.GetBook(2);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** LIBRARY #1:" << endl << lib << endl;

        cout << endl << "*** PRINT BOOK #3 FROM LIBRARY" << endl;
        lib.PrintBook(3);

        cout << endl << "*** REMOVAL OF BOOK #3" << endl;
        lib.RemoveBook(3);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << endl << "*** REMOVAL OF TAKEN BOOK #1" << endl;
        lib.RemoveBook(bookOne);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
    cout << "Book #1 " << ((lib.Has(bookOne)) ?
        "is" : "is not") << " in the library" << endl;
    lib.PassBook(1);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    try {
        cout << "Book #1 " << ((lib.Has(bookOne)) ?
            "is" : "is not") << " in the library" << endl;
        lib.RemoveBook(bookOne);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    cout << endl << "*** LIBRARY #1:" << endl;
    lib.PrintLibrary();
    cout << "Book #1 " << ((lib.Has(bookOne)) ?
        "is" : "is not") << " in the library" << endl;

    try {
        cout << endl << "*** REMOVAL OF NONEXISTENT BOOK #1" << endl;
        lib.RemoveBook(bookOne);
    }
    catch (exception& exc) {
        cout << exc.what() << endl;
    }

    system("pause");
    return 0;
}

