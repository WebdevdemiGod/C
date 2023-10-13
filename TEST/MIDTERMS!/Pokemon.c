#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define Pokemon statistics structure
typedef struct {
    int hp;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
    int overall_rating;
} PokemonStatistics;

// Define a Pokemon structure
typedef struct {
    char name[50]; // Pokemon name
    PokemonStatistics stats;
} Pokemon;

// Define a Pokedex using a singly linked list
typedef struct PokedexNode {
    Pokemon pokemon;
    struct PokedexNode* next;
} PokedexNode;

typedef struct {
    PokedexNode* head;
} Pokedex;

// Define a Deck using a cursor-based stack
#define MAX_DECK_SIZE 50

typedef struct {
    Pokemon deck[MAX_DECK_SIZE];
    int cursor; // Cursor to keep track of the top of the stack
} Deck;

// Define a Tile using a circular array queue
#define MAX_TILE_SIZE 6

typedef struct {
    Pokemon tile[MAX_TILE_SIZE];
    int front; // Index of the front of the queue
    int rear;  // Index of the rear of the queue
} Tile;

// Define a Discard using an array stack
#define MAX_DISCARD_SIZE 50

typedef struct {
    Pokemon discard[MAX_DISCARD_SIZE];
    int top; // Index of the top of the stack
} Discard;

// Define a GameUser
typedef struct {
    Deck deck;
    Tile tile;
    Discard discard;
} GameUser;

// Function to insert a Pokemon into the Pokedex as the first element
void insertFirst(Pokedex* pokedex, Pokemon pokemon) {
    PokedexNode* newNode = (PokedexNode*)malloc(sizeof(PokedexNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for PokedexNode\n");
        exit(1);
    }

    newNode->pokemon = pokemon;
    newNode->next = pokedex->head;
    pokedex->head = newNode;
}

// Function to initialize a Deck
void initializeDeck(Deck* deck) {
    deck->cursor = -1;
}

// Function to push a Pokemon onto the Deck
void push(Deck* deck, Pokemon pokemon) {
    if (deck->cursor < MAX_DECK_SIZE - 1) {
        deck->deck[++(deck->cursor)] = pokemon;
    } else {
        fprintf(stderr, "Deck is full. Cannot push more Pokemon.\n");
    }
}

// Function to check if the Deck is empty
bool isDeckEmpty(Deck* deck) {
    return (deck->cursor == -1);
}

// Function to enqueue a Pokemon into the Tile (circular array queue)
void enqueue(Tile* tile, Pokemon pokemon) {
    int nextRear = (tile->rear + 1) % MAX_TILE_SIZE;
    if (nextRear != tile->front) { // Check if the queue is not full
        tile->tile[nextRear] = pokemon;
        tile->rear = nextRear;
    } else {
        fprintf(stderr, "Tile is full. Cannot enqueue more Pokemon.\n");
    }
}

// Function to check if the Tile is empty
bool isTileEmpty(Tile* tile) {
    return (tile->front == tile->rear);
}

// Function to pop a Pokemon from the Discard (array stack)
void popDiscard(Discard* discard) {
    if (discard->top > 0) {
        discard->top--;
    } else {
        fprintf(stderr, "Discard is empty. Cannot pop more Pokemon.\n");
    }
}

// Function to display the GameUser's information
void displayGameUser(GameUser* user, Pokedex* pokedex) {
    printf("Pokemon:\n");
    for (int i = 0; i <= user->deck.cursor; i++) {
        printf("%s\n", user->deck.deck[i].name);
    }

    printf("\nStats:\n");
    for (int i = 0; i <= user->deck.cursor; i++) {
        Pokemon pokemon = user->deck.deck[i];
        printf("Name: %s\n", pokemon.name);
        printf("HP: %d\n", pokemon.stats.hp);
        printf("Attack: %d\n", pokemon.stats.attack);
        printf("Defense: %d\n", pokemon.stats.defense);
        printf("Special Attack: %d\n", pokemon.stats.special_attack);
        printf("Special Defense: %d\n", pokemon.stats.special_defense);
        printf("Speed: %d\n", pokemon.stats.speed);
        printf("Overall Rating: %d\n", pokemon.stats.overall_rating);
        printf("-------\n");
    }
}

int main() {
    Pokedex pokedex;
    pokedex.head = NULL;

    PokemonStatistics pikachu_stats = {60, 55, 40, 50, 50, 90, 7};
    Pokemon pikachu = {"Pikachu", pikachu_stats};
    insertFirst(&pokedex, pikachu);

    GameUser user;
    initializeDeck(&(user.deck));
    user.tile.front = user.tile.rear = 0;
    user.discard.top = 0;

    Pokemon charizard = {"Charizard", {78, 84, 78, 109, 85, 100, 9}};
    push(&(user.deck), charizard);

    Pokemon blastoise = {"Blastoise", {79, 83, 100, 85, 105, 78, 8}};
    enqueue(&(user.tile), blastoise);

    displayGameUser(&user, &pokedex);

    return 0;
}