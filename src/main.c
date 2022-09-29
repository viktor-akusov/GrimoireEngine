#include <stdio.h>
#include <stdbool.h>
#include "dices.h"
#include "traveler.h"

int main() {
  init_dices();
  traveler_list_st traveler = init_traveler();
  push_spell(&traveler, "test");
  push_spell(&traveler, "quest");
  push_spell(&traveler, "west");
  delete_spell(&traveler, 1);
  push_item(&traveler, "alen");
  push_item(&traveler, "walen");
  push_item(&traveler, "dalen");
  delete_item(&traveler, 1);
  printf("dex = %d\n", traveler.dex);
  printf("str = %d\n", traveler.str);
  printf("chr = %d\n", traveler.chr);

  printf("money = %d\n", traveler.money);
  
  printf(
    "luck = [1 = %d, 2 = %d, 3 = %d, 4 = %d, 5 = %d, 6 = %d]\n", 
    traveler.luck[0], traveler.luck[1], traveler.luck[2],
    traveler.luck[3], traveler.luck[4], traveler.luck[5]
  );

  printf("bottle status = %d\n", traveler.bottle.status);
  printf("bottle liquid = %s\n", traveler.bottle.liquid);

  printf("weapon = %s\n", traveler.weapon);

  printf("SPELLS:\n");
  
  for(int i = 0; i < 10; i++) {
    if(!traveler.spells[i]) break;
    printf("%s\n",traveler.spells[i]);
  }

  printf("ITEMS:\n");

  for(int j = 0; j < 7; j++) {
    if(!traveler.items[j]) break;
    printf("%s\n",traveler.items[j]);
  }

  return 0;
}