# Makefile with dependencies management (Q4)

CXX        = clang++
CXXFLAGS   = -Wall  -std=c++17
DEPFLAGS   = -MMD
LDFLAGS    =
SRCS       = magasin.cpp main.cpp produit.cpp client.cpp commande.cpp
OBJS       = $(SRCS:.cpp=.o)
TARGET     = app
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)