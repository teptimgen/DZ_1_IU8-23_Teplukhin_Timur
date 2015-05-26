// Copyright 2015 <Timur Teplukhin>

#include "Exceptions.h"
#include <string>

using std::to_string;


NotFoundException::NotFoundException(const string& title) : exception() {
    errMsg = "Cannot find the book (title '" + title + "')";
}

NotFoundException::NotFoundException(int id) : exception() {
    errMsg = "Cannot find the book (id " + to_string(id) + ")";
}

const char* NotFoundException::what() const {
    return errMsg.c_str();
}


RemovalOfTakenException::RemovalOfTakenException(const string& title) :
        exception() {
    errMsg = "Cannot remove a taken book (title '" + title + "')";
}

RemovalOfTakenException::RemovalOfTakenException(int id) : exception() {
    errMsg = "Cannot remove a taken book (id " + to_string(id) + ")";
}

const char* RemovalOfTakenException::what() const {
    return errMsg.c_str();
}


FailedTakingException::FailedTakingException(int id) : exception() {
    errMsg = "Cannot take the book (id " + to_string(id) + ")";
}

const char* FailedTakingException::what() const {
    return errMsg.c_str();
}


FailedPassingException::FailedPassingException(int id) : exception() {
    errMsg = "Cannot pass the book (id " + to_string(id) + ")";
}

const char* FailedPassingException::what() const {
    return errMsg.c_str();
}


SuccessfulRemovalMessage::SuccessfulRemovalMessage(const string& title) :
        exception() {
    errMsg = "The book has been removed (title '" + title + "')";
}

const char* SuccessfulRemovalMessage::what() const {
    return errMsg.c_str();
}


SuccessfulTakingMessage::SuccessfulTakingMessage(int id) : exception() {
    errMsg = "The book has been taken (id " + to_string(id) + ")";
}

const char* SuccessfulTakingMessage::what() const {
    return errMsg.c_str();
}


SuccessfulPassingMessage::SuccessfulPassingMessage(int id) : exception() {
    errMsg = "The book has been passed (id " + to_string(id) + ")";
}

const char* SuccessfulPassingMessage::what() const {
    return errMsg.c_str();
}

