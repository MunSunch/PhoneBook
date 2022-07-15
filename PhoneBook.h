#ifndef ____PHONEBOOK_H
#define ____PHONEBOOK_H

#include <cstring>
#include "Contact.h"

class PhoneBook {
    Contact* arrayContacts;
    unsigned int countContacts;
public:
    PhoneBook(Contact *arr, const unsigned int sizeArr);
    PhoneBook();

    unsigned int getCountContacts() const { return countContacts; }

    void append(const Contact& contact);

    Contact *find(const unsigned long id)
    {
        for(auto ptr = arrayContacts; ptr != arrayContacts+countContacts; ptr++) {
            if(ptr->getID() == id) {
                return ptr;
            }
        }
        return NULL;
    }
    Contact *find(const char* name)
    {
        for(auto ptr = arrayContacts; ptr != arrayContacts+countContacts; ptr++) {
            if(strcmp(ptr->getName(), name) == 0) {
                return ptr;
            }
        }
        return NULL;
    }


    bool remove(const unsigned long id);
    void show() const;
    void printFile(const char* path) const;

    unsigned int getSize() const;
};


#endif //____PHONEBOOK_H
