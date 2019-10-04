LIBS=-lsfml-graphics -lsfml-window -lsfml-system
all:
	g++ -c "main.cpp" -o main.o
	g++ -c "gui_lib/gui_lib.cpp" -o gui_lib.o
	
	g++ -o integra_editor main.o gui_lib.o $(LIBS)

clb:
	rm -f *.o

clean:
	rm -f integra_editor
install:
	cp integra_editor /usr/bin

uninstall:
	rm integra_editor