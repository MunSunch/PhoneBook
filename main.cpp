#include <iostream>
#include "Contact.h"
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    Contact c1("Munir", 89873022923);
    char* out = c1.toString();
    puts(out);
    return 0;
}
