#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
  // Open the file for reading and writing
  ifstream infile("prepare1.txt");
  ofstream outfile("preNoEnter.txt");

  // Check if files opened successfully
  if (!infile.is_open() || !outfile.is_open()) {
    cerr << "Error opening files." << endl;
    return 1;
  }

  // Regular expression to match timestamps
  regex timestamp_regex(R"()"); // Matches "followed by two digits : followed by two digits"

  string line;
  while (getline(infile, line)) {
    // Remove timestamps
    line = regex_replace(line, timestamp_regex, "");

    // Skip empty lines after removing timestamps (lines become empty after timestamp removal)
    if (!line.empty()) {
      outfile << line << endl;
    }
  }

  cout << "Timestamps removed successfully! Check file_without_timestamps.txt." << endl;

  // Close the files
  infile.close();
  outfile.close();

  return 0;
}
