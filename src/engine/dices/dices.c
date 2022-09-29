#include <time.h>
#include <stdlib.h>

void init_dices(){
    srand(time(NULL));
}

unsigned short roll_dices(int n) {
    unsigned short result = 0;
    for(int i = 0; i < n; i++){
        result += rand() % 6 + 1;
    }
    return result;
};