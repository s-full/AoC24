#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  vector<int> left;
  vector<int> right;
  unordered_map<int, int> rightCount;
  string file_name = "input.txt";
  int leftNum{-1};
  int rightNum{-1};
  long long solution{0};

  ifstream inFile(file_name, ios::in);
  while (inFile >> leftNum >> rightNum) {

    left.push_back(leftNum);
    right.push_back(rightNum);
    rightCount[rightNum]++;
  }
  inFile.close();

  /*
   sort(right.begin(), right.end());
   sort(left.begin(), left.end());

  for (int i = 0; i < left.size(); ++i) {
    solution += abs(right[i] - left[i]);
  }
  */
  for (int i = 0; i < left.size(); ++i) {
    auto it = rightCount.find(left[i]);
    if (it != rightCount.end()) {
      solution += left[i] * it->second;
    }
  }
  cout << solution;
}
