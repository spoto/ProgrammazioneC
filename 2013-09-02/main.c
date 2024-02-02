#include "appello.h"
#include "iscritto.h"

int main(void) {
  struct appello *app = construct_appello();

  iscrivi(app, construct_iscritto("Fausto", "Spoto", 153535));
  iscrivi(app, construct_iscritto("Giovanni", "Senzaterra", 123456));
  iscrivi(app, construct_iscritto("Roberta", "Rossi", 310453));
  registra_voto(app, 123456, 28);
  registra_voto(app, 153535, 17);

  print_appello(app);
  destroy_appello(app);

  return 0;
}
