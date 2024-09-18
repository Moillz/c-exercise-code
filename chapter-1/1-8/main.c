#include <stdio.h>

/**编写一个统计空格，制表符与换行符个数的程序*/

int main() {
  int c, count;
  count = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      ++count;
    }
  }
  printf("count: %d\n", count);
}

/** clang version 17.0.4, target: x84_64-pc-windows-msvc, thread model: posix */
/** clang ./main.c */