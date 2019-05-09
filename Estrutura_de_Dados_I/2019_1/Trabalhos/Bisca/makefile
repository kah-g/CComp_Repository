all: app
app: Cliente_Teste.o jogo.o baralho.o 
    gcc -o app Cliente_Teste.o jogo.o baralho.o 
baralho.o: baralho.c
    gcc -o baralho.o -c baralho.c -W -Wall -ansi -pedantic
jogo.o: jogo.c
    gcc -o jogo.o -c jogo.c -W -Wall -ansi -pedantic
Cliente_Teste.o: Cliente_Teste.c jogo.h
    gcc -o Cliente_Teste.o -c Cliente_Teste.c -W -Wall -ansi -pedantic
clean:
    rm -rf *.o
mrproper: clean
    rm -rf app
