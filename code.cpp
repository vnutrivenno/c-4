#include <iostream>
#include <string>
#include <algorithm>
#include <random>


std::string reverse(const std::string& word) {
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}


std::string removeVowels(const std::string& word) {
    std::string result = word;
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }), result.end());
    return result;
}


std::string removeConsonants(const std::string& word) {
    std::string result = word;
    result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
        return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') ||
               (c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U');
    }), result.end());
    return result;
}


std::string shuffle(const std::string& word) {
    std::string shuffled = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int main() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Слово выводится задом наперед.\n";
        std::cout << "2. Вывести слово без гласных.\n";
        std::cout << "3. Вывести слово без согласных.\n";
        std::cout << "4. Рандомно раскидывать буквы заданного слова.\n";
        std::cout << "5. Выйти.\n";

        int choice;
        std::cout << "Выберите действие (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Результат: " << reverse(word) << std::endl;
                break;
            case 2:
                std::cout << "Результат: " << removeVowels(word) << std::endl;
                break;
            case 3:
                std::cout << "Результат: " << removeConsonants(word) << std::endl;
                break;
            case 4:
                std::cout << "Результат: " << shuffle(word) << std::endl;
                break;
            case 5:
                std::cout << "Выход.\n";
                return 0;
            default:
                std::cout << "Некорректный ввод. Пожалуйста, выберите число от 1 до 5.\n";
        }
    }

    return 0;
}
