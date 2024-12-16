CC=gcc                       
CFLAGS=-Wall -Wextra        

all: main                    

main: main.o utils.o         
	$(CC) -o main main.o utils.o  

main.o: main.c               
	$(CC) $(CFLAGS) -c main.c     

utils.o: utils.c             
	$(CC) $(CFLAGS) -c utils.c    

clean:                       
	rm -f *.o main              
