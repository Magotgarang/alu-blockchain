CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LDFLAGS = -lssl -lcrypto

SRC = cli.c wallet.c transactions.c mining.c blockchain.c
OBJ = $(SRC:.c=.o)
EXEC = blockchain_cli

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

