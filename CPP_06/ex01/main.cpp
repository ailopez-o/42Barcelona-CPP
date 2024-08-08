#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data originalData(42, 3.14f, "Hello World");
    std::cout << "Original Data: " << originalData.intValue << ", " << originalData.floatValue << ", " << originalData.stringValue << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data: " << deserializedData->intValue << ", " << deserializedData->floatValue << ", " << deserializedData->stringValue << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}
