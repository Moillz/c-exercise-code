// 编写一个程序，以每行一个单词的形式打印其输入
#include <stdio.h>

int main() {
  int c, lastc;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' ||  c == '\n') {
      if (lastc != ' ' && lastc != '\t' && lastc != '\n') {
        putchar('\n');
    }
    } else {
      putchar(c);
    }
    lastc = c;
  }
}