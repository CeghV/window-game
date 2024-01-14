CC=g++
WCC=x86_64-w64-mingw32-g++
make:
	$(CC) -pthread -o wiga window.cpp glad.c -lglfw -lGL -lXrandr -lX11 -lrt -ldl
windows:
	$(WCC) -I/usr/local/include -L/usr/local/lib -static-libgcc -static-libstdc++ -pthread -o wiga.exe window.cpp glad.c -lglfw3 -lgdi32 -lopengl32
clean:
	rm wiga