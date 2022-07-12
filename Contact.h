#ifndef ____CONTACT_H
#define ____CONTACT_H


class Contact {
    char* name;
    char* surname;

    unsigned long homePhoneNumber;
    unsigned long workPhoneNumber;
    unsigned long mobilePhoneNumber;

    char* description;

    static unsigned long countContacts;

    unsigned int sizeContact;
    unsigned long id;

    bool isCopy;
public:
    Contact(const char *name,
            const char *surname,
            unsigned long homePhoneNumber,
            unsigned long workPhoneNumber,
            unsigned long mobilePhoneNumber,
            const char *description);
    Contact(const char *name,
            const char *surname,
            unsigned long workNumber,
            const char* description);
    Contact(const char *name,
            unsigned long mobilePhoneNumber,
            const char* description);
    Contact(const char *name,
            unsigned long mobilePhoneNumber);

    Contact(const Contact& contact);
    ~Contact();


    void setName(char *name);
    void setSurname(char *surname);
    void setHomePhoneNumber(int homePhoneNumber);
    void setWorkPhoneNumber(int workPhoneNumber);
    void setMobilePhoneNumber(int mobilePhoneNumber);
    void setDescription(char *description);


    char *getName() const;
    char *getSurname() const;
    int getHomePhoneNumber() const;
    int getWorkPhoneNumber() const;
    int getMobilePhoneNumber() const;
    char *getDescription() const;


   // void printConsole() const;
   // void printFile() const;





};


#endif //____CONTACT_H