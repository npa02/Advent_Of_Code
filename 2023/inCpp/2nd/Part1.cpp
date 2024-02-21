#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Game {
    int game_id;
    string game_info;
};

Game game_list[100] = {};
int num_game = 0; // Counter for the number of games

void get_data() {
    ifstream inputFile;
    inputFile.open("input.txt");
    string line;

    // Read data set
    // Get the game_id, and all the sets in that game, then save in the list
    while (getline(inputFile, line)) {
        if (line.find("Game") != string::npos) {
            // Extract game_id from the line
            int game_id = stoi(line.substr(line.find("Game") + 5));

            // Extract game_info from the line
            string game_info = line.substr(line.find(":") + 2);

            // Save the game information into array
            Game game;
            game.game_id = game_id;
            game.game_info = game_info;
            game_list[num_game++] = game;
        }
    }

    inputFile.close();

}

bool valid_game(const string& game_info) {
    vector<string> subset_list;
    istringstream ss(game_info);
    string subset;

    while (getline(ss, subset, ';')) {
        subset_list.push_back(subset);
    }

    bool check = true;

    for (const auto& subset : subset_list) {
        int blue = 0, red = 0, green = 0;

        istringstream subset_ss(subset);
        string color;

        // Split string with ', '
        while(getline(subset_ss, color, ',')) {
            istringstream color_ss(color);

            if (color.find("blue") != string::npos) {
                string num;
                color_ss >> num;
                blue = stoi(num);
            }

            if (color.find("red") != string::npos) {
                string num;
                color_ss >> num;
                red = stoi(num);
            }

            if (color.find("green") != string::npos) {
                string num;
                color_ss >> num;
                green = stoi(num);
            }

            if (blue > 14 || red > 12 || green > 13) {
                check = false;
                break;
            }
        }
    }

    return check;
}

int main() {
    // Read and get data
    get_data();

    int valid_sum = 0;

    for (int i = 0; i < num_game; i++) {
        if (valid_game(game_list[i].game_info)) {
            valid_sum += game_list[i].game_id;
        }
    }

    cout << "Sum = " << valid_sum << endl;

    return 0;
}
