# Erkennung des Betriebssystems
ifeq ($(OS),Windows_NT)
    RM = del /Q
    TARGET = ostersonntag.exe
    FIX_PATH = $(subst /,\,$1)
else
    RM = rm -f
    TARGET = ostersonntag
    FIX_PATH = $1
endif

CC = gcc
CFLAGS = -Wall -I./mod
MOD_DIR = ./mod
OBJ = ostersonntag.o $(MOD_DIR)/tools.o

# Das Haupt-Target muss an erster Stelle stehen
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

ostersonntag.o: ostersonntag.c
	$(CC) $(CFLAGS) -c ostersonntag.c -o ostersonntag.o

$(MOD_DIR)/tools.o: $(MOD_DIR)/tools.c
	$(CC) $(CFLAGS) -c $(MOD_DIR)/tools.c -o $(MOD_DIR)/tools.o

clean:
	$(RM) $(TARGET)
	$(RM) *.o
	$(RM) $(call FIX_PATH,$(MOD_DIR)/*.o)

.PHONY: clean all