#ifndef __CAESAR_H__
#define __CAESAR_H__

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(char *pt);
char *decrypt(char *ct);

#ifdef __CAESAR_IMPLEMENTATION__

char shift(char c) {
  return (c - 'A' + 3) % 26 + 'A';
}

char unshift(char c) {
  return (c - 'A' - 3 + 26) % 26 + 'A';
}

char *allocate(size_t n) {
  char *m = (char *)calloc(n + 1, sizeof(char));
  if (m != NULL) return m;
  printf("Memory allocation error.\n");
  exit(1);
}

// modifies s.
size_t toUpperAlpha(char *s) {
  size_t i = 0, n = 0;
  for (; i < strlen(s); i++)
    if (isalpha(s[i])) s[n++] = toupper(s[i]);
  s[n] = '\0';
  return n;
}

char *apply(char (* op)(char), char *source) {
  size_t i = 0;
  size_t n = toUpperAlpha(source);
  char *target = allocate(n);
  for (; i < n; i++) target[i] = op(source[i]);
  target[i] = '\0';
  return target;
}

char *encrypt(char *pt) {
  return apply(shift, pt);
}

char *decrypt(char *ct) {
  return apply(unshift, ct);
}

#endif // implementation
#endif // header
