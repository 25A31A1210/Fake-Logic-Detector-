#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

// Function to check logical keywords
int checkKeywords(string input) {
    vector<string> keywords = {"because", "therefore", "if", "hence", "since"};
    int score = 0;

    for (string word : keywords) {
        if (input.find(word) != string::npos) {
            score += 2;
        }
    }
    return score;
}

// Function to check sentence length
int checkLength(string input) {
    if (input.length() > 25)
        return 2;
    else if (input.length() > 10)
        return 1;
    else
        return -1;
}

// Function to detect repetition (fake logic indicator)
int checkRepetition(string input) {
    int count = 0;
    for (int i = 0; i < input.length() - 1; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        }
    }
    return (count > 2) ? -2 : 1;
}

// Function to generate final result
void analyzeStatement(string input) {
    srand(time(0));
    int score = 0;

    score += checkKeywords(input);
    score += checkLength(input);
    score += checkRepetition(input);

    // Random factor
    score += rand() % 4;

    cout << "\nAnalyzing statement...\n";

    if (score >= 5) {
        cout << "Result: ✅ Highly Logical Statement\n";
    } else if (score >= 2) {
        cout << "Result: ⚖️ Partially Logical\n";
    } else {
        cout << "Result: ❌ Fake Logic Detected\n";
    }
}

int main() {
    string input;
    int choice;

    do {
        cout << "\n===== Fake Logic Detector =====\n";
        cout << "1. Enter Statement\n";
        cout << "2. Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter your statement: ";
                getline(cin, input);
                analyzeStatement(input);
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 2);

    return 0;
}