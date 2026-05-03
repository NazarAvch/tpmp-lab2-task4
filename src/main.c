
/**
 * @file main.c
 * @brief Главная программа для работы со структурой Person
 * @author Ваше имя
 * @version 1.0
 * 
 * Программа выполняет:
 * 1. Чтение данных о людях из файла input.txt
 * 2. Поиск самого молодого человека
 * 3. Вывод результата на экран и сохранение в output.txt
 */

#include "person.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Person *persons = NULL;
    Person youngest;
    int count = 0;
    
    printf("========================================\n");
    printf("Программа поиска самого молодого человека\n");
    printf("========================================\n\n");
    
    /* Чтение данных из файла */
    if (!readPersonsFromFile("input.txt", &persons, &count)) {
        printf("Программа завершена с ошибкой.\n");
        return 1;
    }
    
    if (count == 0) {
        printf("В файле нет данных о людях.\n");
        free(persons);
        return 0;
    }
    
    printf("Успешно прочитано %d записей.\n\n", count);
    
    /* Вывод всех прочитанных записей */
    printf("--- Список всех людей ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nЧеловек №%d:\n", i + 1);
        printPerson(&persons[i]);
    }
    
    /* Поиск самого молодого */
    findYoungest(persons, count, &youngest);
    
    /* Вывод результата */
    printf("\n========================================\n");
    printf("РЕЗУЛЬТАТ: САМЫЙ МОЛОДОЙ ЧЕЛОВЕК\n");
    printf("========================================\n");
    printPerson(&youngest);
    
    /* Сохранение результата в файл */
    if (writePersonToFile("output.txt", &youngest)) {
        printf("\nРезультат успешно сохранён в файл output.txt\n");
    } else {
        printf("\nОшибка при сохранении результата в файл\n");
    }
    
    /* Освобождение памяти */
    free(persons);
    
    printf("\nПрограмма завершена.\n");
    return 0;
}
