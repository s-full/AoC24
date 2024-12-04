#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  vector<int> row;
  int solution = 0;
  bool increasing;
  vector<int> differences;
  string file_name = "input.test";
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

    for (int i = 1; i < row.size(); ++i) {
      differences.push_back(row[i] - row[i - 1]);
    }

    if (increasing) {
      bool flag = true;
      for (int i = 0; i < differences.size(); ++i) {
        if (differences[i] <= 0 || differences[i] > 3) {
          flag = false;
          break;
        }
      }
      if (flag) {
        solution++;
      }
    } else {
      bool flag = true;
      for (int i = 0; i < differences.size(); ++i) {
        if (differences[i] >= 0 || differences[i] < -3) {
          flag = false;
          break;
        }
      }
      if (flag) {
        solution++;
      }
    }
    differences.clear();
  }

  cout << "solution " << solution;
}
