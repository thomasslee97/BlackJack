#define CARDS_IN_HAND 5

enum State {
    STATE_WELCOME_MESSAGE,
    STATE_SHOW_INSTRUCTIONS,
    STATE_WAIT_FOR_START,
    STATE_RESET_ALL_VALUES,
    STATE_DEAL_CARDS_PLAYER,
    STATE_DEAL_CARDS_DEALER,
    STATE_WAIT_FOR_PLAYER_CHOICE,
    STATE_CALCULATE_HANDS,
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

extern int playerHand[CARDS_IN_HAND];
extern int dealerHand[CARDS_IN_HAND];

extern int playerCards;
extern int dealerCards;

char* cardsToString(int);

int cardsToValue(int, int);

void dealToPlayer(enum Player);

void printHand(enum Player, char*);
