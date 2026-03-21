CXXFLAGS += -Wall -Wextra -Weffc++ -std=c++14 -MMD

top-vec: main.o
	g++ -o $@ $^

-include main.d

clean:
	rm -rf *.d *.o top-vec

run:
	./top-vec
