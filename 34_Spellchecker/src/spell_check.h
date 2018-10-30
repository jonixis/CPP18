#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include <string>
#include "Pset.h"
#include "Pvector.h"

class SpellCheck {
private:
  Pset<std::string> dict;
  Pvector<std::string> text;

  void handle_word(std::string &word);
  bool word_in_dict(std::string word);

public:
  SpellCheck(std::string dict_file_path, std::string text_file_path) : dict(dict_file_path), text(text_file_path){ }

  void run();
};

#endif // SPELLCHECK_H