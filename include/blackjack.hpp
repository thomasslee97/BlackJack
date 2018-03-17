#include <iostream>

#include <array>

#define CARDS_PER_HAND 5
#define SPACING_CHARACTER " "

using namespace std;

enum State {
    STATE_WELCOME_MESSAGE,
    STATE_SHOW_INSTRUCTIONS,
    STATE_WAIT_FOR_START,
    STATE_RESET_ALL_VALUES,
    GAME_LOOP,
    FINAL_STATE_ENTRY
};

enum Card {
    CARD_TWO,
    CARD_THREE,
    CARD_FOUR,
    CARD_FIVE,
    CARD_SIX,
    CARD_SEVEN,
    CARD_EIGHT,
    CARD_NINE,
    CARD_TEN,
    CARD_JACK,
    CARD_QUEEN,
    CARD_KING,
    CARD_ACE,
    FINAL_CARD_ENTRY
};

enum Player {
    PLAYER_HUMAN,
    PLAYER_DEALER,
    FINAL_PLAYER_ENTRY
};

extern array<int, CARDS_PER_HAND> playerHand;
extern array<int, CARDS_PER_HAND> dealerHand;

extern int playerCards;
extern int dealerCards;

string cardsToString(int);

int cardsToValue(int, int);

void dealToPlayer(enum Player);

void printHand(string, int, string);

void printDealerHand(const array<int, CARDS_PER_HAND>);

string handToString(const array<int, CARDS_PER_HAND>);

int countHand(const array<int, CARDS_PER_HAND>, int);

char getPlayerInput(void);

void ClearScreen(void);

void MakeDealerMove(void);

void BusySleep(void);

int CheckForWinner(const array<int, CARDS_PER_HAND>, const array<int, CARDS_PER_HAND>);
