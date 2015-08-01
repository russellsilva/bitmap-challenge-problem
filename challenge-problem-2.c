#include <stdio.h>
static char bitmap[536870912] = {0};

void populate_bitmap() {
  int ret;
  while (ret != EOF) {
    unsigned int exclude;
    ret = scanf("%u", &exclude);
    if (ret == EOF) {
      break;
    }

    buffer[exclude / 8] |= 1 << (exclude % 8);
  }
}

int main() {
  for (int i = 0; i < 536870912; i++) {
    char candidates = buffer[i];
    // printf("%x\n", candidates);
    // printf("%x\n", candidates ^ (char) 255);
    if ((candidates ^ (char) 255) == 0) {
      continue;
    } else {
      for (int j = 0; j < 8; j++) {
        if (((candidates >> j) ^ 1) & 1 == 1) {
          printf("%d\n", i * 8 + j);
          break;
        }
      }
      break;
    }
  }
}
