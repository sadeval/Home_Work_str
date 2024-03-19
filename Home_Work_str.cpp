#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

//TASK_20

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        cout << " ";
    }
}
void notprintSpaces(int count) {
    for (int i = 0; i > count; i++) {
        cout << "";
    }
}

int main() {
    const int max_length = 50;
    char str[max_length + 1];
    cout << "Enter the string max 50 symbols): ";
    cin.getline(str, max_length + 1);

    int length = strlen(str);
    int rombLength = min(length, max_length);

    char* ptr = str;


    for (int i = 0; i < rombLength; i++) {

        printSpaces(rombLength - i - 1);

        for (int j = 0; j <= i; j++) {
            cout << *(ptr + j);
        }
        cout << "\n";
        Sleep(50);
    }


    for (int i = rombLength - 2; i >= 0; i--) {

        notprintSpaces(rombLength - i - 1);

        for (int j = 0; j <= i; j++) {
            cout << *(ptr + j);
        }
        cout << "\n";
        Sleep(50);
    }

    return 0;
}

//TASK_13

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int max_digits = 1000000;
    char* pi = new char[max_digits + 1];
    cout << "Enter the first " << max_digits << " digits of Pi: ";
    cin.getline(pi, max_digits + 1);

    int max_sequence = 0;
    int current_sequence = 0;
    bool found_first_9 = false;

    char* ptr = pi;

    while (*ptr != '\0') {
        if (*ptr == '9') {
            if (found_first_9) {
                max_sequence = max(max_sequence, current_sequence);
                current_sequence = 0;
            }
            found_first_9 = true;
        }
        else if (found_first_9) {
            current_sequence++;
        }
        ptr++;
    }

    cout << "Maximum sequence of digits between two nines in Pi: " << max_sequence << "\n";

    delete[] pi;

    return 0;
}

//TASK_6

#include <iostream>
#include <cstring>

using namespace std;

void toLower(char* str) {
    for (; *str; str++) {
        *str = tolower(*str);
    }
}

bool containSpam(const char* input, const char* spamWords[], int numSpamWords) {
    for (int i = 0; i < numSpamWords; i++) {
        if (strstr(input, spamWords[i]) != nullptr) {
            return true;
        }
    }
    return false;
}

int main() {
    const int max_length = 100;
    const char* spamWords[] = { "viagra", "xxx" };
    int numSpamWords = sizeof(spamWords) / sizeof(spamWords[0]);

    char input[max_length + 1];
    cout << "Enter text: ";
    cin.getline(input, max_length);

    toLower(input);

    if (containSpam(input, spamWords, numSpamWords)) {
        cout << "THIS IS A SPAM!" << "\n";
    }
    else {
        cout << "it's not a spam" << "\n";
    }

    return 0;
}

//TASK_8

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


char* generatePassword(int length) {

    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";

    char* password = new char[length + 1];

    srand(time(nullptr));

    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }

    password[length] = '\0';

    return password;
}

int main() {

    int length;
    cout << "Enter the length of the password: ";
    cin >> length;

    char* password = generatePassword(length);
    cout << "Generated password: " << password << "\n";

    delete[] password;

    return 0;
}


//TASK_5

#include <iostream>
#include <cstring>

using namespace std;

int countOccurrences(char* text, char* word) {
    int count = 0;
    int wordLength = strlen(word);
    char* ptr = text;

    while ((ptr = strstr(ptr, word)) != nullptr) {
        count++;
        ptr += wordLength;
    }

    return count;
}

int main() {
    char* text = new char[200];
    strcpy_s(text, 199, "My cats are pretty! My cats are smart! My cats are super cuttie! Who loves cats more than I do? Maybe it's Alexander? :)");

    char* search = new char[200];
    strcpy_s(search, 199, "cats");

    int occurrences = countOccurrences(text, search);

    cout << "The word \"" << search << "\" occurs " << occurrences << " times in the text." << "\n";

    delete[] text;
    delete[] search;

    return 0;
}