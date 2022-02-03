#ifndef FFP_TUM_INPUTHANDLER_HPP
#define FFP_TUM_INPUTHANDLER_HPP

#include <string>

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

template <typename T>
void getUserInput(T& value, const std::string& promptMsg) {
    while (true) {
        std::cout << promptMsg;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();  // reset out of failure mode (caused by invalid data type or over-/underflow)
            clearInputBuffer(); // remove incorrect input
            std::cout << "Invalid value specified.\n";
        } else {
            clearInputBuffer();
            break;
        }
    }
}
#endif //FFP_TUM_INPUTHANDLER_HPP
