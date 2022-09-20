# Note make will substitue non-defined variables with an empty string!
CC = g++
CPP_STANDARD = 11
CFLAGS = -Wall -Wextra -std=c++$(CPP_STANDARD)

PROGS := asignaciones creaDatos cuentaPalabras paridad $\
	paridadBucle productorio seleccionPalabras sumatorio valores

TRASH := *.out *.o *.ex

info:
	@printf "Objetivos disponibles:\n"
	@printf "\t- all: Compila todos los programas y genera el ejecutable *.ex correspondiente.\n"
	@printf "\t- asignaciones: Compila el ejemplo de asignaciones y genera el ejecutable asignaciones.ex.\n"
	@printf "\t- creaDatos: Compila el ejemplo de asignaciones y genera el ejecutable creaDatos.ex\n"
	@printf "\t- cuentaPalabras: Compila el ejemplo de asignaciones y genera el ejecutable cuentaPalabras.ex\n"
	@printf "\t- paridad: Compila el ejemplo de asignaciones y genera el ejecutable paridad.ex\n"
	@printf "\t- paridadBucle: Compila el ejemplo de asignaciones y genera el ejecutable paridadBucle.ex\n"
	@printf "\t- productorio: Compila el ejemplo de asignaciones y genera el ejecutable productorio.ex\n"
	@printf "\t- seleccionPalabras: Compila el ejemplo de asignaciones y genera el ejecutable seleccionPalabras.ex\n"
	@printf "\t- sumatorio: Compila el ejemplo de asignaciones y genera el ejecutable sumatorio.ex\n"
	@printf "\t- valores: Compila el ejemplo de asignaciones y genera el ejecutable valores.ex\n"
	@printf "\t- optimiza-0: Compila el ejemplo de optimización sin optimización alguna y genera el ejecutable optimiza-0.ex\n"
	@printf "\t- optimiza-2: Compila el ejemplo de optimización con optimización-2 y genera el ejecutable optimiza-2.ex\n\n"
	@printf "\t- clean: Elimina todos los ejecutables y archivos intermedios.\n"
	@printf "\t- test-optimization: Ejecuta ambos programas de optimización mostrando los tiempos de ejecución.\n\n"
	@printf "\t- info: Muestra esta información. Este objetivo también se ejecutará si no se explicita uno.\n"

define target_template
  $(1).ex: $(1).cpp
	$(CC) -o $(1).ex $$< $(CFLAGS)
endef

$(foreach elm, $(PROGS), $(eval $(call target_template, $(elm))))

all: $(addsuffix .ex, $(PROGS) optimiza-0 optimiza-2)
	@echo "Se han compilado todos los ejecutables."

optimiza-0.ex: optimiza.cpp
	$(CC) -o $@ -O0 $< $(CFLAGS)

optimiza-2.ex: optimiza.cpp
	$(CC) -o $@ -O2 $< $(CFLAGS)

.PHONY: clean test-optimization

test-optimization: $(addsuffix .ex, optimiza-0 optimiza-2)
	@printf "Ejecutando el programa sin optimización...\n"
	@time ./optimiza-0.ex
	@printf "Ejecutando el programa optimizado...\n"
	@time ./optimiza-2.ex
	@printf "Realizado el $(shell date)\n"

clean:
	@echo "Limpiando ejecutables compilados y archivos temporales: $(TRASH)"
	@rm -f $(TRASH)
