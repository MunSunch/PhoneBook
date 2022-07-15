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




    void setName(char *name) {
        delete[] this->name;
        strcpy(this->name, name);
    }
    void setSurname(char *surname) {
        delete[] this->surname;
        strcpy(this->surname, surname);
    }
    void setHomePhoneNumber(long long homePhoneNumber) {
        this->homePhoneNumber = homePhoneNumber;
    }
    void setWorkPhoneNumber(long long workPhoneNumber) {
        this->workPhoneNumber = workPhoneNumber;
    }
    void setMobilePhoneNumber(long long mobilePhoneNumber) {
        this->mobilePhoneNumber = mobilePhoneNumber;
    }
    void setDescription(char *description) {
        delete[] this->description;
        strcpy(this->description, description);
    }


    char *getName() const { return name;}
    char *getSurname() const {  return surname;}
    long long getHomePhoneNumber() const {  return homePhoneNumber;}
    long long getWorkPhoneNumber() const {  return workPhoneNumber;}
    long long getMobilePhoneNumber() const {    return mobilePhoneNumber;}
    char *getDescription() const {  return description;}
    unsigned long getID() const {   return id;}



    void printConsole() const;
    char* toString() const;
    //  Копирование для уже инициализированного контакта значениями полей из другого контакта
    void copy(const Contact &contact_src);
};


#endif //____CONTACT_H
