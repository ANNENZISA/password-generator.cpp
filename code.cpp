#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

string generatePassword(int length, bool includeNumbers, bool includeSymbols) {
    const string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numberChars = "0123456789";
    const string symbolChars = "!@#$%^&*()_+-=[]{}|;:'<>,.?/";

    string validChars = lowercaseChars + uppercaseChars;

    if (includeNumbers)
        validChars += numberChars;
    
    if (includeSymbols)
        validChars += symbolChars;

    if (validChars.empty()) {
        cout << "Error: No character set selected.\n";
        return "";
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    string password;

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % validChars.length();
        password.push_back(validChars[randomIndex]);
    }

    return password;
}

int main() {
    int length;
    bool includeNumbers, includeSymbols;

    cout << "Enter the desired password length: ";
    cin >> length;

    cout << "Include numbers? (1 for yes, 0 for no): ";
    cin >> includeNumbers;

    cout << "Include symbols? (1 for yes, 0 for no): ";
    cin >> includeSymbols;

    string password = generatePassword(length, includeNumbers, includeSymbols);

    if (!password.empty()) {
        cout << "Generated Password: " << password << "\n";
    }

    return 0;
}
