#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_test(const char *input, int expected_lines, int expected_words, int expected_chars) {
  // Redirect stdin to the input string
  // Create a temporary file and write the input string to it
  FILE *input_stream;
  if (tmpfile_s(&input_stream) != 0) {
    perror("tmpfile_s");
    exit(EXIT_FAILURE);
  }
  if (input_stream == NULL) {
    perror("tmpfile");
    exit(EXIT_FAILURE);
  }
  fwrite(input, 1, strlen(input), input_stream);
  rewind(input_stream);

  // Redirect stdin to the temporary file
  FILE *new_stream;
  if (freopen_s(&new_stream, "NUL", "r", input_stream) != 0) {
    perror("freopen");
    exit(EXIT_FAILURE);
  }

  // Run the main function
  #define OUT 0
  #define IN 1
  
  int c, nl, nw, nc, state;
  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    nc++;
    if (c == '\n') {
      nl++;
    }
    if (c == '\n' || c == ' ' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      nw++;
      state = IN;
    }
  }
  fclose(input_stream);

  // Check the results
  if (nl != expected_lines || nw != expected_words || nc != expected_chars) {
    printf("Test failed for input: \"%s\"\n", input);
    printf("Expected lines: %d, words: %d, chars: %d\n", expected_lines, expected_words, expected_chars);
    printf("Got lines: %d, words: %d, chars: %d\n", nl, nw, nc);
  } else {
    printf("Test passed for input: \"%s\"\n", input);
  }
}

int main() {
  run_test("Hello world\n", 1, 2, 12);
  run_test("Hello\nworld\n", 2, 2, 12);
  run_test("Hello   world\n", 1, 2, 15);
  run_test("Hello\tworld\n", 1, 2, 12);
  run_test("Hello\n\nworld\n", 3, 2, 13);
  run_test("", 0, 0, 0);
  run_test(" \n\t", 1, 0, 3);

  return 0;
}