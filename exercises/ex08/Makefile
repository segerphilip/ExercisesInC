CC = gcc

TARGET = ex_compile

LIB = -lglib-2.0

INCLUDES = -I/usr/include/glib-2.0 -I/usr/local/lib/glib-2.0/include

all: $(TARGET)
	$(TARGET): $(TARGET).c
	$(CC) $(INCLUDES) $(LIB) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
