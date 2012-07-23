#######################################################################
#    makefile                                                         #
#                                                                     #
#    Copyright (C) 2011, 2012 by Suhel Momin                          #
#                                                                     #
#    You may distribute under the terms of the GNU General Public     #
#    License as specified in the README file.                         #
#                                                                     #
#######################################################################
 
#
# Make file for the nsmart programming language
#

###############################################i
IDIR =../include
ODIR = obj
CC = gcc
CFLAGS = -g -DYYDEBUG -DYYERROR_VERBOSE -I$(IDIR)
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =       	error.o         \
                config.o        \
                command.o       \
                command_func.o  \
                sym_tab.o       \
                sym_arg_tab.o   \
                symbol.o        \
                run.o           \
                support_run.o   \
                stack.o         \
                io.o            \
                io_unix.o            \
                main.o          \
                parser.o        \
		nsmart.tab.o	\
		lex.yy.o	\
                op.o           	

OBJ= $(patsubst %,$(ODIR)/%,$(_OBJ))


###############################################


all: nn

base: parser lexer

parser:
	@echo -----Generating Parser code----
	bison -r all -t -d nsmart.y 
	@echo -----Parser Done----


lexer:
	@echo -----Generating Lexer code----
	flex nsmart.l
	@echo -----Lexer Done----

$(ODIR)/%.o:%.c 
	$(CC) -c -o $@ $< $(CFLAGS)

nn: $(OBJ)
	@echo ----Generating nn----
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS)
	@echo -----DONE----


.PHONY: clean
 
clean-base:	
	rm -f nsmart.tab.h    	\
              nsmart.tab.c    	\
              nsmart.output   	\
              lex.yy.c        
clean:
	rm -f 	$(ODIR)/*.o 	\
		$(ODIR)/nn 	\
		*~ core 	


