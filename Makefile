all: project4 redirout

project4: project4.c
	gcc -Wall -Wextra -o project4 project4.c

redirout: redirout.c
	gcc -Wall -Wextra -o redirout redirout.c

clean:
	rm -f project4 redirout
