
/**
 * @file person.h
 * @brief Заголовочный файл для работы со структурой Person
 * @author Ваше имя
 * @version 1.0
 */

#ifndef PERSON_H
#define PERSON_H

#define MAX_STR 50
#define MAX_PHONE 20
#define MAX_STREET 100
#define MAX_PERSONS 100

/**
 * @struct Address
 * @brief Структура для хранения адреса
 */
typedef struct {
    int zip;                     /**< Почтовый индекс */
    char country[MAX_STR];       /**< Страна */
    char region[MAX_STR];        /**< Область */
    char district[MAX_STR];      /**< Район */
    char city[MAX_STR];          /**< Город */
    char street[MAX_STREET];     /**< Улица */
    int house;                   /**< Дом */
    int apartment;               /**< Квартира */
} Address;

/**
 * @struct BirthDate
 * @brief Структура для хранения даты рождения
 */
typedef struct {
    int year;    /**< Год */
    int month;   /**< Месяц (1-12) */
    int day;     /**< День (1-31) */
} BirthDate;

/**
 * @struct Person
 * @brief Структура для хранения информации о человеке
 */
typedef struct {
    char lastName[MAX_STR];      /**< Фамилия */
    char firstName[MAX_STR];     /**< Имя */
    char patronymic[MAX_STR];    /**< Отчество */
    char gender[10];             /**< Пол */
    char nationality[MAX_STR];   /**< Национальность */
    int height;                  /**< Рост (см) */
    int weight;                  /**< Вес (кг) */
    BirthDate birthDate;         /**< Дата рождения */
    char phone[MAX_PHONE];       /**< Номер телефона */
    Address address;             /**< Домашний адрес */
} Person;

/**
 * @brief Чтение данных о людях из текстового файла
 * @param filename Имя файла для чтения
 * @param persons Указатель на массив указателей на Person (будет выделена память)
 * @param count Указатель на переменную для количества прочитанных записей
 * @return 1 при успехе, 0 при ошибке
 */
int readPersonsFromFile(const char *filename, Person **persons, int *count);

/**
 * @brief Нахождение самого молодого человека
 * @param persons Массив структур Person
 * @param count Количество записей
 * @param youngest Указатель на структуру для сохранения результата
 */
void findYoungest(const Person *persons, int count, Person *youngest);

/**
 * @brief Запись информации о человеке в файл
 * @param filename Имя файла для записи
 * @param p Указатель на структуру Person для записи
 * @return 1 при успехе, 0 при ошибке
 */
int writePersonToFile(const char *filename, const Person *p);

/**
 * @brief Сравнение двух дат рождения
 * @param date1 Первая дата
 * @param date2 Вторая дата
 * @return 1 если date1 > date2 (младше), -1 если date1 < date2 (старше), 0 если равны
 */
int compareBirthDates(const BirthDate *date1, const BirthDate *date2);

/**
 * @brief Вывод информации о человеке на экран
 * @param p Указатель на структуру Person
 */
void printPerson(const Person *p);

#endif /* PERSON_H */
