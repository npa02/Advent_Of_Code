#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile;

    inputFile.open("input.txt");

    int sum = 0;
    string line;
    while (getline(inputFile, line)) {
        string num_string = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                num_string += line[i];
                break;
            }
        }
        for (int i = line.length() - 1; i >= 0; i--) {
            if (line[i] >= '0' && line[i] <= '9') {
                num_string += line[i];
                break;
            }
        }
        // cout << num_string;
        sum += stoi(num_string);
    }

    cout << "Sum = " << sum << endl;
    // Close the file
    inputFile.close();
    return 0;
}