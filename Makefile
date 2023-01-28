SRCS_FILES = pushswap.c parse.c tools.c swap.c checkswap.c printlst.c algo.c \
algoii.c check_algo.c 100.c 100part2.c 100part3.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_PATH = ./sorces/
CC = cc
NAME = push_swap
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
BONUS_PATH = ./bonus/
BONUS_FILES = bonus.c checkswap_bonus.c parse_bonus.c swap_bonus.c \
gnl/get_next_line.c gnl/get_next_line_utils.c
BONUS = $(addprefix $(BONUS_PATH), $(BONUS_FILES))
CHECKER = checker

# Reset
Color_Off=\033[0m

# Regular Colors
Black=\033[0;30m       # Black
Red=\033[0;31m         # Red
Green=\033[0;32m       # Green
Yellow=\033[0;33m       # Yellow
Blue=\033[0;34m
Purple=\033[0;35m       # Purple
Cyan=\033[0;36m         # Cyan
White=\033[0;37m        # White

# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m       # Green
BYellow=\033[1;33m      # Yellow
BBlue=\033[1;34m
BPurple=\033[1;35m    	  # Purple
BCyan=\033[1;36m        # Cyan
BWhite=\033[1;37m       # White

# Underline
UBlack=\033[4;30m
URed=\033[4;31m
UGreen=\033[4;32m       # Green
UYellow=\033[4;33m     # Yellow
UBlue=\033[4;34m        # Blue
UPurple=\033[4;35m      # Purple
UCyan=\033[4;36m        # Cyan
UWhite=\033[4;37m       # White

# Background
On_Black=\033[40m       # Black
On_Red=\033[41m         # Red
On_Green=\033[42m       # Green
On_Yellow=\033[43m      # Yellow
On_Blue=\033[44m        # Blue
On_Purple=\033[45m      # Purple
On_Cyan=\033[46m        # Cyan
On_White=\033[47m       # White

# High Intensity
IBlack=\033[0;90m
IRed=\033[0;91m         # Red
IGreen=\033[0;92m       # Green
IYellow=\033[0;93m      # Yellow
IBlue=\033[0;94m        # Blue
IPurple=\033[0;95m      # Purple
ICyan=\033[0;96m        # Cyan
IWhite=\033[0;97m       # White

# Bold High Intensity
BIBlack=\033[1;90m
BIRed=\033[1;91m        # Red
BIGreen=\033[1;92m      # Green
BIYellow=\033[1;93m     # Yellow
BIBlue=\033[1;94m       # Blue
BIPurple=\033[1;95m     # Purple
BICyan=\033[1;96m       # Cyan
BIWhite=\033[1;97m      # White

# High Intensity backgrounds
On_IBlack=\033[0;100m
On_IRed=\033[0;101m
On_IGreen=\033[0;102m
On_IYellow=\033[0;103m
On_IBlue=\033[0;104m
On_IPurple=\033[0;105m
On_ICyan=\033[0;106m
On_IWhite=\033[0;107m


$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\n    $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off)"
	@echo "    $(On_IWhite)$(BBlue)|$(BRed)P$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)U$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)S$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)H$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)S$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)W$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)A$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off) $(On_IWhite)$(BBlue)|$(BRed)P$(Color_Off)$(On_IWhite)$(BBlue).--. |$(Color_Off)"
	@echo "    $(On_IWhite)$(BBlue)| :/\: |$(Color_Off) $(On_IWhite)$(BBlue)| (\/) |$(Color_Off) $(On_IWhite)$(BBlue)| :/\: |$(Color_Off) $(On_IWhite)$(BBlue)| :/\: |$(Color_Off) $(On_IWhite)$(BBlue)| :/\: |$(Color_Off) $(On_IWhite)$(BBlue)| :/\: |$(Color_Off) $(On_IWhite)$(BBlue)| (\/) |$(Color_Off) $(On_IWhite)$(BBlue)| :/\: |$(Color_Off)"
	@echo "    $(On_IWhite)$(BBlue)| (__) |$(Color_Off) $(On_IWhite)$(BBlue)| :\/: |$(Color_Off) $(On_IWhite)$(BBlue)| :\/: |$(Color_Off) $(On_IWhite)$(BBlue)| (__) |$(Color_Off) $(On_IWhite)$(BBlue)| :\/: |$(Color_Off) $(On_IWhite)$(BBlue)| :\/: |$(Color_Off) $(On_IWhite)$(BBlue)| :\/: |$(Color_Off) $(On_IWhite)$(BBlue)| (__) |$(Color_Off)"
	@echo "    $(On_IWhite)$(BBlue)| *--*$(BRed)P$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)U$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)S$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)H$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)S$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)W$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)A$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off) $(On_IWhite)$(BBlue)| *--*$(BRed)P$(Color_Off)$(On_IWhite)$(BBlue)|$(Color_Off)"
	@echo "    $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off) $(On_IWhite)$(BBlue)o------o$(Color_Off)"
	@echo "$(BPurple)			Good To Go!"

all: $(NAME)

bonus: $(BONUS)
	@$(CC) $(CFLAGS) $(BONUS) -o $(CHECKER)

clean:
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(CHECKER)
	@echo "$(BYellow)ALL CLEAN!!$(Color_Off)"

re: fclean all