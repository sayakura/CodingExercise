DEPENDS =  -lglad -lglfw -lfreetype -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon
INCLUDES = -I./\
		   -Iinclude/\
		   -Iinclude/freetype\
		   -Iinclude/glad\
		   -Iinclude/GLFW\
		   -Iinclude/KHR\

all:
	g++ main.cpp  $(INCLUDES) -Llib $(DEPENDS)