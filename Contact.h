#ifndef ____CONTACT_H
#define ____CONTACT_H


class Contact {
    char* name;
    char* surname;

    int homePhoneNumber;
    int workPhoneNumber;
    int mobilePhoneNumber;

    char* description;
public:
    Contact(char *name, char *surname, int homePhoneNumber, int workPhoneNumber, int mobilePhoneNumber,
            char *description);
    Contact(char *name, char *surname, int workNumber, char* description);


};


#endif //____CONTACT_H
