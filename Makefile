CXX=g++
CFLAGS = -pedantic -Wall
INCLUDE=-I/usr/include/SFML
LDFLAGS=-L /usr/lib -lsfml-graphics -lsfml-window -lsfml-system

OBJS = App.o Cell.o
OUT=app

app: $(OBJS)
	$(CXX) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS) && rm -v *.o && ./$(OUT)

clean:
	rm -v *.o $(OUT)
