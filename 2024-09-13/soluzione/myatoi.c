// restitiusce il numero decimale le cui cifre sono quelle di p
// seguite dai caratteri si s, che si assume essere tra il
// carattere dello 0 e il carattere del 9 inclusi;
// questa funzione deve essere ricorsiva
long myatoip(long p, char *s) {
  if (*s == '\0')
    return p;
  else
    return myatoip(p * 10 + *s - '0', s + 1);
}

// restituisce il numero decimale ottenuto trasformando
// la stringa s in un long; la stringa s si assume che contenga
// solo caratteri tra il carattere dello 0 e il carattere del 9 inclusi;
// questa funzione deve usare myatoip
long myatoi(char *s) {
  return myatoip(0, s);
}
