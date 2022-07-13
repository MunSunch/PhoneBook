#include <cstring>
#include <iostream>
#include "Contact.h"

const unsigned int BUF_SIZE = 256;
unsigned long Contact::countContacts = 0;

Contact::Contact(const char *name,
                 const char *surname,
                 unsigned long homePhoneNumber,
                 unsigned long workPhoneNumber,
                 unsigned long mobilePhoneNumber,
                 const char *description) : name(new char[BUF_SIZE]),
                                            surname(new char[BUF_SIZE]),
                                            homePhoneNumber(homePhoneNumber),
                                            workPhoneNumber(workPhoneNumber),
                                            mobilePhoneNumber(mobilePhoneNumber),
                                            description(new char[BUF_SIZE])
                                            {
                                              strcpy(this->name, name);
                                              strcpy(this->surname, surname);
                                              strcpy(this->description, description);
                                              id = countContacts++;
                                              sizeContact = sizeof(*this);
                                              isCopy = false;
                                            }
Contact::Contact(const char *name,
                 const char *surname,
                 unsigned long workNumber,
                 const char* description): Contact(name,
                                                   surname,
                                                   0,
                                                   0,
                                                   workNumber,
                                                   description){}
Contact::Contact(const char *name,
                 unsigned long mobilePhoneNumber,
                 const char* description): Contact(name,
                                                   "UNKNOWN",
                                                   0,
                                                   0,
                                                   mobilePhoneNumber,
                                                   description){}
Contact::Contact(const char *name,
                 unsigned long mobilePhoneNumber): Contact(name,
                                                           mobilePhoneNumber,
                                                           "UNKNOWN"){}


Contact::Contact(const Contact& contact): name(new char[BUF_SIZE]),
                                          surname(new char[BUF_SIZE]),
                                          homePhoneNumber(homePhoneNumber),
                                          workPhoneNumber(workPhoneNumber),
                                          mobilePhoneNumber(mobilePhoneNumber),
                                          description(new char[BUF_SIZE])
                                          {
                                                strcpy(name, contact.name);
                                                strcpy(surname, contact.surname);
                                                strcpy(description, contact.description);
                                                id = countContacts++;
                                                sizeContact = sizeof(*this);
                                                isCopy = true;
                                          }

Contact::~Contact()
        {
            delete[] name;
            delete[] surname;
            delete[] description;
        }


void Contact::setName(char *name) {
    delete[] this->name;
    strcpy(this->name, name);
}
void Contact::setSurname(char *surname) {
    delete[] this->surname;
    strcpy(this->surname, surname);
}
void Contact::setHomePhoneNumber(int homePhoneNumber) {
    Contact::homePhoneNumber = homePhoneNumber;
}
void Contact::setWorkPhoneNumber(int workPhoneNumber) {
    Contact::workPhoneNumber = workPhoneNumber;
}
void Contact::setMobilePhoneNumber(int mobilePhoneNumber) {
    Contact::mobilePhoneNumber = mobilePhoneNumber;
}
void Contact::setDescription(char *description) {
    delete[] this->description;
    strcpy(this->description, description);
}


char *Contact::getName() const {
    return name;
}
char *Contact::getSurname() const {
    return surname;
}
int Contact::getHomePhoneNumber() const {
    return homePhoneNumber;
}
int Contact::getWorkPhoneNumber() const {
    return workPhoneNumber;
}
int Contact::getMobilePhoneNumber() const {
    return mobilePhoneNumber;
}
char *Contact::getDescription() const {
    return description;
}


void Contact::printConsole() const {
    const char div[] = ", ";
    const char openBracket = '{';
    const char closeBracket = '}';
    std::cout << openBracket << "id=" << id << div
              << "name=" << name << div
              << "surname=" << surname << div
              << "homePhoneNumber=" << homePhoneNumber << div
              << "workPhoneNumber=" << workPhoneNumber << div
              << "mobilePhoneNumber=" << mobilePhoneNumber << div
              << "description=" << description << closeBracket << std::endl;
}
char* Contact::toString() const{
    char* out = new char[BUF_SIZE];
    strcpy(out, "");

    const char div[] = " ";
    strcat(out, (std::to_string(id)).c_str());
    strcat(out, div);

    strcat(out, name);
    strcat(out, div);

    strcat(out, surname);
    strcat(out, div);

    strcat(out, (std::to_string(homePhoneNumber)).c_str());
    strcat(out, div);

    strcat(out, (std::to_string(workPhoneNumber)).c_str());
    strcat(out, div);

    strcat(out, (std::to_string(mobilePhoneNumber)).c_str());
    strcat(out, div);

    strcat(out, "\"");
    strcat(out, description);
    strcat(out, "\"");
    strcat(out, div);

    strcat(out, (std::to_string(isCopy)).c_str());
    strcat(out, div);

    return out;
}