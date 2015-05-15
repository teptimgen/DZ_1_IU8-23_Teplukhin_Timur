// Copyright 2015 <Timur Teplukhin>
#include "Library.h"
#include <string>
#include <list>

Library::Library() {
    name = "\0";
    type = "\0";
    countCheckedOut = 0;
    maxId = 0;
}

Library::Library(const string& name, const string& type) {
    this->name = name;
    this->type = type;
    countCheckedOut = 0;
    maxId = 0;
}

Library::~Library() {
    name = "\0";
    type = "\0";
    countCheckedOut = 0;
    maxId = 0;
}

void Library::SetName(const string& name) {
    this->name = name;
}

const string& Library::GetName() const {
    return name;
}

void Library::SetType(const string& type) {
    this->type = type;
}

const string& Library::GetType() const {
    return type;
}

void Library::SetCountCheckedOut(int countCheckedOut) {
    this->countCheckedOut = countCheckedOut;
}

int Library::GetCountCheckedOut() const {
    return countCheckedOut;
}

int Library::Has(const Book& book) const {
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (iter._Ptr->_Myval == book)
            return TRUE;
    return FALSE;
}

int Library::GetSize() const {
    return this->size();
}

void Library::AddBook(Book book) {
    book.SetId(++maxId);
    this->emplace_back(book);
}

void Library::RemoveBook(int id) {
    Book temp = GetBook(id);
    if (&temp != NULL) {
        list<Book>::const_iterator iter = this->begin();
        for (; iter != this->end(); ++iter)
            if (iter._Ptr->_Myval.GetId() == id) {
                if (iter._Ptr->_Myval.GetCheckOut() == FALSE) {
                    this->erase(iter);
                    cout << "The book has been removed" << endl;
                    return;
                } else {
                    throw RemovalOfTakenException(id);
                }
            }
    } else {
        throw NotFoundException(id);
    }
}

void Library::RemoveBook(const Book& book) {
    Book temp = book;
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (iter._Ptr->_Myval == temp) {
            if (iter._Ptr->_Myval.GetCheckOut() == FALSE) {
                this->erase(iter);
                cout << "The book has been removed" << endl;
                return;
            } else {
                throw RemovalOfTakenException(temp.GetTitle());
            }
        }
    throw NotFoundException(temp.GetTitle());
}

const Book& Library::GetBook(int id) const {
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (iter._Ptr->_Myval.GetId() == id)
            return iter._Ptr->_Myval;
    throw NotFoundException(id);
}

void Library::TakeBook(int id) {
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (iter._Ptr->_Myval.GetId() == id) {
            if (iter._Ptr->_Myval.GetCheckOut() == FALSE) {
                ++countCheckedOut;
                iter._Ptr->_Myval.SetCheckOut(TRUE);
                cout << "The book has been taken" << endl;
                return;
            } else {
                cout << "Cannot take the book" << endl;
                return;
            }
        }
    throw NotFoundException(id);
}

void Library::PassBook(int id) {
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (iter._Ptr->_Myval.GetId() == id) {
            if (iter._Ptr->_Myval.GetCheckOut() == TRUE) {
                --countCheckedOut;
                iter._Ptr->_Myval.SetCheckOut(FALSE);
                cout << "The book has been passed" << endl;
                return;
            } else {
                cout << "Cannot pass the book" << endl;
                return;
            }
        }
    throw NotFoundException(id);
}

void Library::PrintBook(int id) {
    Book temp = GetBook(id);
    if (&temp != NULL) {
        cout << "id:............." << temp.GetId() << endl;
        cout << "Title:.........." << temp.GetTitle().c_str() << endl;
        cout << "Authors:........" << temp.GetAuthors().c_str() << endl;
        cout << "Pages:.........." << temp.GetPages() << endl;
        cout << "Status:........." << ((temp.GetCheckOut()) ?
            "Taken" : "Available") << endl;
    } else {
        throw NotFoundException(id);
    }
}

void Library::PrintLibrary() {
    cout << "Lib title:......" << GetName().c_str() << endl;
    cout << "Lib type:......." << GetType().c_str() << endl;
    cout << "Books:.........." << GetSize() << endl;
    cout << "Taken books:...." << GetCountCheckedOut() << endl;
    std::list<Book>::const_iterator iter = begin();
    for (; iter != end(); ++iter)
        cout << endl << iter._Ptr->_Myval;
}

ostream& operator<<(ostream& os, const Library& lib) {
    os << "Lib title:......" << lib.name.c_str() << endl;
    os << "Lib type:......." << lib.type.c_str() << endl;
    os << "Books:.........." << lib.GetSize() << endl;
    os << "Taken books:...." << lib.countCheckedOut << endl;
    std::list<Book>::const_iterator iter = lib.begin();
    for (; iter != lib.end(); ++iter)
        os << endl << iter._Ptr->_Myval;
    return os;
}

Library& Library::operator+=(const Book& book) {
    AddBook(book);
    return *this;
}
