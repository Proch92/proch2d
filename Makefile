all:
	g++ -c src/p2d.cpp src/Window.cpp src/Image.cpp

	ar rvs libp2d.a p2d.o Window.o Image.o