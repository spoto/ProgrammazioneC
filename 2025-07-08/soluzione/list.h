#define CHAR_MAX 50
#define SCORE_MAX 4

typedef struct player{
    int id;
    char nickname[CHAR_MAX];
    float best_scores[SCORE_MAX];
    struct player *next;
} Player;


Player* newPlayer(int id, const char nickname[], float *best_scores);
int listLen(Player *head);
Player* insertPlayer(Player *head, Player *new);
Player* insertInOrder(Player *head, Player *new);
float getMean(float best_scores[]);
Player* createTopPlayersList(Player *head, float mediaTop);
void printList(Player *head);
void destroyList(Player *head);
