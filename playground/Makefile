
NAME=				bomberman
RM=					rm -f
INC=				-I ~/.brew/include 
LIB=				-L ~/.brew/lib -lGLEW.2.1 -lglfw.3.2  -I ~/.brew/include -framework OpenGL
CPPFLAGS=			-Wall -Wextra -Werror
SRC=				main.cpp \
					game.cpp \
					model.cpp \
					shader.cppv \
					camera.cpp \
					mesh.cpp 


COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m


OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

NAME=	bomberman

RM=		rm -f

FLAGS=	clang++ -std=c++11 -Wall -Wextra -Werror

INC=	-I $(HOME)/.brew/include 
LIB=	-L $(HOME)/.brew/lib -lGLEW.2.1 -lglfw.3.2  -I $(HOME)/.brew/include -framework OpenGL

SRC=	main.cpp \
		game.cpp \
		camera.cpp

OBJ=	$(SRC:.cpp=.o)

all: dependencies
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
	@$(FLAGS) $(SRC) $(LIB) $(INC) -o $(NAME)

dependencies:
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@)$(NO_COLOR)\n";
	@if ! test -d ~/.brew/Library; \
	then sh brew_install.sh; \
		printf "%b" "$(OK_COLOR)Brew installed\n"; \
	else \
		printf "%b" "$(WARN_COLOR)Brew is already installed\n"; \
	fi

	@if ! test -d ~/.brew/Cellar/glfw; \
	then brew install glfw3; \
	fi
	@if ! test -d ~/.brew/Cellar/glew; \
	then brew install glew; \
	fi
	@if ! test -d ~/.brew/Cellar/assimp; \
	then brew install assimp; \
	fi; \
	

	@printf "%b" "$(OK_COLOR)Dependencies installed\n"; \

clean:
					$(RM) $(OBJ)

fclean:				clean
					$(RM) $(NAME)

uninstall:
	@if test -d ~/.brew/Library; \
	then sh brew_uninstall.sh; \
	else \
		printf "%b" "$(WARN_COLOR)Brew has already been uninstalled\n"; \
	fi

re:					clean fclean all