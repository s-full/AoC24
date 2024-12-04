#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string file_name = "input.txt";
  int solution = 0;
  int firstArg;
  int secondArg;
  bool secondDoneFlag = false;
  ifstream inFile(file_name, ios::in);
  char currChar;
  while (inFile >> currChar) {
    secondDoneFlag = false;
    if (currChar == 'm') {
      cout << "found m" << endl;
      inFile >> currChar;
      if (currChar == 'u') {

        cout << "found mu" << endl;
        inFile >> currChar;
        if (currChar == 'l') {

          cout << "found mul" << endl;
          inFile >> currChar;
          if (currChar == '(') {

            cout << "found mul(" << endl;
            string firstArg{""};
            string secondArg{""};
            while (true) 
	    {
              inFile >> currChar;
              if (isdigit(currChar)) 
	      {
                firstArg += currChar;

                cout << "found mul(" << firstArg << endl;
              } 
	      else if (currChar == ',' && firstArg != "") 
	      {


                while (true) {
                  cout << "found mul(" << firstArg << "," << endl;
                  inFile >> currChar;
                  if (isdigit(currChar)) {
                    secondArg += currChar;
                    cout << "found mul(" << firstArg << "," << secondArg
                         << endl;
                  } else if (currChar == ')' && secondArg != "") {

                    cout << "found mul(" << firstArg << "," << secondArg << ")"
                         << endl;
                    int tempInt = stoi(firstArg) * stoi(secondArg);
                    solution += tempInt;
                    secondDoneFlag = true;
                    cout << "added " << tempInt << endl;
                    break;
                  } else {
                    break;
                  }
                }
		break;




              } 
	      else
	      {
                break;
              }
              
            }
          }
        }
      }
    }
  }
  inFile.close();
  cout << "solution: " << solution;
}
