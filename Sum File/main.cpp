#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string filename) { 
      ifstream file;
      int sum = 0;
      int num;
      file.open(filename);
      if (!file.is_open()) {
         cout << "Error opening " << filename << endl;
         exit (EXIT_FAILURE);
      }

      while (file >> num) {
         sum = sum + num;
      }

      return sum;

}