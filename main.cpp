// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// ------------- CODE -------------
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes (if any)


// Main function
int main() {
  vector<string> names;
  ifstream input("names.txt");

  // if (!input) {
  //   cout << "Could not open names.txt.\n";
  //   return 1;
  // }

  string name;
  while (getline(input, name)) {
    if (!name.empty()) {
      names.push_back(name);
    }
  }

  // if (names.empty()) {
  //   cout << "No names found.\n";
  //   return 0;
  // }

  srand(static_cast<unsigned int>(time(nullptr)));
  int group_number = 1;
  while (!names.empty()) {
    cout << "Group " << group_number++ << ":\n";
    for (int i = 0; i < 3 && !names.empty(); i++) {
      size_t random_index = static_cast<size_t>(rand()) % names.size();
      cout << "  " << names[random_index] << '\n';
      names.erase(names.begin() + random_index);
    }
  }

  return 0;
}

// Function implementations (if any)


// ------------- DESIGN -------------
/* 
Program Name: Random Name Groups

Program Description:
Read names from names.txt, shuffle them, and display groups of up to three.

Design:
A. INPUT
Input file names.txt; each non-empty line is stored as a string in a vector.

B. OUTPUT
Group numbers and each name are printed to the screen.

C. CALCULATIONS
There are no arithmetic formulas beyond calculating group numbers and choosing
random shuffle indexes.

D. LOGIC and ALGORITHMS
1. Open names.txt and read each non-empty line into a vector of strings.
2. For each group, randomly select and remove up to three remaining names.
3. Continue until all names have been printed; the last group may contain fewer names.


SAMPLE RUNS
Output order changes each time the program runs.

*/
