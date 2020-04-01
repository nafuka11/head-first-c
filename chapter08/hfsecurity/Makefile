CC			= gcc

MAIN_NAME	= bank_vault
MAIN_SRCS	= bank_vault.c

LIB_NAME	= hfsecurity
LIB_FILE	= lib$(LIB_NAME).a
LIB_SRCS	= encrypt.c \
			  checksum.c
LIB_OBJS	= $(LIB_SRCS:.c=.o)

$(MAIN_NAME)	: $(MAIN_SRCS) $(LIB_FILE)
	$(CC) $(MAIN_SRCS) -I. -L. -l$(LIB_NAME) -o $(MAIN_NAME)

.c .o			:
	$(CC) -c $< -o $@

$(LIB_FILE)		: $(LIB_OBJS)
	ar -rcs $(LIB_FILE) $(LIB_OBJS)

clean			:
	rm -f $(LIB_OBJS)
	rm -f $(LIB_FILE)
	rm -f $(MAIN_NAME)

.PHONY			: clean
