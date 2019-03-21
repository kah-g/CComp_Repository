#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float x;
  float y;
} ponto;

typedef struct {
  ponto a;
  ponto b;
} retangulo;

typedef struct {
  ponto a;
  ponto b;
  ponto c;
} triangulo;

typedef struct {
  ponto a;
  float raio;
  //ponto desnecessario
} circulo;

float ret (retangulo);

float tri (triangulo);

float cir (circulo);

int main () {
  printf("Bem vindo a Calculadora de Areas. Escolha o tipo que quer calcular.\n");
  printf("1 - Retangulo\n2 - Triangulo\n3 - Circulo\n");
  int tipo;
  scanf("%d", &tipo);
  switch (tipo) {
    case 1:
     printf("Entre com os pontos A e B\n");
     retangulo r1;
     scanf("%f %f %f %f", &r1.a.x, &r1.a.y, &r1.b.x, &r1.b.y);
     printf("A area do retangulo e: %.2f\n", ret(r1));
     break;
    case 2:
     printf("Entre com os pontos A,B e C\n");
     triangulo t1;
     scanf("%f %f %f %f %f %f\n", &t1.a.x, &t1.a.y, &t1.b.x, &t1.b.y, &t1.c.x, &t1.c.y);
     printf("A area do triangulo e: %.2f\n", tri(t1));
     break;
    case 3:
     printf("Entre com o ponto A e o raio\n");
     circulo c1;
     scanf("%f %f %f", &c1.a.x, &c1.a.y, &c1.raio);
     printf("A area do circulo: %.2f\n", cir(c1));
     break;
    default:
     printf("ERRRRRRROOOOOOOOUUUUUUUUU\n");
  }

  return 0;
}

float ret (retangulo r1) {
  float base, altura, areaRet;
  if (r1.a.x >= r1.b.x) {
    base = r1.a.x - r1.b.x;
  } else {
    base = r1.b.x - r1.a.x;
  }
  if (r1.a.y >= r1.b.y) {
    altura = r1.a.y - r1.b.y;
  } else {
    altura = r1.b.y - r1.a.y;
  }
  areaRet = base * altura;
  return areaRet;
}

float tri (triangulo t1) {
  float base, altura, areaTri;
  if ((t1.a.y > t1.b.y) && (t1.a.y > t1.c.y)) {
    altura = t1.a.y - t1.b.y;
  } else if ((t1.b.y > t1.a.y) && (t1.b.y > t1.c.y)) {
    altura = t1.b.y - t1.c.y;
  } else {
    altura = t1.c.y - t1.a.y;
  }
  if ((t1.a.x < t1.b.x) && (t1.a.x < t1.c.x)) {
    if (t1.b.x > t1.c.x) {
      base = t1.b.x - t1.a.x;
    } else {
      base = t1.c.x - t1.a.x;
    }
  } else if ((t1.b.x < t1.a.x) && (t1.b.x < t1.c.x)) {
    if (t1.a.x > t1.c.x) {
      base = t1.a.x - t1.b.x;
    } else {
      base = t1.c.x - t1.b.x;
    }
  } else {
    if (t1.a.x > t1.b.x) {
      base = t1.a.x - t1.c.x;
    } else {
      base = t1.b.x - t1.c.x;
    }
  }
  areaTri = (base * altura) / 2;
  return areaTri;
}

float cir (circulo c1) {
  float areaCir = 3.14 * (c1.raio * c1.raio);
  return areaCir;
}
