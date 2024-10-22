#include "template.tpp"

int main() {
    try {
        // Probamos con un std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        std::cout << "Buscando 3 en el vector..." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Valor encontrado: " << *it << std::endl;

        std::cout << "Buscando 5 en el vector..." << std::endl;
        it = easyfind(vec, 5);  // Esto lanzará una excepción
        std::cout << "Valor encontrado: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    try {
        // Probamos con un std::list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::cout << "Buscando 20 en la lista..." << std::endl;
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Valor encontrado: " << *it << std::endl;

        std::cout << "Buscando 50 en la lista..." << std::endl;
        it = easyfind(lst, 50);  // Esto lanzará una excepción
        std::cout << "Valor encontrado: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}
