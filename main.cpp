#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <clocale>
#if defined(_WIN32)
#include <windows.h>
#endif

#include "transportFactory.hpp"

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "");
    std::locale::global(std::locale());

#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    if (argc < 2)
    {
        std::cout << u8"Использование: " << argv[0]
                  << u8" <тип_транспорта_1> ... <тип_транспорта_n> (цифрой)" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Transport>> transports;

    for (size_t i = 1; i < argc; ++i)
    {
        try
        {
            int value = std::stoi(argv[i]);
            auto transport = TransportFactory::create(static_cast<TransportType>(value));
            transports.push_back(std::move(transport));
        }
        catch (...)
        {
            transports.push_back(nullptr);
        }
    }

    std::cout << u8"\nИнформация о транспорте:\n";

    for (size_t i = 0; i < transports.size(); ++i)
    {
        if (transports[i])
        {
            transports[i]->print();
        }
        else
        {
            std::cout << u8"НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА\n";
        }

        std::cout << "\n";
    }

    return 0;
}