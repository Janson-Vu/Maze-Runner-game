game:
	g++ -c -std=c++11 main.cpp 
	g++ -c -std=c++11 main.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	g++ main.o -o sfml-app -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

test-p1:
	g++ -c PlayerTest.cpp
	g++ -c PlayerTest.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ PlayerTest.o -o sfml-app-test -lsfml-graphics -lsfml-window -lsfml-system
	g++ PlayerTest.o -o sfml-app-test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app-test

test-p2:
	g++ -c PlayerMovementTest.cpp
	g++ -c PlayerMovementTest.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ PlayerMovementTest.o -o sfml-app-test -lsfml-graphics -lsfml-window -lsfml-system
	g++ PlayerMovementTest.o -o sfml-app-test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app-test

test-p3:
	g++ -c PlayerMovementTest2.cpp
	g++ -c PlayerMovementTest2.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ PlayerMovementTest2.o -o sfml-app-test -lsfml-graphics -lsfml-window -lsfml-system
	g++ PlayerMovementTest2.o -o sfml-app-test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app-test

test-path:
	g++ -c PathTest.cpp
	g++ -c PathTest.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ PathTest.o -o sfml-app-test -lsfml-graphics -lsfml-window -lsfml-system
	g++ PathTest.o -o sfml-app-test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app-test

test-door:
	g++ -c DoorTest.cpp
	g++ -c DoorTest.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ DoorTest.o -o sfml-app-test -lsfml-graphics -lsfml-window -lsfml-system
	g++ DoorTest.o -o sfml-app-test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app-test

test-key:
	g++ -c KeyTest.cpp
	g++ -c KeyTest.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
	g++ KeyTest.o -o sfml-app-test -lsfml-graphics -lsfml-window -lsfml-system
	g++ KeyTest.o -o sfml-app-test -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app-test
