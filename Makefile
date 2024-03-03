CC=gcc
CFLAGS=-O3 -g
 
TARGET=test mandel
 
all: $(TARGET)
 
libppm.so : ppm.c
	$(CC) $(CFLAGS)  -fpic -shared $^ -o $@
 
test: main.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) main.c  -lppm -L. -o $@ -Wl,-rpath=$(PWD)

mandel: mandel.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) $< -lppm -L.  -o $@ -lm -Wl,-rpath=$(PWD)


clean:
	rm -fr $(TARGET) *.so
