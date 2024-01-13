CC=g++
make:
	$(CC) -pthread -o wiga window.cpp glad.c -lglfw -lGL -lXrandr -lX11 -lrt -ldl
clean:
	rm wiga