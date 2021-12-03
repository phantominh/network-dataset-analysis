
traversals: main.o traversals.o
	clang++ -Wall -Werror -std=c++1y main.o traversals.o -o traversals

test: traversals.o traversal_tests.o
	clang++ -Wall -Werror -std=c++1y traversals.o traversals_test.o -o test

traversal_tests.o: ./tests/traversals_test.cpp
	clang++ -c -Wall -Werror -std=c++1y ./tests/traversals_test.cpp

main.o: main.cpp 
	clang++ -c -Wall -Werror -std=c++1y main.cpp

traversals.o: traversals.cpp traversals.h
	clang++ -c -Wall -Werror -std=c++1y traversals.cpp

clean:
	rm -f traversals main.o traversals.o test traversals_test.o