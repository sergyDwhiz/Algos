// Dealing a hand of cards -- Revisit playing cards if you badslidded :)
#include<stdio.h>
#include<stdbool.h>    // C99 
#include<stdlib.h>
#include<time.h>
#include<assert.h> (lol :)
 #define NUM_SUITS 4
 #define NUM_RANKS 13

 int main(void)
 {
    bool in_hand[NUM_SUITS][NUM_RANKS]= {false}; // Since we have no cards in hand yet
    int number_of_cards, rank, suit;
    
    const char rank_code[]= {'2','3','4','5','6','7','8',
                              '9','t','j','q','k','a'};
 const char suit_code[]= {'c','d','h','s'};
                                              /*for clubs, Diamond,
                                              Hearts, and Spade rspectively*/
    srand ((unsigned) time(NULL));
    printf("Enter number of cards in the hand:\n");
    scanf("%d", &number_of_cards);
    printf("Your hand: \n");
    while(number_of_cards>0)
    {
        suit = rand() % NUM_SUITS;  // rand from stdlib library
                                   // Picks a random suit.
        rank = rand() % NUM_RANKS; // Picks a random rank as well.
        if (!in_hand[suit][rank])
        {
        in_hand[suit][rank] = true;
        number_of_cards--;
        printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");
    return 0;
 }
 