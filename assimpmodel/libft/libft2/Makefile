# var
UNAME := $(shell uname)
CC = gcc
NAME = libft.a
CFLAGS = -Werror -Wextra -Wall
OBJDIR = obj/
HEADERDIR = .
INCLUDES_DIR = includes
INCLUDES = $(INCLUDES_DIR)/libft.h $(INCLUDES_DIR)/ft_printf.h \
		   $(INCLUDES_DIR)/get_next_line.h
SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isblk.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strbchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_lstend.c \
	   ft_strrev.c \
	   ft_malloc.c \
	   ft_lsort.c \
	   ft_swap.c \
	   ft_lstsort.c \
	   ft_memdup.c \
	   ft_strfjoin.c \
	   ft_putnchar.c \
	   ft_lstcat.c \
	   ft_lstlen.c \
	   ft_lstat.c \
	   ft_lstmergesort.c \
	   get_next_line.c \
	   ft_realloc.c \
	   ft_len_untill.c \
	   ft_lstpush.c \
	   ft_zutoa.c \
	   ft_strjoinnchar.c \
	   ft_strreplace.c \
	   ft_strinsert.c \
	   ft_convert_base.c \
	   ft_lltoa.c \
	   ft_tablen.c \
	   printf.c \
	   ft_power.c \
	   ft_atoi_printf.c \
	   ft_action_dp.c \
	   ft_print_d.c \
	   ft_action_uxo.c \
	   ft_action_sc.c \
	   ft_action_bonus.c \
	   ft_action_bonus2.c \
	   ft_action_bonus3.c \
	   ft_action_bonus4.c \
	   ft_action_bonus5.c \
	   ft_action_bonus6.c \
	   ft_wchar.c \
	   ft_ftoa.c \
	   ft_ftohex.c \
	   ft_fwrite.c \
	   ft_init_info.c \
	   ft_select_f.c \
	   ft_action.c \
	   ft_upper_case.c \
	   ft_str_alphawash.c \
	   ft_atof.c \
	   ft_rsqrt.c \
	   ft_free.c \
	   ft_freetab.c \
	   ft_split_cmd.c \
	   ft_rm.c \
	   ft_switch_icanon.c \
	   ft_tabdup.c \
	   ft_strsplitstr.c \
	   ft_strclean.c \
	   ft_isnumber.c \
	   hash.c \
	   ft_stronly.c \
	   ft_strlower.c \
	   connect_server.c \
	   create_server.c \
	   ft_match.c \
	   ft_lstdup.c \
	   ft_lstchrpos.c \
	   ft_lstcmp.c \
	   ft_lstrr.c \
	   ft_lstdelif.c \
	   read_arg.c \
	   ft_tabjoin.c \
	   ft_isspace.c \
		ft_has_char.c \
		ft_has_char_rev.c \
		ft_is_lowercase.c \
		ft_is_uppercase.c \
		ft_strchr_rev.c \
		tablen.c \
		ft_lsttotab.c \
		ft_close.c \
		ft_lstclean.c \



#ifeq ($(UNAME_S),Darwin)
#	   ft_ntime.c
#endif
HEADER = libft.h
OBJS = $(addprefix $(OBJDIR),$(subst .c,.o,$(SRCS)))

NB=`echo $(OBJS) | wc -w | bc`

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	ar r $@ $(OBJS)
	ranlib $@

printf/libftprintf.a:
	make -C printf

$(OBJS): | $(OBJDIR)

$(OBJDIR)%.o : %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) -I $(INCLUDES_DIR) $< -o $@

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then \
		mkdir $(OBJDIR);\
		fi

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

proper: all clean

re: fclean all

test: $(NAME)
	@[ "$(MAIN_TEST)" ] || \
		echo "You have to set MAIN_TEST (and ARGV)";
	@[ "$(MAIN_TEST)" ] && $(CC) $(MAIN_TEST) libft.a \
		-o  $(subst .c,.out,$(MAIN_TEST)) -I$(HEADERDIR)
	@[ "$(MAIN_TEST)" ] && ./$(subst .c,.out,$(MAIN_TEST)) $(ARGV)
