#include <iostream>
#include "Contact.h"
#include "PhoneBook.h"
#include <cstring>

using namespace std;

void indent(int n=3){
    if(n==0)    return;
    cout << endl;
    indent(n-1);
}

int main() {
    setlocale(LC_ALL, "rus");

    PhoneBook p1(new Contact[5]{{"Munir", 89873022923},
                                {"Andrey", 89193011911},
                                {"Viktor", 306120, "монтажник"},
                                {"Masha", 89172101911, "relax"},
                                {"Nikolay", "Voldyrev", 89531130670, "работа"}
                                }, 5);
    p1.show();
    indent();



    cout << "Поиск контакта c именем Munir" << endl;
    auto munir = p1.find("Munir");
    if(munir != NULL){
        cout << munir->toString() << endl;
    } else {
        cout << "Контакт не найден(" << endl;
    }
    indent();



    cout << "Удаление контакта с id 3(Masha)" << endl;
    if(p1.remove(3)){
        cout << "Успешно удалено" << endl;
    } else {
        cout << "Контакта не было в книге" << endl;
    }
    p1.show();
    indent();


    cout << "Добавление нового контакта:" << endl;
    p1.append(Contact("Alex", 12345));
    p1.show();
    indent();


    p1.printFile("listContacts.txt");


    return 0;
}
