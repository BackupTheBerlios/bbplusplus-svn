CC=g++
CXXFLAGS=-Wall -g3 -pedantic -ansi
LIBS=-lreadline -lcurses
SOURCES=bbstart.cc commands.cc configure.cc main.cc ui.cc units.cc \
	tasks/audiomenu.cc tasks/burnermenu.cc tasks/cdinfomenu.cc \
	tasks/datamenu.cc tasks/imagemenu.cc tasks/mainmenu.cc \
	tasks/tempdirmenu.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=BashBurn2

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(OBJECTS) -o $@

TAGS: $(SOURCES)
	etags $(SOURCES)

clean:
	rm -rf *.o tasks/*.o $(EXECUTABLE) TAGS
