#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Función para reemplazar todas las ocurrencias de 'from' por 'to' en 'str'
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty()) return;

    size_t startPos = 0;
    while((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}

int main(int argc, char* argv[]) {
    // Verificar el número correcto de argumentos
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string fileContent;
    std::string line;

    // Abrir el archivo original
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return 1;
    }

    // Leer el contenido del archivo
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    fileContent = buffer.str();
    inputFile.close();

    // Reemplazar s1 por s2 en el contenido del archivo
    replaceAll(fileContent, s1, s2);

    // Crear el nombre del nuevo archivo
    std::string newFilename = filename + ".replace";

    // Abrir el nuevo archivo para escribir el contenido modificado
    std::ofstream outputFile(newFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Could not create file: " << newFilename << std::endl;
        return 1;
    }

    outputFile << fileContent;
    outputFile.close();

    return 0;
}
