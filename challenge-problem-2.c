#include <stdio.h>

#define SIZE_OF_BITMAP 536870912
static char bitmap[SIZE_OF_BITMAP] = {0};

unsigned int find_value_not_in_bitmap();
void populate_bitmap();
void populate_one_bit(unsigned int);
int first_unset_bit(char);

int main() {
  populate_bitmap();
  unsigned int result = find_value_not_in_bitmap();
  printf("%u\n", result);
}

void populate_bitmap() {
  int ret = 0;
  while (ret != EOF) {
    unsigned int value;
    ret = scanf("%u", &value);
    if (ret == EOF) {
      break;
    }

    populate_one_bit(value);
  }
}

void populate_one_bit(unsigned int value) {
  bitmap[value / 8] |= 1 << (value % 8);
}

unsigned int find_value_not_in_bitmap() {
  for (int i = 0; i < SIZE_OF_BITMAP; i++) {
    char candidates = bitmap[i];
    int j = first_unset_bit(candidates);
    if (j > -1) {
      return i * 8 + j;
    }
  }
}

int first_unset_bit(char byte) {
  if ((byte ^ (char) 255) == 0) {
    return -1;
  } else {
    for (int i = 0; i < 8; i++) {
      if ((((byte >> i) ^ 1) & 1) == 1) {
        return i;
      }
    }
  }
}
