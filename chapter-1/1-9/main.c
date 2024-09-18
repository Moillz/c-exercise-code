/** 练习1-9 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替 */
#include <stdio.h>

int main() {
  int c, lastc = 0;
  while ((c = getchar()) != EOF) {
    if (c != ' ' || lastc != ' ') {
      putchar(c);
    }
    lastc = c;
  }
  return 0;
}