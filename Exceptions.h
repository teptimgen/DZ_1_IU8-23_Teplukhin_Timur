// Copyright 2015 <Timur Teplukhin>
#pragma once

#include "Headers.h"
#include <string>

class NotFoundException : public exception {
    string errMsg;
 public:
    explicit NotFoundException(const string&);
    explicit NotFoundException(int id);
    const char* what() const throw();
};

class RemovalOfTakenException : public exception {
    string errMsg;
 public:
    explicit RemovalOfTakenException(const string&);
    explicit RemovalOfTakenException(int id);
    const char* what() const throw();
};

class FailedTakingException : public exception {
    string errMsg;
 public:
    explicit FailedTakingException(int id);
    const char* what() const throw();
};

class FailedPassingException : public exception {
    string errMsg;
 public:
    explicit FailedPassingException(int id);
    const char* what() const throw();
};

class SuccessfulRemovalMessage : public exception {
    string errMsg;
 public:
    explicit SuccessfulRemovalMessage(const string&);
    const char* what() const throw();
};

class SuccessfulTakingMessage : public exception {
    string errMsg;
 public:
    explicit SuccessfulTakingMessage(int id);
    const char* what() const throw();
};

class SuccessfulPassingMessage : public exception {
    string errMsg;
 public:
    explicit SuccessfulPassingMessage(int id);
    const char* what() const throw();
};

