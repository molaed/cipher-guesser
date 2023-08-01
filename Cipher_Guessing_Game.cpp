#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "caesar.hpp"

using namespace std;

int game_call(vector<string> listofwords, int difficulty) {
    int Contending_Score = 0;
    int max_shift[3] = {3, 10, 25};
    int lives_array[3] = {5, 3, 1};
    srand (time(NULL));
    
    int lives = lives_array[difficulty-1];

    while (lives > 0) {
        int shift = rand() % max_shift[difficulty-1] + 1;
        
        string random_string = listofwords[rand()%100+1];
        string ciphered_string = random_string;
        arya::encode_line(ciphered_string, shift);

        char ciphered_char[6];
        for (int i=0; i<5; i++) {
            if (ciphered_string[i]<33) {
                ciphered_char[i] = ciphered_string[i]+33;
            }
            else if (ciphered_string[i]>123) {
                ciphered_char[i] = 160 - ciphered_string[i];
            }
            else {
                ciphered_char[i] = ciphered_string[i];
            }
        }
        ciphered_char[5] = '\0';

        int correct_choice = rand() % 3;
        int guess;
        
        vector <string> listofchoices;
        listofchoices.push_back(random_string);

        cout << "\nGuess the original word if the shifted word is: " << ciphered_char << endl;
        // cout << "The shift is " << shift << endl; 
        cout << "Correct answer is " << random_string << endl;
        for (int i = 0; i < 3; i++) {
            if (i == correct_choice) {
                cout << i+1 << ". " << random_string << endl;
            }
            else {
                string random_choice = listofwords[rand()%100+1];
                while (count(listofchoices.begin(), listofchoices.end(), random_choice) > 0) {
                    random_choice = listofwords[rand()%100+1];
                }
                listofchoices.push_back(random_choice);
                
                cout << i+1 << ". " << random_choice << endl;
            }
        }

        cout << "Choose wisely: ";
        cin >> guess;
        if (guess == correct_choice+1) {
            cout << "Correct!" << endl;
            Contending_Score++;
        }
        else {
            cout << "Wrong Answer, " << --lives << " lives left.\n";
        }
        cout << "***************************************************************************************";
        cout << endl << endl;
    }

    return Contending_Score;
    // for (int i = 0; i < 5; i++) { // 5 rounds
    // }
}

int main() {

    bool game = true;
    int option;

    ifstream ifHigh_Score("High_Score.txt");
    ofstream ofHigh_Score("High_Score.txt");
    ifstream infile("input.txt");

    vector<string> listofwords;
    string temp;
    while (infile >> temp) {
        listofwords.push_back(temp);
    }

    string sHigh_Score = "0";
    // getline(ifHigh_Score, sHigh_Score);

    int difficulty = 2; // 1-3

    while (game) {
        cout << "Cipher Guessing Game" << endl;
        cout << "1. Play" << endl;
        cout << "2. Difficulty" << endl; // time difficulty + range of shifts
        cout << "3. High Score" << endl;
        cout << "4. Help" << endl;
        cout << "5. Exit" << endl;

        cout << "Option: ";
        cin >> option;

        while(!cin) {
            cin.clear(); // reset failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
        }

        switch (option) {
            case(1): { // play
                int Contending_Score = game_call(listofwords, difficulty);

                if (Contending_Score > stoi(sHigh_Score)) {
                    cout << "New High Score!\n";
                    sHigh_Score = to_string(Contending_Score);
                    ofHigh_Score << sHigh_Score;
                }

                break;
            }
            case(2): { // difficulty
                cout << "Current Difficulty: " << difficulty << endl;
                cout << "Please enter the new difficulty (1-3): " << endl;
                cin >> difficulty;
                while (difficulty > 3 || difficulty < 0) {
                    cout << "please enter a difficulty from 1-3";
                }
                cout << "You have selected difficulty " << difficulty << endl;

                break;
            }
            case (3): { // high score
                cout << "High Score: " << sHigh_Score << endl;

                //cout << "High Scores" << endl;

                // string score;
                // for (int i = 0; i < 3; i++) {
                //     getline(fHigh_Score, score);
                //     cout << i+1 << ". " << score << endl;
                // }

                break;
            }
            case (4): {
                string readiness = "NOTREADY";
                cout << "\nThis is a multiple choice guessing game where we Caesar shift\n";
                cout << "the ASCII values of a string and you guess the original string.\n\n";
                cout << "The shift is based on the diffulty with a max shift of 3/10/25 for difficulties 1/2/3\n";
                cout << "The default difficulty is 2\n";
                cout << "Valid ASCII values range from 33 (\"!\") to 125 (\"{\")\n\n";
                cout << "Guessing the correct string grants you one point, otherwise you lose a life!\n";
                cout << "You have 5/3/1 lives,";
                cout << "when you run out of lives, you lose.\n\n";
                cout << "Try to get as many points as you can and beat the high score!\n";

                cout << "Please type \"READY\" when you are ready... \n";
                while(readiness == "NOTREADY") {
                    cin >> readiness;
                }
                cout << "Good Luck!";
                break;
            }
            case (5): { // exit game
                cout << "Thank you for playing!";
                game = false;

                break;
            }
            default: {
                cout << "Please enter a number from 1-5!";
            }
        }
        cout << "\n";
        cout << "***************************************************************************************";
        cout << "\n\n";
    }   



    return 0;
}


