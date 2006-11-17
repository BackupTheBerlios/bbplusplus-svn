CC=g++
CFLAGS=-c -Wall -pedantic -O0 -g3 -pg
LDFLAGS=
SOURCES=testfile.cc inputhandler.cc menudisplayer.cc mainstate.cc \
	action.cc menu.cc menuitem.cc commands.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=bashburn++

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

