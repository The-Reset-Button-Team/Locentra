#include <iostream>
#include <vector>

#include "ingestion/loader.hpp"

int main()
{
    std::cout << "Locentra starting..." << std::endl;

    Loader loader;

    std::vector<std::string> documents =
        loader.load("data/documents");

    std::cout << "Loaded "
              << documents.size()
              << " document(s)"
              << std::endl;

    return 0;
}
