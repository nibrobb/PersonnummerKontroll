BIN = pnrkontroll
SRC = kontroll.c
INSTALL_DIR = /usr/local/bin/

.PHONY: all
.PHONY: clean
.PHONY: install

all: $(BIN)

$(BIN): $(SRC)
	$(CC) -o $(BIN) $(SRC)

install: all
	cp $(BIN) $(INSTALL_DIR)

clean:
	rm -f $(BIN) kontroll_cpp


kontroll_cpp: kontroll.cpp
	g++ $< -o $@ -Wall -Wextra -Wpedantic -O3
