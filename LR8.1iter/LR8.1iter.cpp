#include <iostream>
using namespace std;

// Search the string for "no" or "on".
bool hasNoOrOn(const char s[])
{
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++) {
        if ((s[i] == 'n' && s[i + 1] == 'o') ||
            (s[i] == 'o' && s[i + 1] == 'n'))
            return true;
    }
    return false;
}

// Replace each "no" with "***".
bool replaceNo(const char s[], char result[], int size)
{
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[i] == 'n' && s[i + 1] == 'o') {
            if (j + 3 >= size) return false;
            result[j] = '*';
            result[j + 1] = '*';
            result[j + 2] = '*';
            j += 3;
            i += 2;
        }
        else {
            if (j + 1 >= size) return false;
            result[j] = s[i];
            i++;
            j++;
        }
    }
    result[j] = '\0';
    return true;
}

#ifndef UNIT_TEST
int main()
{
    char s[1000], result[1600];
    cout << "Enter string: ";
    cin.getline(s, 1000);
    cout << "Contains 'no' or 'on': " << (hasNoOrOn(s) ? "yes" : "no") << '\n';
    if (replaceNo(s, result, 1600))
        cout << "Modified string: " << result << '\n';
    else
        cout << "Error: result is too long.\n";
    return 0;
}
#endif

