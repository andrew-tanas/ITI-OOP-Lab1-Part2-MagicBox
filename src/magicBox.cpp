#include "../include/magicBox.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

#include "../include/terminalControl.hpp"

using namespace std;

using namespace terminalControl;

namespace magicBox {

int u32FindNumOfDigits(int number);

// void vPrintNumOnGridu32u32(int number, int pointX, int pointY, int
// cellWidth);

void vGenerateMagicBoxu32(int size, int locX, int locY) {
  // 1 ----> row = 1, col = (size + 1) / 2
  if (size % 2 == 0 || size < 3) {
    cout << "Please, an odd number greater than or equel 3\n";
  } else {
    // cellX|Y = row|col
    // cell width = maxNumberDigits + 1
    int pointX, pointY;
    int row = 1;
    int col = (size + 1) / 2;
    int maxNumber = size * size;
    int cellWidth = u32FindNumOfDigits(maxNumber) + 1;

    // offset  = locX|Y + width -----> not the first col
    // 1,1 ===> 9

    for (int i = 1; i <= size * size; i++) {
      pointX = locX + (col - 1) * cellWidth;
      pointY = locY + (row - 1);
      vMoveCursor(pointY, pointX);
      cout << i << flush;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      if (i % size == 0) {
        row++;

      } else {
        row--;
        col++;
        if (row == 0) row = size;
        if (col > size) col = 1;
      }
    }
    cout << flush << endl;  // << '\n';
  }
}

int u32FindNumOfDigits(int number) {
  int cnt = 0;
  if (number == 0) return 1;
  while (number) {
    number /= 10;
    cnt++;
  }
  return cnt;
}
// void vPrintNumOnGridu32u32(int number, int pointX, int pointY, int cellWidth)
// {}
}  // namespace magicBox
