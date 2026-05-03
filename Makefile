# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./src
TARGET = lab3_task4

# Директории
SRCDIR = src
OBJDIR = obj
DATADIR = data

# Исходные файлы
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Правило по умолчанию
all: $(TARGET)

# Компоновка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Компиляция .c в .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание папки для объектных файлов
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Создание примера входного файла (если не существует)
create-input:
	@if not exist $(DATADIR)\input.txt ( \
		mkdir $(DATADIR) 2>nul & \
		echo Иванов Иван Иванович Мужской Русский 180 75 1990 05 15 +375291234567 220000 Беларусь Минская Минский Минск Ленина 10 25 > $(DATADIR)\input.txt & \
		echo Петрова Анна Сергеевна Женский Белоруска 165 60 1995 08 22 +375297654321 220001 Беларусь Минская Минский Минск Пушкина 5 12 >> $(DATADIR)\input.txt & \
		echo Сидоров Алексей Петрович Мужской Русский 175 70 2000 12 10 +375331112233 220002 Беларусь Минская Минский Минск Горького 15 7 >> $(DATADIR)\input.txt & \
		echo Козлова Елена Владимировна Женский Русский 168 55 1988 03 01 +375295554444 220003 Беларусь Минская Минский Минск Сурганова 20 30 >> $(DATADIR)\input.txt & \
		echo Соколов Дмитрий Николаевич Мужской Белорус 185 80 2005 07 19 +375447776655 220004 Беларусь Минская Минский Минск Калиновского 8 45 >> $(DATADIR)\input.txt & \
		echo Файл input.txt создан в папке $(DATADIR) & \
	) else ( \
		echo Файл input.txt уже существует & \
	)

# Очистка
clean:
	rm -rf $(OBJDIR) $(TARGET) output.txt

# PHONY цели
.PHONY: all run clean create-input
