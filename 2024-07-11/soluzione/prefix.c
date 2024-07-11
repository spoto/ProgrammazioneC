// determina se la stringa s1 e' un prefisso della stringa s2;
// questa funzione deve essere ricorsiva
int prefix(char *s1, char *s2) {
  return *s1 == '\0' || (*s1 == *s2 && prefix(s1 + 1, s2 + 1));
}
