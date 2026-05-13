#include <iostream>
using namespace std;

int main()
{
    // Define string using char pointer
    char *str = (char*)"Hello World";

    cout << "Original String: " << str << endl;

    cout << "\nAfter AND with 127:\n";

    for (int i = 0; str[i] != '\0'; i++) {
        char result = str[i] & 127;
        cout << result;
    }

    cout << "\n\nAfter XOR with 127:\n";

    for (int i = 0; str[i] != '\0'; i++) {
        char result = str[i] ^ 127;
        cout << result;
    }

    cout << endl;

    return 0;
}
