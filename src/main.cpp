#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char *argv[])
{
    constexpr size_t CHUNK_SIZE = 8;
    if (argc < 2)
    {
        std::cout << "Must provide a filename" << std::endl;
        return 0;
    }
    std::ifstream ifs(argv[1], std::ifstream::binary);
    if (!ifs.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }
    std::cout << "OFFSET     HEX BYTES" << std::endl;
    std::cout << std::setfill('0') << std::hex;
    size_t bytes_processed = 0;
    char x;
    while (ifs.get(x))
    {
        if (bytes_processed % CHUNK_SIZE == 0)
        {
            std::cout << std::setw(8) << bytes_processed << "  ";
        }
        bytes_processed++;
        int val = static_cast<int>(static_cast<unsigned char>(x));
        std::cout << " ";
        std::cout << std::setw(2) << val;
        if (bytes_processed % CHUNK_SIZE == 0)
        {
            std::cout << std::endl;
        }
    }
    if (bytes_processed % CHUNK_SIZE != 0)
    {
        std::cout << std::endl;
    }
    return 0;
}