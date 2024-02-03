# Establece el directorio raíz desde donde empezar la búsqueda
ROOT_DIR := $(PWD)

# Comando para encontrar todos los Makefile, excluyendo el Makefile raíz
MAKEFILES := $(shell find $(ROOT_DIR) -mindepth 2 -name 'Makefile')

# Regla por defecto
all:
	@echo "Ejecutando 'make re' en cada Makefile encontrado:"
	$(foreach mkfile,$(MAKEFILES),echo "En el directorio $(dir $(mkfile))"; cd $(dir $(mkfile)) && $(MAKE) re && cd $(ROOT_DIR);)

# Regla ficticia para evitar conflictos con archivos del mismo nombre
.PHONY: all
