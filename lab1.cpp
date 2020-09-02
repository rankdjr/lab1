// Douglas Rank
// CMPS 3350

#include <iostream>
#include <string>
using namespace std;

bool checkLetters (string);
void test ();

int main(int argc, char* argv[]) {
    string input;
    string arg = "test";
    bool result;

    if (argc > 1) {
        for (int i=1; i<argc; i++) {
            if (argv[i] == arg)
                test();
        }
    }

    do {
        cout << "Enter word: ";
        getline(cin, input);
        result = checkLetters(input);

        if (result)
            cout << "Double letters found." << endl;
        else
            cout << "No double letters found" << endl;
    } while (!result);

    return 0;
}

bool checkLetters (string word) {
    bool flag = false;
    for (int i = 0; word[i+1] != '\0'; i++) {
        if (word[i] == ' ') {
            flag = false;
            break;
        }
        if (word[i] == word[i+1] && word[i] != word[i+2] && word[i] != word[i-1]) {
            flag = true;
            break;
        }
    }

    return flag;
}

void test() {
    string word;
    word = "A one letter word";    
    cout << word << "\t - " << checkLetters(word) << endl;
    word = "aardvark";    
    cout << word << "\t\t - " << checkLetters(word) << endl;
    word = "book";    
    cout << word << "\t\t\t - " << checkLetters(word) << endl;
    word = "fall";    
    cout << word << "\t\t\t - " << checkLetters(word) << endl;
    word = "abdddc";    
    cout << word << "\t\t\t - " << checkLetters(word) << endl;     
    word = "test";    
    cout << word << "\t\t\t - " << checkLetters(word) << endl;     

}
