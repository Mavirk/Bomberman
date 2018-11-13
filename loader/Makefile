NAME=				bomberman
RM=					rm -f
INC=				-I /goinfre/rmurdoch/.brew/include 
LIB=				-L /goinfre/rmurdoch/.brew/lib -lGLEW.2.1 -lglfw.3.2  -I ~/.brew/include -framework OpenGL
CPPFLAGS=			-Wall -Wextra -Werror
SRC=				main.cpp \
					game.cpp \
					model.cpp\
					mesh.cpp\
					shader.cpp\


OBJ=				$(SRC:.cpp=.o)

all:
	g++ $(CPPFLAGS) $(SRC) $(LIB) $(INC) -o $(NAME)

clean:
					$(RM) $(OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					clean fclean all