all: family

family: main.o familyTree.o
	g++ -o $@ $^
