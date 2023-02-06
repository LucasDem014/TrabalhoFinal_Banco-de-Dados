all:	domain.o domainTest.o entity.o entityTest.o libraryTest.exe
	+$(MAKE) -C ../ControllerObjs

domain.o:	../../lib/Domains/domain.cpp
	g++ -std=c++17 -Wall -c ../../lib/Domains/domain.cpp

entity.o:	../../lib/Entities/entity.cpp
	g++ -std=c++17 -Wall -c ../../lib/Entities/entity.cpp
