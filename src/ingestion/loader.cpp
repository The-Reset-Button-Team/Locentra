#include "ingestion/loader.hpp"

#include <filesystem>
#include <fstream>
#include <iterator>

std::vector<std::string> Loader::load(const std::string& directory)
{
    std::vector<std::string> documents;

    namespace fs = std::filesystem;

    std::error_code error;

    fs::directory_iterator entries(
        directory,
        fs::directory_options::skip_permission_denied,
        error
    );

    if (error)
        return documents;

    for (const auto& entry : entries)
    {
        if (!entry.is_regular_file(error))
        {
            error.clear();
            continue;
        }

        std::ifstream file(entry.path(), std::ios::binary);

        if (!file)
            continue;

        std::string content(
            (std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>()
        );

        documents.push_back(content);
    }

    return documents;
}
