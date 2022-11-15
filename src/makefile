make: card.o hero.o player.o card.hpp hero.hpp player.hpp

card.o:card.hpp card.cpp
	g++ -c card.cpp -I.

card.hpp:
	g++ -c card.hpp

hero.o:card.o hero.hpp hero.cpp
	g++ -c hero.cpp -I.

hero.hpp:
	g++ -c hero.hpp

player.o:hero.o player.hpp player.cpp
	g++ -c player.cpp -I.

player.hpp:
	g++ -c player.hpp

