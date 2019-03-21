double soma (double a, double b);
double subtrai (double a, double b);
double multiplica (double a, double b);
double divide (double a, double b);
void menu ();

double soma (double a, double b) {
  return a + b;
}
double subtrai (double a, double b) {
  return a - b;
}
double multiplica (double a, double b) {
  return a * b;
}
double divide (double a, double b) {
  if (b != 0) {
    return a / b;
  } else {
    printf("Indivisivel\n");
    return 0;
  }
}

void menu () {
  printf("1 - Somar\n");
  printf("2 - Subtrair\n");
  printf("3 - Multiplicar\n");
  printf("4 - Dividir\n");
  printf("5 - Sair\n");
}
