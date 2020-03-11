#include <stdio.h>
#include <stdlib.h>

int digito (char c);
char maiuscula (char c);
int comprimento (char* s);
void copia (char* destino, char* origem);
int compara (char* s1, char* s2);

int main () {
	printf ("Testando os exercicios de hoje.\n");

	printf ("\nPrimeiro exercicio:\nEntre com um caractere.\n");
	char ch1;
	scanf (" %c", &ch1);
	int dig = digito (ch1);
	if (dig == 1) {
		printf ("Esse caractere eh um digito.\n");
	}
	else {
		printf ("Esse caractere nao eh um digito.\n");
	}

	printf ("\nSegundo exercicio:\nEntre com um caractere.\n");
	char ch2;
	scanf (" %c", &ch2);
	char ch3 = maiuscula (ch2);
	printf ("Seu caractere: %c .\n", ch3);

	printf ("\nTerceiro exercicio:\nEntre com uma palavra.\n");
	char* str1 = (char*) malloc (sizeof(char)*12); //isso ta certo?
	scanf (" %s", str1);
	int com = comprimento (str1);
	printf ("O tamanho da palavra entrada eh: %d .\n", com);

	printf ("\nQuarto exercicio:\nA palavra entrada anterirormente sera copiada.\n");
	char* str2 = (char*) malloc (sizeof(char)*12);
	copia (str1, str2);
	printf ("String origem: %s - String destino: %s. \n", str1, str2);

	printf ("\nQuinto exercicio:\nEntre com uma palavra.\n");
	char* str3; //tomar cuidado com essa tb
	int resultado = compara (str2, str3);
	switch (resultado) {
		case 0:
			printf ("As duas palavras sao iguais.\n");
		break;

		case -1:
			printf ("A palavra %s precede %s .\n", str2, str3);
		break;

		case 1:
			printf ("A palavra %s precede %s .\n", str3, str2);
		break;

		default:
		 printf ("Eita!\n");
	}

	free(str1);
	free(str2);
}

int digito (char c) {
	//Informar se o caractere c eh um digito ou não
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

char maiuscula (char c) {
	//se o caractere entrado for minusculo ele se tornara maisculo, caso contrario permanecera o mesmo
	char l;
	if (c >= 'a' && c <= 'z') {
		l = 'A' + (c - 'a');
	} else {
		l = c;
	}
	return l;
}

int comprimento (char* s) {
	//criando a funcao strlen
	int i;
	for (i=0; s[i] != '\0'; i++) {
		//nada acontece aqui??? sera que da?
	}
	return i; //talvez o retorno tenha que ser i -1?
}

void copia (char* destino, char* origem) {
	//criando a funcao strcpy
	int tamanho = comprimento (origem);
	int i;
	for (i=0; i <= tamanho; i++) {
		destino[i] = origem[i];
	}
	destino[i] = '\0';
}

int compara (char* s1, char* s2) {
	//criando a funcao strcmp
	//se igual o retorno eh 0. se s1 precede s2 retorna -1, se s2 precede s1 retorna 1
	int i;
	for (i=0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] != s2[i]) {
			if (s1[i] < s2[i]) {
				return -1;
			}
			else {
				return 1;
			}
		}
	}
	if (s1[i] == s2[i]) {
		return 0;
	}
	else if (s1[i] == '\0') {
		return -1;
	}
	else {
		return 1;
	}
}
