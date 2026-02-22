#include <iostream>
#include <vector>
#include <sstream>
#include "transportFactory.hpp"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cout << "Использование: " << argv[0] 
                << " <тип_транспорта_1> ... <тип_транспорта_n> (цифрой)" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Transport>> transports;

    for(size_t i = 1; i < argc; ++i){
        try
        {
            int value = std::stoi(argv[i]);
            auto transport = TransportFactory::create(static_cast<TransportType>(value));
            transports.push_back(std::move(transport));
        }
        catch(...)
        {
            transports.push_back(nullptr);
        }
        
    }

    std::cout << "\nИнформация о транспорте:\n";

    for (size_t i = 0; i < transports.size(); ++i) {
        if (transports[i]){
            transports[i]->print();
        } else {
            std::cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА\n";
        }

        std::cout << "\n";
    }

    return 0;
}