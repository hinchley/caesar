#include <stdio.h>

#define  __CAESAR_IMPLEMENTATION__
#include "caesar.h"

void usage(char *program) {
  printf("Usage: %s -e plaintext | -d ciphertext\n", program);
  exit(1);
}

int main(int argc, char **argv) {
  char *program = argv[0];

  if (argc != 3) usage(program);

  char *option = argv[1];
  if (strlen(option) != 2) usage(program);

  char mode = option[1];
  if (mode != 'e' && mode != 'd') usage(program);

  char *input  = argv[2];
  char *output = mode == 'e' ? encrypt(input) : decrypt(input);

  printf("%s\n", output);

  free(output);

  return 0;
}
