#include <iostream>

using namespace std;

void swap(int &i, int &j) {
  int tmp = i;
  i = j;
  j = tmp;
}

int main(int argc, char const *argv[]) {
  int i = 99;
  int j = 66;

  // cout << "i= " << i << endl;
  // cout << "j= " << j << endl << endl;

  // cout << "Swapping..." << endl << endl;

  swap(i, j);

  // cout << "i= " << i << endl;
  // cout << "j= " << j << endl << endl;

  return 0;
}