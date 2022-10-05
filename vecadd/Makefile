all: main mainp

main: main.cpp Makefile
	g++ -Wall -Wextra -std=c++17 main.cpp -o main

mainp: mainp.cpp Makefile
	g++ -Wall -Wextra -std=c++17 mainp.cpp -o mainp -fopenmp

clean:
	rm -f main mainp
