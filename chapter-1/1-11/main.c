/** 你准备如何测试单词计数程序？如何程序中存在某种错误，那么什么样的输入最有可能发现这类错误 */
#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;
  nl = nw = nc = 0;
  state = OUT;
  
  // Read input character by character
  while((c = getchar()) != EOF) {
    nc++; // Increment character count
    if (c == '\n') {
      nl++; // Increment line count
    }
    
    // Check for whitespace characters
    if (c == '\n' || c == ' ' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      nw++; // Increment word count
      state = IN;
    }
  }
  
  // Print the results
  printf("number of lines: %d, number of words: %d, number of characters: %d\n", nl, nw, nc);
}