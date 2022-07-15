#ifndef ____PHONEBOOK_H
#define ____PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
    Contact* arrayContacts;
    unsigned int countContacts;
public:
    PhoneBook();

    void append(const Contact& contact);
    Contact *find(const unsigned long id)
    {
        for(auto ptr = arrayContacts; ptr != arrayContacts+countContacts; ptr++)
        {
            if(ptr->getID() == id)
            {
                return ptr;
            }
        }
        return NULL;
    }
    void remove(const unsigned long id);
    void show() const;
    void printFile(const char* path) const;

    unsigned int getSize() const;
};


#endif //____PHONEBOOK_H
