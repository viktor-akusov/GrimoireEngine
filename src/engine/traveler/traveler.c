#include <stdbool.h>
#include <stdio.h>
#include "traveler.h"
#include "../dices/dices.h"

traveler_list_st init_traveler() {
    traveler_list_st traveler;

    unsigned short roll = roll_dices(2);

    switch (roll)
    {
        case 2:
            traveler.dex = 8;
            traveler.str = 22;
            traveler.chr = 8;
            break;
        case 3:
            traveler.dex = 10;
            traveler.str = 20;
            traveler.chr = 6;
            break;
        case 4:
            traveler.dex = 12;
            traveler.str = 16;
            traveler.chr = 5;
            break;
        case 5:
            traveler.dex = 9;
            traveler.str = 18;
            traveler.chr = 8;
            break;
        case 6:
            traveler.dex = 11;
            traveler.str = 20;
            traveler.chr = 6;
            break;
        case 7:
            traveler.dex = 9;
            traveler.str = 20;
            traveler.chr = 7;
            break;
        case 8:
            traveler.dex = 10;
            traveler.str = 16;
            traveler.chr = 7;
            break;
        case 9:
            traveler.dex = 8;
            traveler.str = 24;
            traveler.chr = 7;
            break;
        case 10:
            traveler.dex = 9;
            traveler.str = 22;
            traveler.chr = 6;
            break;
        case 11:
            traveler.dex = 10;
            traveler.str = 18;
            traveler.chr = 7;
            break;
        case 12:
            traveler.dex = 11;
            traveler.str = 20;
            traveler.chr = 5;
            break;
        default:
            break;
    }

    traveler.money = 15;

    traveler.bottle.status = FULL;
    traveler.bottle.liquid = "water";

    traveler.weapon = "sword";

    int cross_a = roll_dices(1) - 1;
    int cross_b = roll_dices(1) - 1;

    for(int i = 0; i < 6; i++) {
        traveler.luck[i] = true;
        if(i == cross_a || i == cross_b) {
            traveler.luck[i] = false;
        } 
    }

    for(int i = 0; i < 10; i++) {
        traveler.spells[i] = NULL;
    }

    for(int i = 0; i < 7; i++) {
        traveler.items[i] = NULL;
    }

    return traveler;
}

signed short push_spell(traveler_list_st* traveler, char name[]){
    int i;
    
    for(i = 0; i < 10; i++) {
        if (!traveler->spells[i]) break; 
    }

    if (i > 9) return -1;
    
    traveler->spells[i] = name;
    
    return 0;
};

void delete_spell(traveler_list_st* traveler, unsigned short position){
    if (position > 9) return;
    for(int i = position; i <= 10; i++) {
        if(i < 10 && traveler->spells[i]) {
            if(i + 1 > 9) {
                traveler->spells[i] = NULL;
            } else {
                traveler->spells[i] = traveler->spells[i+1];
            }
        }
    }
}

signed short push_item(traveler_list_st* traveler, char name[]){
    int i;
    
    for(i = 0; i < 7; i++) {
        if (!traveler->items[i]) break; 
    }

    if (i > 6) return -1;
    
    traveler->items[i] = name;
    
    return 0;
};

void delete_item(traveler_list_st* traveler, unsigned short position){
    if (position > 6) return;
    for(int i = position; i <= 7; i++) {
        if(i < 7 && traveler->items[i]) {
            if(i + 1 > 6) {
                traveler->items[i] = NULL;
            } else {
                traveler->items[i] = traveler->items[i+1];
            }
        }
    }
}
