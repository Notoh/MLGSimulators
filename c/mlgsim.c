#include "mlgsim.h"


static struct Doritos {
    int PtsTurn;
    int cost;
    int count;
};

static struct Dew {
    int PtsTurn;
    int cost;
    int count;
};

struct Doritos doritos;
struct Dew dew;

void assign(void) {
    doritos.cost = 30;
    doritos.PtsTurn = 10;
    dew.cost = 60;
    dew.PtsTurn = 20;
}

int main(int argc, char *argv[]) {
    assign();

    int MLGPoints = 100; //default value

    printf("\n\t------MLG Simulator by Alex Pawelko-----\t\n");

    for(int i = 1; i < 16; i++) {
        printf("\n\tYou are on turn %i.", i);
        printf("\n\tYou earned %d MLG Points this turn!",CalcPtsTurn());
        MLGPoints += CalcPtsTurn();
        printf("\n\tYou have %i MLG Points.", MLGPoints);
        printf("\n\tCurrently you have %i Doritos and %d litre(s) of Mountain Dew.", doritos.count,dew.count);

        printf("\n\tDo you want to buy any Doritos? Doritos cost %i and earn %d MLG Points per turn. If you do not "
                       "wish to buy any type 0.\n",doritos.cost, doritos.PtsTurn);
        int amount;

        scanf("%d",&amount);
        if (amount > 0) {
            int attempt = 0;
            for(; attempt < amount; attempt++) {
                if(MLGPoints - doritos.cost >= 0) {
                    ++doritos.count;
                    MLGPoints -= doritos.cost;
                } else {
                    printf("\n\tYou didn't have enough MLGPoints to buy all those Doritos.");
                    break;
                }
            }
            printf("\n\tYou now have %i Doritos.", doritos.count);
        } else if (amount < 0) {
            printf("\n\tDid you fail Grade 2 math? You can't buy a negative amount of Doritos.");
        }

        printf("\n\tDo you want to buy any Mountain Dew? Mountain Dew costs %i per litre and earn %d MLG Points per "
                       "turn. If you do not wish to buy any type 0.\n",dew.cost, dew.PtsTurn);

        int amount1;
        scanf("%d",&amount1);
        if(amount1 > 0) {
            int attempt = 0;
            for(; attempt < amount1; attempt++) {
                if(MLGPoints - dew.cost >= 0) {
                    ++dew.count;
                    MLGPoints -= dew.cost;
                } else {
                    printf("\n\tYou didn't have enough MLGPoints to buy all that Mountain Dew.");
                    break;
                }
            }
            printf("\n\tYou now have %i litres of Mountain Dew.",  dew.count);
        } else if(amount1 < 0) {
            printf("\n\tDid you fail Grade 2 math? You can't buy a negative quantity of Mountain Dew.");
        }
        printf("\n\tTurn %i has ended.", i);
        printf("\n\t------------------------------------------------");
    }

    printf("The game has ended with you scoring %i MLG Points, %d Doritos and %d litres of Mountain Dew!",MLGPoints,
           doritos.count,dew.count);
    return 0;
}

int CalcPtsTurn(void) {
    int dor = doritos.count*doritos.PtsTurn;
    int bdew = dew.count*dew.PtsTurn;
    return dor+bdew;
}
