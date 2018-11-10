#include <iostream>
#include "spell_check.h"

using namespace std;

// TODO extract punctuation for word in dict check. and in case of replacement append again

void SpellCheck::run() {
  for (string &word : text) {
    if (!word_in_dict(word)) {
      handle_word(word);
    }
  }
}

bool SpellCheck::word_in_dict(string word) {
  return dict.find(word) != dict.end();
}

void replace_word(string &word) {
  cout << "Replace '" << word << "' with: ";
  cin >> word;
  cout << endl;
}

void SpellCheck::handle_word(string &word) {
  cout << "Word misspelled or not in dictionary: " << word << endl;
  cout << "(a)dd, (i)gnore, (r)eplace? ";

  char command;
  for (;;) {
    cin >> command;

    if (command == 'a') {
      dict.insert(word);
      return;
    } else if (command == 'r') {
      replace_word(word);
      // Recursive call to handle replacement word
      if (!word_in_dict(word)) {
        handle_word(word);
      }
      return;
    } else if (command == 'i') {
      return;
    } else {
      cout << "Unknwon command! Choose again..." << endl;
    }
  }

  cout << endl;
}

