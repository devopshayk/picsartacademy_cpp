// #include <iostream>


// // template<typename T>
// // auto max(T)
// // int main() {

// //     max<int>(3.4); // int double
// //     // max(3.3, 3, 4); // d, d
// //     return 0;
// // }

// #include <iostream>

// // Наш кирпичик (упрощенно)
// template<typename T, T v>
// struct integral_const {
//     static constexpr T value = v;
// };  

// // Сокращения для удобства
// using true_type  = integral_const<bool, true>;
// using false_type = integral_const<bool, false>;

// // 1. Общий случай: типы T и U разные
// template<typename T, typename U>
// struct is_same : false_type {};

// // 2. Частичная специализация: когда оба типа — T
// template<typename T>
// struct is_same<T, T> : true_type {};

// // --- Проверка ---
// int main() {
//     std::cout << std::boolalpha;
    
//     std::cout << "int == int: " << is_same<int, int>::value << std::endl;   // true
//     std::cout << "int == float: " << is_same<int, float>::value << std::endl; // false
    
//     // Важно: для компилятора int и const int — это РАЗНЫЕ типы
//     std::cout << "int == const int: " << is_same<int, const int>::value << std::endl; // false
    
//     return 0;
// }

// // 1. Общий случай: тип НЕ является ссылкой. 
// // Мы просто отдаем его как есть.
// template<typename T>
// struct remove_reference {
//     using type = T;
// };

// // 2. Специализация для lvalue-ссылки (&)
// // Если нам пришел T&, мы игнорируем амперсанд и вытаскиваем только T.
// template<typename T>
// struct remove_reference<T&> {
//     using type = T;
// };


// #include <iostream>

// int main() {
//     std::vector<int> ;


// }



// ----------------------------T-T-----------------------------

// #include <iostream>


// template <typename T, typename U>
// struct is_same {
//     static const bool value = false;
// };

// template <typename T>
// struct is_same<T, T> {
//     static const bool value = true;
// };




// template <typename T>
// struct is_const {
//     static const bool type = false; 
// };


// template <typename T>
// struct is_const<const T> {
//     static const bool type = true;
// };




// template <typename T>
// struct rem_ref {
//     using type = T;
// };

// template <typename T>
// struct rem_ref<T&> {
//     using type  = T;
// };


// int main() {
//     std::cout << is_same<int, int>::value;
//     std::cout << is_same<int, double>::value;

//     std::cout << is_const<const int>::type;
//     std::cout << is_const<int>::type;

//     rem_ref<int&>::type;
//     rem_ref<int>::type;
// }



// ---------------- Fold Expression -----------

#include <iostream>
 


template <typename... Args>
void printAll(Args... arg) {
    ((std::cout << arg << "\n"), ...);
}


int main() {
    printAll(1, 2, 3, 4);
}