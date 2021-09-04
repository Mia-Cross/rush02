# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schene <schene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 14:21:19 by schene            #+#    #+#              #
#    Updated: 2021/06/24 11:42:41 by schene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rush02

SRCSDIR		=  srcs

OBJDIR		= .obj

SRCS		= main.c utils.c parse_dict.c linked_list.c \
				convert_value.c search_key.c display.c

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

DPDCS		= $(OBJS:.o=.d)

INCLUDES = -I include/

CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

RM			= rm -f

CC			= gcc

opti:
	@make -j all

all : 
	@make $(NAME)

-include $(DPDCS)

$(NAME) : $(OBJS) $(LIB)
	@printf "[$(NAME)] "
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB}
	@echo Compiled $(NAME) successfully !
	@echo $(NAME) > .gitignore

#${NAME}:	${OBJS} $(LIB)
#			@echo "✅"
#			@printf "[libft] " && make -C libft
#			@printf "[$(NAME)] "
#			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB}
#			@echo "✅ \033[32mCompilation Done, ./${NAME} created.\033[0m"

$(OBJDIR) :
			@mkdir -p .obj 

$(OBJDIR)/%.o : $(SRCSDIR)/%.c | $(OBJDIR)
			@${CC} ${CFLAGS} -c $< -o $@

clean :
			@(rm -rf $(OBJDIR))

fclean :	clean
			@(rm -rf $(NAME))
			@(rm -rf a.out.dSYM)
			@(rm -f a.out)

re :
			@make fclean
			@make opti
			

