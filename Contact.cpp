#include "Contact.h"

Contact::Contact(char *name, char *surname, int homePhoneNumber, int workPhoneNumber, int mobilePhoneNumber,
                 char *description) : name(name), surname(surname), homePhoneNumber(homePhoneNumber),
                                      workPhoneNumber(workPhoneNumber), mobilePhoneNumber(mobilePhoneNumber),
                                      description(description) {}
Contact::Contact(char *name, char *surname, int workNumber, char* description)
        : Contact(name, surname, 0, 0, workNumber, description){}
