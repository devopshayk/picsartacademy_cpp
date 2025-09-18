#include <iostream>
#include <string>

    void reversed(std::string& s);

    int main() {
        std::string word;

        std::cout << "Write text for reverse: ";
        std::cin >> word;

        reversed(word);

        std::cout << "Reversed text: " << word << std::endl;;

        return 0;
    }

    void reversed(std::string& s) {
        int length = s.size();

        for(int i = 0; i < length / 2; i++) std::swap(s[i], s[length - i - 1]);
    }