#include "chat.h"

Chat::Chat() {
    count = 0;
    mem_size = 8;
    array = new Pair[mem_size];
}
Chat::~Chat() {
    delete[] array;
}
int Chat::hash_func(std::string us_login, int offset) {
    // вычисляем индекс
    int sum = 0, i = 0;
    for (; i < us_login.length(); i++) {
        sum += us_login[i];
    }
    const double coefficient = 0.1;
    const int constant = 3;
    // квадратичные пробы
    return (constant * (double(coefficient * sum) - int(coefficient * sum) + offset * offset));
}
void Chat::resize() {

    Pair* save = array;
    int save_ms = mem_size;

    mem_size *= 2;
    array = new Pair[mem_size];
    count = 0;

    for (int i = 0; i < save_ms; i++) {
        Pair& old_pair = save[i];
        if (old_pair.status == enPairStatus::engaged) {
            reg(old_pair.login, old_pair.password);
        }
    }

    delete[] save;
}
void Chat::reg(std::string us_login, std::string us_pas) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(us_login,i);
        if (index >= mem_size) {
            resize();
        }
        if (array[index].status == enPairStatus::free) {
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }
    array[index] = Pair(us_login, us_pas);
    count++;        
}
bool Chat::login(std::string us_login, std::string us_pas) {
    for (int i = 0; i < mem_size; i++)
    {
        int index = hash_func(us_login, i);
        if (index >= mem_size)
        {
            std::cout << "wrong login or password";
            return false;
        }
        if (array[index].login == us_login && array[index].password == us_pas)
        {
            std::cout << "Successfully logged in!";
            return true;
        }
    }
    std::cout << "wrong login or password";
    return false;
}