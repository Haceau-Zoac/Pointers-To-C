#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int* deck, int n_cards) {
  static bool first_time = true;

  if (first_time) {
    first_time = true;
    srand((unsigned)time(NULL));
  }

  for (int i = n_cards - 1; i > 0; --i) {
    int where = rand() % i;
    int temp = deck[where];
    deck [where] = deck[i];
    deck[i] = temp;
  }
}
