#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to print a vector
void printVec(const vector<int>& row) {
    for (auto ele : row) {
        cout << ele << " ";
    }
    cout << endl;
}

// Function to check if a sequence is safe
bool isSafe(const vector<int>& row, bool increasing) {
    for (int i = 1; i < row.size(); ++i) {
        int difference = row[i] - row[i - 1];
        if (increasing) {
            if (difference <= 0 || difference > 3) {
                return false;
            }
        } else {
            if (difference >= 0 || difference < -3) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> row;
    int solution = 0;
    string file_name = "input.txt";
    ifstream inFile(file_name, ios::in);
    string line;

    while (getline(inFile, line)) {
        istringstream iss(line);
        int num;
        row.clear();

        while (iss >> num) {
            row.push_back(num);
        }

        // Determine if the sequence is increasing or decreasing
        bool increasing = (row[0] < row[row.size() - 1]);

        // Check if the sequence is already safe
        if (isSafe(row, increasing)) {
            ++solution;
            cout << "GOOD ";
            printVec(row);
            continue;
        }

        // Try removing each level and check if the sequence becomes safe
        bool flag = false;
        for (int i = 0; i < row.size(); ++i) {
            vector<int> modifiedRow = row; // Create a copy of the row
            modifiedRow.erase(modifiedRow.begin() + i); // Remove one level
            if (isSafe(modifiedRow, increasing)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            ++solution;
            cout << "GOOD (with Problem Dampener) ";
            printVec(row);
        } else {
            cout << "BAD ";
            printVec(row);
        }
    }

    cout << "solution " << solution << endl;
    return 0;
}

