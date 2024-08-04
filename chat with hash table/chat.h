#pragma once
#include "string.h"
#include <iostream>
#define SIZE 10
#define LOGINLENGTH 10
#pragma once

#include <string.h>

#define NAMELENGTH 10  // Зафикируем длину имени

class Chat { // хэш таблица
public:

    Chat();
    ~Chat();
    void reg(std::string us_login, std::string us_pas);
    bool login(std::string us_login, std::string us_pas);
private:

    enum enPairStatus {
        free,
        engaged,
        deleted
    };

    struct Pair { // пара ключ-значение

        Pair() :
            login(""),
            password(""),
            status(enPairStatus::free)
        {}
        Pair(std::string us_login, std::string us_pas) :
            login(us_login),
            password(us_pas),
            status(enPairStatus::engaged) {}
        Pair& operator = (const Pair& other) {
            login = other.login;
            password=other.password;
            status = other.status;

            return *this;
        }

        bool operator == (const Pair& other) {
            return  status == other.status &&
                (status != enPairStatus::engaged || login==other.login && password==other.password);
        }

        std::string login;
        std::string password;
        enPairStatus status;
    };
    void resize();
    int hash_func(std::string login, int offset);
    Pair* array;
    int mem_size;
    int count;
};