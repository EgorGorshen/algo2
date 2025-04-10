run: build
	@echo "[---------- running ----------]"
	@./main
	@echo "\n[-------- end running --------]"

build:
	@echo "[--------- building ---------]"
	@clang++ main.cpp -o main -std=c++20
	@echo "[-------- end building --------]"

next:
	@mv main.cpp @1.cpp
	@touch main.cpp

test:
	@echo "[---------- testing ----------]"
	@cat test.txt | make run
	@echo "[-------- end testing --------]"

