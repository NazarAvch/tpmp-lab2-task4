
/**
 * @file person.c
 * @brief Реализация функций для работы со структурой Person
 * @author Ваше имя
 * @version 1.0
 */

#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readPersonsFromFile(const char *filename, Person **persons, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return 0;
    }
    
    *count = 0;
    *persons = (Person*)malloc(MAX_PERSONS * sizeof(Person));
    if (*persons == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        fclose(file);
        return 0;
    }
    
    while (*count < MAX_PERSONS && 
           fscanf(file, "%s", (*persons)[*count].lastName) == 1) {
        
        fscanf(file, "%s", (*persons)[*count].firstName);
        fscanf(file, "%s", (*persons)[*count].patronymic);
        fscanf(file, "%s", (*persons)[*count].gender);
        fscanf(file, "%s", (*persons)[*count].nationality);
        fscanf(file, "%d", &(*persons)[*count].height);
        fscanf(file, "%d", &(*persons)[*count].weight);
        fscanf(file, "%d %d %d", 
               &(*persons)[*count].birthDate.year,
               &(*persons)[*count].birthDate.month,
               &(*persons)[*count].birthDate.day);
        fscanf(file, "%s", (*persons)[*count].phone);
        fscanf(file, "%d", &(*persons)[*count].address.zip);
        fscanf(file, "%s", (*persons)[*count].address.country);
        fscanf(file, "%s", (*persons)[*count].address.region);
        fscanf(file, "%s", (*persons)[*count].address.district);
        fscanf(file, "%s", (*persons)[*count].address.city);
        fscanf(file, "%s", (*persons)[*count].address.street);
        fscanf(file, "%d", &(*persons)[*count].address.house);
        fscanf(file, "%d", &(*persons)[*count].address.apartment);
        
        (*count)++;
    }
    
    fclose(file);
    return 1;
}

int compareBirthDates(const BirthDate *date1, const BirthDate *date2) {
    /* Сравнение годов */
    if (date1->year != date2->year) {
        return (date1->year > date2->year) ? 1 : -1;
    }
    /* Сравнение месяцев */
    if (date1->month != date2->month) {
        return (date1->month > date2->month) ? 1 : -1;
    }
    /* Сравнение дней */
    if (date1->day != date2->day) {
        return (date1->day > date2->day) ? 1 : -1;
    }
    return 0; /* Даты равны */
}

void findYoungest(const Person *persons, int count, Person *youngest) {
    if (count == 0) return;
    
    /* Копируем первого человека как начального кандидата */
    *youngest = persons[0];
    
    /* Ищем самого молодого (самую позднюю дату рождения) */
    for (int i = 1; i < count; i++) {
        if (compareBirthDates(&persons[i].birthDate, &youngest->birthDate) > 0) {
            *youngest = persons[i];
        }
    }
}

int writePersonToFile(const char *filename, const Person *p) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл %s\n", filename);
        return 0;
    }
    
    fprintf(file, "========================================\n");
    fprintf(file, "Самый молодой человек\n");
    fprintf(file, "========================================\n\n");
    fprintf(file, "Фамилия: %s\n", p->lastName);
    fprintf(file, "Имя: %s\n", p->firstName);
    fprintf(file, "Отчество: %s\n", p->patronymic);
    fprintf(file, "Пол: %s\n", p->gender);
    fprintf(file, "Национальность: %s\n", p->nationality);
    fprintf(file, "Рост: %d см\n", p->height);
    fprintf(file, "Вес: %d кг\n", p->weight);
    fprintf(file, "Дата рождения: %04d-%02d-%02d\n", 
            p->birthDate.year, p->birthDate.month, p->birthDate.day);
    fprintf(file, "Телефон: %s\n", p->phone);
    fprintf(file, "\n--- Адрес ---\n");
    fprintf(file, "Почтовый индекс: %d\n", p->address.zip);
    fprintf(file, "Страна: %s\n", p->address.country);
    fprintf(file, "Область: %s\n", p->address.region);
    fprintf(file, "Район: %s\n", p->address.district);
    fprintf(file, "Город: %s\n", p->address.city);
    fprintf(file, "Улица: %s\n", p->address.street);
    fprintf(file, "Дом: %d\n", p->address.house);
    fprintf(file, "Квартира: %d\n", p->address.apartment);
    fprintf(file, "========================================\n");
    
    fclose(file);
    return 1;
}

void printPerson(const Person *p) {
    printf("========================================\n");
    printf("%s %s %s\n", p->lastName, p->firstName, p->patronymic);
    printf("Пол: %s, Национальность: %s\n", p->gender, p->nationality);
    printf("Рост: %d см, Вес: %d кг\n", p->height, p->weight);
    printf("Дата рождения: %04d-%02d-%02d\n", 
           p->birthDate.year, p->birthDate.month, p->birthDate.day);
    printf("Телефон: %s\n", p->phone);
    printf("Адрес: %s, %s, %s, %s, г. %s, ул. %s, д. %d, кв. %d, %d\n",
           p->address.country, p->address.region, p->address.district,
           p->address.city, p->address.city, p->address.street,
           p->address.house, p->address.apartment, p->address.zip);
    printf("========================================\n");
}
