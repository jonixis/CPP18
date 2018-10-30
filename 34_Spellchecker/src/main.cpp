#include <iostream>
#include "spell_check.h"

using namespace std;

void printHelp() {
  cout << "Welcome to the magnificent spell checker!" << endl << endl;
  cout << "Usage: 34_Spellchecker dict_file_path text_file_path" << endl;
}

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printHelp();
    return 1;
  }

  SpellCheck spellcheck(argv[1], argv[2]);
  spellcheck.run();


  return 0;
}