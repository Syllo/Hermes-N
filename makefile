main : main.o ConfigFile.o Contact.o
	g++ -Wall -o main main.o ConfigFile.o Contact.o
	
main.o : main.cpp ConfigFile.h
ConfigFile.o : ConfigFile.cpp ConfigFile.h
Contact.o : Contact.cpp Contact.h

%.o : %.cpp
	g++ -Wall -c $<

clean :
	rm *.o main
