NAME = RPN
COMPILER = c++ -Wall -Wextra -Werror -std=c++11 # BUNU KESİN DÜZELT!!!!!!!!!!!!!
SRC = *.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re