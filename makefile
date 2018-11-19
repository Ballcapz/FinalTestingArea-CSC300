SOURCES=main.cpp

trains.out: $(SOURCES)
	g++ main.cpp -o $@

trains_debug.out: $(SOURCES)
	g++ -g main.cpp -o $@
