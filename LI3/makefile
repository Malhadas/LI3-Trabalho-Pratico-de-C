##############DEFINICOES####################################
#----------------------------------------------------------#
BINARY        = GereVendas                                 #
CC            = gcc                                        #
CFLAGS        = -Wall -pedantic -g -ansi -O3               #
VALGRINDFLAGS = --leak-check=full --log-file="Valgrind.out"#
FILES         = $(shell find src -name "*.c")              #
HEADERS       = $(shell find src -name "*.h")              #
OBJS          = $(FILES:.c=.o)                             #
#----------------------------------------------------------#
############################################################ 



###############REGRAS#########################
#--------------------------------------------#
GereVendas: $(OBJS)                          
	$(CC) $(CFLAGS) $(OBJS) -o $(BINARY) 
	rm $(FILES:.c=.o)                    
#--------------------------------------------#
run: GereVendas                              
	./$(BINARY)                          
#--------------------------------------------#
apenasRun :                                  
	./$(BINARY)                          
#--------------------------------------------#
ValgrindRun:                                 
	valgrind $(VALGRINDFLAGS) ./$(BINARY)
#--------------------------------------------#
clean:                                       
	rm -f $(BINARY)                      
#--------------------------------------------#
##############################################
