#include <iostream>
#include "Contact.h"
#include "PhoneBook.h"
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    PhoneBook p1;
    Contact c1("Munir", 89873022923);
    Contact c2("Andrey", 12345);

    p1.append(c1);
    p1.append(c2);



    p1.remove(3);
    p1.show();



    return 0;
}
