#include "PhoneBook.h"

PhoneBook::PhoneBook():arrayContacts(nullptr),
                       countContacts(0){}

void PhoneBook::append(const Contact &new_contact)
{
    Contact* new_arrayContacts = new Contact[++countContacts];
    for(int i=0; i<countContacts-1; i++){
        Contact* curContact = &arrayContacts[i];
        new_arrayContacts[i].copy(*curContact);

        //  Удаление контакта из старого массива
        curContact->~Contact();
    }
    new_arrayContacts[countContacts-1].copy(new_contact);
    arrayContacts = new_arrayContacts;
}

void PhoneBook::show() const
{
    for(int i=0; i<countContacts; i++){
        arrayContacts[i].printConsole();
    }
}

unsigned int PhoneBook::getSize() const
{
    unsigned int size{0};
    for(int i=0; i<countContacts; i++)
    {
        size += arrayContacts[i].sizeContact;
    }
    return size;
}

