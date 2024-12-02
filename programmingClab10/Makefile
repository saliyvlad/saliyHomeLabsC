CC=gcc                       # Компилятор
CFLAGS=-Wall -Wextra        # Флаги компиляции

all: main                    # Цель по умолчанию

main: main.o utils.o         # Зависимости для цели main
	$(CC) -o main main.o utils.o  # Команда для создания исполняемого файла

main.o: main.c               # Зависимость для main.o
	$(CC) $(CFLAGS) -c main.c     # Команда для компиляции main.c

utils.o: utils.c             # Зависимость для utils.o
	$(CC) $(CFLAGS) -c utils.c    # Команда для компиляции utils.c

clean:                       # Цель для очистки
	rm -f *.o main               # Удаление объектных файлов и исполняемого файла
