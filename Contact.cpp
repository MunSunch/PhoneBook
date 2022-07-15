#include <cstring>
#include <iostream>
#include "Contact.h"

const unsigned int BUF_SIZE = 256;
unsigned long Contact::var = 0;

Contact::Contact(const char *name,
                 const char *surname,
                 unsigned long long homePhoneNumber,
                 unsigned long long workPhoneNumber,
                 unsigned long long mobilePhoneNumber,
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
                                                  id = var++;
                                                  sizeContact = sizeof(*this);
                                            }
Contact::Contact(const char *name,
                 const char *surname,
                 unsigned long long workNumber,
                 const char* description): Contact(name,
                                                   surname,
                                                   0,
                                                   0,
                                                   workNumber,
                                                   description){}
Contact::Contact(const char *name,
                 unsigned long long mobilePhoneNumber,
                 const char* description): Contact(name,
                                                   "UNKNOWN",
                                                   0,
                                                   0,
                                                   mobilePhoneNumber,
                                                   description){}
Contact::Contact(const char *name,
                 unsigned long long mobilePhoneNumber): Contact(name,
                                                                mobilePhoneNumber,
                                                                "UNKNOWN"){}

Contact::Contact(): Contact("UNKNOWN", 0){}






Contact::Contact(const Contact& contact): name(new char[BUF_SIZE]),
                                          surname(new char[BUF_SIZE]),
                                          homePhoneNumber(contact.homePhoneNumber),
                                          workPhoneNumber(contact.workPhoneNumber),
                                          mobilePhoneNumber(contact.mobilePhoneNumber),
                                          description(new char[BUF_SIZE])
                                          {
                                                strcpy(name, contact.name);
                                                strcpy(surname, contact.surname);
                                                strcpy(description, contact.description);
                                                id = var++;
                                                sizeContact = sizeof(*this);
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
void Contact::setHomePhoneNumber(long long homePhoneNumber) {
    Contact::homePhoneNumber = homePhoneNumber;
}
void Contact::setWorkPhoneNumber(long long workPhoneNumber) {
    Contact::workPhoneNumber = workPhoneNumber;
}
void Contact::setMobilePhoneNumber(long long mobilePhoneNumber) {
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
long long Contact::getHomePhoneNumber() const {
    return homePhoneNumber;
}
long long Contact::getWorkPhoneNumber() const {
    return workPhoneNumber;
}
long long Contact::getMobilePhoneNumber() const {
    return mobilePhoneNumber;
}
char *Contact::getDescription() const {
    return description;
}


void Contact::printConsole() const {
    const char div[] = " ";
    std::cout << id << div
              << name << div
              << surname << div
              << homePhoneNumber << div
              << workPhoneNumber << div
              << mobilePhoneNumber << div
              << description << std::endl;
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

    return out;
}

void Contact::copy(const Contact &contact_src)
{
    delete[] this->name;
    name = new char[BUF_SIZE];
    strcpy(name, contact_src.name);

    delete[] this->surname;
    surname = new char[BUF_SIZE];
    strcpy(surname, contact_src.surname);

    homePhoneNumber = contact_src.homePhoneNumber;
    workPhoneNumber = contact_src.workPhoneNumber;
    mobilePhoneNumber = contact_src.mobilePhoneNumber;

    delete[] this->description;
    description = new char[BUF_SIZE];
    strcpy(description, contact_src.description);
}
