#include <stdbool.h>

#ifndef TRAVELER
#define TRAVELER

typedef enum bottle_status_e{
  EMPTY,
  HALF,
  FULL
} bottle_status_et;

typedef struct bottle_s {
  char* liquid;
  bottle_status_et status;
} bottle_st;

typedef struct traveler_list_s {
  unsigned short dex;
  unsigned short str;
  unsigned short chr;
  char* spells[10];
  char* items[7];
  unsigned short money;
  bottle_st bottle;
  char* weapon;
  bool luck[6];
} traveler_list_st;

// creates new traveler
traveler_list_st init_traveler();

// puts spell to the list
signed short push_spell(traveler_list_st* traveler, char name[]);

// deletes spell from the list
void delete_spell(traveler_list_st* traveler, unsigned short position);

// puts item to the list
signed short push_item(traveler_list_st* traveler, char name[]);

// deletes item from the list
void delete_item(traveler_list_st* traveler, unsigned short position);

#endif