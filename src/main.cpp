#include <iostream>

#include "../include/magicBox.hpp"
#include "../include/terminalControl.hpp"
using namespace std;
using namespace magicBox;
using namespace terminalControl;

int main() {
  bInitTerminal();
  int size;
  cout << "enter the magic box size: ";
  cin >> size;
  vClearScreen();
  vGenerateMagicBoxu32(size, 5, 5);

  // int number = 1;

  // int cnt = 0;
  // while (number) {
  //   number /= 10;
  //   cnt++;
  // }

  // cout << cnt << endl;

  return 0;
}