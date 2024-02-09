#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct num_spell {
    string spell;
    char number;
};

const num_spell spell_to_number[] = {
    {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
};

string replace_spell(const string& str) {
    string result = str;

    for (const num_spell& mapping : spell_to_number) {
        size_t pos = result.find(mapping.spell);

        while (pos != string::npos) {
            // Replace the second and subsequent characters with the digit
            result[pos + 1] = mapping.number;

            // Move the position to the next character after the replaced digit
            pos = result.find(mapping.spell, pos + 1);
        }
    }

    return result;
}



int main() {
    
    ifstream inputFile;

    inputFile.open("input.txt");

    int sum = 0;
    string line;
    while (getline(inputFile, line)) {
        string num_string = "";
        string modified_str = replace_spell(line);
        // cout << modified_str << endl;
        for (int i = 0; i < modified_str.length(); i++) {
            if (modified_str[i] >= '0' && modified_str[i] <= '9') {
                num_string += modified_str[i];
                break;
            }
        }
        for (int i = modified_str.length() - 1; i >= 0; i--) {
            if (modified_str[i] >= '0' && modified_str[i] <= '9') {
                num_string += modified_str[i];
                break;
            }
        }
        if (!num_string.empty()) {
            // cout << num_string << endl;
            sum += stoi(num_string);
        }
    }

    cout << "Sum = " << sum << endl;
    // Close the file
    inputFile.close();

    return 0;
}
