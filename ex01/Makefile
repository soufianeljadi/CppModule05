CXX = c++
SRC = main.cpp Bureaucrat.cpp Form.cpp 
OBJ = $(SRC:.cpp=.o)
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Form

all: $(NAME)

$(NAME): $(OBJ) Bureaucrat.hpp Form.hpp
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean  