# Note make will substitue non-defined variables with an empty string!
CC = g++
CPP_STANDARD = 11
CFLAGS = -Wall -Wextra -Wpedantic -std=c++$(CPP_STANDARD)

PROGS := derivada/testDerivada integral/testIntegral prodEscalar/testProdEscalar $\
	raices/testRaicesPolGrado2

TRASH := *.out *.o *.ex

info:
	@printf "Objetivos disponibles:\n"
	@printf "\t- all: Compila todos los programas y genera el ejecutable *.ex correspondiente en bin/.\n"
	@printf "\t- derivada/testDerivada.ex: Compila el ejemplo de derivadas y genera el ejecutable bin/testDerivada.ex.\n"
	@printf "\t- integral/testIntegral.ex: Compila el ejemplo de integrales y genera el ejecutable bin/testIntegal.ex\n"
	@printf "\t- raices/testRaicesPolGrado2.ex: Compila el ejemplo de asignaciones y genera el ejecutable bin/testRaicesPolGrado2.ex\n"
	@printf "\t- prodEscalar/testProdEscalar.ex: Compila el ejemplo de asignaciones y genera el ejecutable bin/testProdEscalar.ex\n\n"
	@printf "\t- clean: Elimina todos los ejecutables y archivos intermedios.\n"

define target_template
  $(1).ex: $(1).cpp
	$(CC) $(CFLAGS) -o bin/$(word 2, $(subst /, , $(1))).ex $$<
endef

$(shell mkdir -p bin)

$(foreach elm, $(PROGS), $(eval $(call target_template, $(elm))))

all: $(addsuffix .ex, $(PROGS))
	@echo "Se han compilado todos los ejecutables."

.PHONY: clean

clean:
	@echo "Limpiando ejecutables compilados y archivos temporales: $(addprefix bin/, $(TRASH))"
	@rm -f $(addprefix bin/, $(TRASH))
