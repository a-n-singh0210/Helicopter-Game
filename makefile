CXX = g++
SFML_PATH = /opt/homebrew/Cellar/sfml/2.6.1

CXXFLAGS = -I$(SFML_PATH)/include
LDFLAGS = -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

TARGET = helicopter_game

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
