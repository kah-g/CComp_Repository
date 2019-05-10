all:app
app: *.o
	gcc -o app *.o
*.o: *.c
	gcc -c *.c
clean:
	rm -rf *.o
run: app
	valgrind ./app
