// Copyright 2015 <Timur Teplukhin>
#include "Library.h"
#include <string>
#include <list>

Library::Library() {
    name = string();
    type = string();
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

bool Library::Has(const Book& book) const {
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (*iter == book)
            return true;
    return false;
}

int Library::GetSize() const {
    return this->size();
}

void Library::AddBook(const Book& book) {
    this->emplace_back(book);
    EditBook(0).SetId(++maxId);
}

void Library::RemoveBook(int id) {
    Book temp = GetBook(id);
    RemoveBook(temp);
}

void Library::RemoveBook(const Book& book) {
    Book temp = book;
    list<Book>::const_iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if (*iter == temp) {
            if ((*iter).GetCheckOut() == false) {
                this->erase(iter);
                throw SuccessfulRemovalMessage(temp.GetTitle());
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
        if ((*iter).GetId() == id)
            return *iter;
    throw NotFoundException(id);
}

Book& Library::EditBook(int id) {
    list<Book>::iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if ((*iter).GetId() == id)
            return *iter;
    throw NotFoundException(id);
}

void Library::TakeBook(int id) {
    list<Book>::iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if ((*iter).GetId() == id) {
            if ((*iter).GetCheckOut() == false) {
                ++countCheckedOut;
                (*iter).SetCheckOut(true);
                throw SuccessfulTakingMessage(id);
                return;
            } else {
                throw FailedTakingException(id);
                return;
            }
        }
    throw NotFoundException(id);
}

void Library::PassBook(int id) {
    list<Book>::iterator iter = this->begin();
    for (; iter != this->end(); ++iter)
        if ((*iter).GetId() == id) {
            if ((*iter).GetCheckOut() == true) {
                --countCheckedOut;
                (*iter).SetCheckOut(false);
                throw SuccessfulPassingMessage(id);
                return;
            } else {
                throw FailedPassingException(id);
                return;
            }
        }
    throw NotFoundException(id);
}

void Library::PrintBook(int id) {
    Book temp = GetBook(id);
    cout << "id:............." << temp.GetId() << endl;
    cout << "Title:.........." << temp.GetTitle().c_str() << endl;
    cout << "Authors:........" << temp.GetAuthors().c_str() << endl;
    cout << "Pages:.........." << temp.GetPages() << endl;
    cout << "Status:........." << ((temp.GetCheckOut()) ?
        "Taken" : "Available") << endl;
}

void Library::PrintLibrary() {
    cout << "Lib title:......" << GetName().c_str() << endl;
    cout << "Lib type:......." << GetType().c_str() << endl;
    cout << "Books:.........." << GetSize() << endl;
    cout << "Taken books:...." << GetCountCheckedOut() << endl;
    std::list<Book>::const_iterator iter = begin();
    for (; iter != end(); ++iter)
        cout << endl << *iter;
}

ostream& operator<<(ostream& os, const Library& lib) {
    os << "Lib title:......" << lib.name.c_str() << endl;
    os << "Lib type:......." << lib.type.c_str() << endl;
    os << "Books:.........." << lib.GetSize() << endl;
    os << "Taken books:...." << lib.countCheckedOut << endl;
    std::list<Book>::const_iterator iter = lib.begin();
    for (; iter != lib.end(); ++iter)
        os << endl << *iter;
    return os;
}

Library& Library::operator+=(const Book& book) {
    AddBook(book);
    return *this;
}

