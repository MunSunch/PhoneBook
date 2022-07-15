#include <cstdio>
#include "PhoneBook.h"
#include <iostream>
#include <iomanip>

using std::setw;
using std::left;

PhoneBook::PhoneBook():arrayContacts(nullptr),
                       countContacts(0){}

PhoneBook::PhoneBook(Contact *arr,
                     const unsigned int sizeArr): arrayContacts(new Contact[sizeArr]),
                                                  countContacts(sizeArr)
                                                  {
                                                      for(int i=0; i<countContacts; i++)
                                                      {
                                                          arrayContacts[i].copy(arr[i]);
                                                      }
                                                  }



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

bool PhoneBook::remove(const unsigned long id)
{
    auto ptr = find(id);
    if(ptr != NULL) {
        (*ptr).copy(arrayContacts[countContacts - 1]);
        arrayContacts[countContacts - 1].~Contact();
        countContacts--;
        return true;
    }
    return false;
}

void PhoneBook::show() const
{
    const char div[]{" "};
    const char tab_tab{'='};
    const int tab_id{3};
    const int tab_name{20};
    const int tab_surname{20};
    const int tab_homePhoneNumber{20};
    const int tab_workPhoneNumber{20};
    const int tab_mobilePhoneNumber{20};
    const int tab_description{50};
    std::cout << left << setw(tab_id) << "ID" << div
              << left << setw(tab_name) << "NAME" << div
              << left << setw(tab_surname) << "SURNAME" << div
              << left << setw(tab_homePhoneNumber) << "HOME_PHONE_NUMBER" << div
              << left << setw(tab_workPhoneNumber) << "WORK_PHONE_NUMBER" << div
              << left << setw(tab_mobilePhoneNumber) << "MOBILE_PHONE_NUMBER" << div
              << left << setw(tab_description) << "DESCRIPTION" << std::endl;
    int tab_ = tab_id+tab_description+tab_homePhoneNumber+tab_mobilePhoneNumber+tab_name+tab_surname+tab_workPhoneNumber;
    while(tab_)
    {
        std::cout << tab_tab;
        tab_--;
    }
    std::cout << std::endl;

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

void PhoneBook::printFile(const char* path) const
{
    FILE* out = fopen(path, "w");
    const char* format = "%u. {id = %u, name = %s, surname = %s, homeNumber = %lu, workNumber = %lu, mobileNumber = %lu, description = %s} \n";
    for(int i=0; i<countContacts; i++)
    {
        fprintf(out, format, i+1,
                             arrayContacts[i].getID(),
                             arrayContacts[i].getName(),
                             arrayContacts[i].getSurname(),
                             arrayContacts[i].getHomePhoneNumber(),
                             arrayContacts[i].getWorkPhoneNumber(),
                             arrayContacts[i].getMobilePhoneNumber(),
                             arrayContacts[i].getDescription());
    }
    fclose(out);
}