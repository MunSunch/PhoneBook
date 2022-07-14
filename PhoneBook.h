#ifndef ____PHONEBOOK_H
#define ____PHONEBOOK_H


#include "Contact.h"

class PhoneBook {
    Contact* arrayContacts;
    unsigned int countContacts;
public:
    PhoneBook();
    void append(const Contact& contact);
    char* find(const unsigned int id) const;
    char* find(const char* name, const char* surname) const;
    void sort();
    void remove(const unsigned int id);
    void show() const;
    void printFile(const char* path) const;
    unsigned int getSize() const;
};


#endif //____PHONEBOOK_H
