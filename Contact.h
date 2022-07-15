#ifndef ____CONTACT_H
#define ____CONTACT_H


class Contact {
    char* name;
    char* surname;

    unsigned long long homePhoneNumber;
    unsigned long long workPhoneNumber;
    unsigned long long mobilePhoneNumber;

    char* description;

    static unsigned long var;
    unsigned long id;
public:
    unsigned int sizeContact;

    Contact(const char *name,
            const char *surname,
            unsigned long long homePhoneNumber,
            unsigned long long workPhoneNumber,
            unsigned long long mobilePhoneNumber,
            const char *description);
    Contact(const char *name,
            const char *surname,
            unsigned long long workNumber,
            const char* description);
    Contact(const char *name,
            unsigned long long mobilePhoneNumber,
            const char* description);
    Contact(const char *name,
            unsigned long long mobilePhoneNumber);
    Contact();

    Contact(const Contact& contact);
    ~Contact();


    void setName(char *name);
    void setSurname(char *surname);
    void setHomePhoneNumber(long long homePhoneNumber);
    void setWorkPhoneNumber(long long workPhoneNumber);
    void setMobilePhoneNumber(long long mobilePhoneNumber);
    void setDescription(char *description);


    char *getName() const;
    char *getSurname() const;
    long long getHomePhoneNumber() const;
    long long getWorkPhoneNumber() const;
    long long getMobilePhoneNumber() const;
    char *getDescription() const;
    unsigned long getID() const { return id;}


    void printConsole() const;
    char* toString() const;
    //  Копирование для уже инициализированного контакта значениями полей из другого контакта
    void copy(const Contact &contact_src);
};


#endif //____CONTACT_H
