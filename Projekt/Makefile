ARGS = 

run:
	g++ -c -o Edge.o Edge.cpp
	g++ -c -o GraphAsMatrix.o GraphAsMatrix.cpp
	g++ -c -o Labyrinth.o Labyrinth.cpp
	g++ -o Main.o Main.cpp Labyrinth.cpp Edge.cpp GraphAsMatrix.cpp
	./Main.o $(ARGS)
	@echo 
	@make clean

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
