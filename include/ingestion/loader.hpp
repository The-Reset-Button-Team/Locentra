#ifndef LOCENTRA_LOADER_HPP
#define LOCENTRA_LOADER_HPP

#include <string>
#include <vector>

class Loader
{
public:
    std::vector<std::string> load(const std::string& directory);
};

#endif
