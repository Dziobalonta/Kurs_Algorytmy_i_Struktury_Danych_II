run:
	g++ -c SetAsArray.cpp -o SetAsArray.o
	g++ -o ZbioryTest.o ZbioryTest.cpp SetAsArray.cpp
	./ZbioryTest.o
	@echo 
	@make clean

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}