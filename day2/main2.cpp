#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void printVec(vector<int> &row) {
  for (auto ele : row) {
    cout << ele << " ";
  }
  cout << endl;
}

int main() {
  vector<int> row;
  int solution = 0;
  bool increasing;
  vector<int> differences;
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
    increasing = (row[0] < row[row.size() - 1]);
    int badLevels = 0;
    bool flag = true;
    int i = 1;
    for (; i < row.size(); ++i) {
      int difference = row[i] - row[i - 1];
      if (increasing) {
        if (difference <= 0 || difference > 3) {
          badLevels++;
          if (badLevels > 1) {
            flag = false;
            printVec(row);
            cout << "BAD" << endl;
            break;
          }
          cout << "Before erase ";
          printVec(row);
          row.erase(row.begin() + i-1);
          cout << "After erase ";
          printVec(row);
          i--;
        }
      } else {
        if (difference >= 0 || difference < -3) {
          badLevels++;
          if (badLevels > 1) {
            flag = false;
            printVec(row);
            cout << "BAD" << endl;
            break;
          }
          cout << "Before erase ";
          printVec(row);
          row.erase(row.begin() + i-1);
          cout << "After erase ";
          printVec(row);
          i--;
        }
      }
    }
    if (flag) {
      ++solution;
      cout << "GOOD ";
      printVec(row);
    }
  }
  cout << "solution " << solution;
}
