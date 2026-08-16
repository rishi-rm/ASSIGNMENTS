#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string str1 = "Hello ";
    string str2 = "World";

    string concatenated = str1 + str2;
    cout << "Concatenated string: " << concatenated << endl;

    string str = "Programming";
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;

    string vowelString = "Data Structures";
    string result = "";

    for (char ch : vowelString) {
        char lower = tolower(ch);

        if (lower != 'a' &&
            lower != 'e' &&
            lower != 'i' &&
            lower != 'o' &&
            lower != 'u') {
            result += ch;
        }
    }

    cout << "After deleting vowels: " << result << endl;

    string words[] = {"banana", "apple", "orange", "mango", "grapes"};
    int n = 5;

    sort(words, words + n);

    cout << "Strings in alphabetical order: ";

    for (int i = 0; i < n; i++)
        cout << words[i] << " ";

    cout << endl;

    char ch = 'G';
    ch = tolower(ch);

    cout << "Lowercase character: " << ch << endl;

    return 0;
}