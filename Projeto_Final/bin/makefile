library= ./LibraryObjs/domain.o ./LibraryObjs/entity.o
controllers= ./ControllerObjs/cntrPresentation.o ./ControllerObjs/cntrService.o
cpp_source=  ../main.cpp
flags= -lncurses -ltinfo -O2 -L/usr/lib -lmysqlcppconn

all:	main.exe
	./main.exe

main.exe:	$(library) $(controllers) $(cpp_source)
	g++ -std=c++17 -Wall $(library) $(controllers) $(cpp_source) $(flags) -o main.exe