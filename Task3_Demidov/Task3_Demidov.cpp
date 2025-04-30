#include "Tests.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    testInt();
    testString();
    testSpecialCases();
    return 0;
}