#include <stdio.h>

int main(void) {
  int numero;
  int potenziale_radice;
  int trovata_radice_intera = 0; // 0 = falso

  printf("Inserisci il numero: ");
  scanf("%i", &numero);

  for (potenziale_radice = 1;
       potenziale_radice <= numero && !trovata_radice_intera;
       potenziale_radice++)
    if (potenziale_radice * potenziale_radice == numero)
      trovata_radice_intera = 1; // 1 = vero

  if (trovata_radice_intera)
    printf("%i e' un quadrato perfetto\n", numero);
  else
    printf("%i non e' un quadrato perfetto\n", numero);

  return 0;
}
