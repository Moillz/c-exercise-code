/** 练习10 编写一个将输入复制到输出的程序，并将其中的制表符替换为\t，把回退符替换成\b，把反斜杠替换成\\ */
#include <stdio.h>

int main() {
  int c;
  while((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if(c == '\b') {
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      putchar(c);
    }
  }
}

