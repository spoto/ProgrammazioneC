struct sentence {
  char *word;
  struct sentence *next;
};

struct sentence *construct_sentence(char *words[], int length);
void free_sentence(struct sentence *s);
int length_sentence(struct sentence *s);
char *concat_sentence(struct sentence *s);
char *inverse_concat_sentence(struct sentence *s);
