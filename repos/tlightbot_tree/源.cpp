#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>

using namespace std;
using namespace std::filesystem;
namespace fs = std::filesystem;
void demo_status(const fs::path& p, fs::file_status s)
{
    std::cout << p;
    switch (s.type())
    {
    case fs::file_type::none: std::cout << " has `not-evaluated-yet` type"; break;
    case fs::file_type::not_found: std::cout << " does not exist"; break;
    case fs::file_type::regular: std::cout << " is a regular file"; break;
    case fs::file_type::directory: std::cout << " is a directory"; break;
    case fs::file_type::symlink: std::cout << " is a symlink"; break;
    case fs::file_type::block: std::cout << " is a block device"; break;
    case fs::file_type::character: std::cout << " is a character device"; break;
    case fs::file_type::fifo: std::cout << " is a named IPC pipe"; break;
    case fs::file_type::socket: std::cout << " is a named IPC socket"; break;
    case fs::file_type::unknown: std::cout << " has `unknown` type"; break;
    default: std::cout << " has `implementation-defined` type"; break;
    }
    std::cout << '\n';
}

void enumdir(fs::path& directory)
{
    fs::file_status s;
    fs::path p;
    string str;
    for (auto it = fs::directory_iterator(directory); it != fs::directory_iterator(); ++it)
    {
        char* pdir;
        std::cout << *it << std::endl;
        s = it->symlink_status();
        switch (s.type())
        {
        case fs::file_type::regular:
            //std::cout << " is a regular file"; 
            break;
        case fs::file_type::directory:
            p = *it;
            //str = p.filename();
            //std::cout << " is a directory"; 
            enumdir(p);
            break;
        }
    }
    //demo_status(*it, it->symlink_status()); // use cached status from directory entry
}
int main()
{
    fs::path  dir = ".";

    enumdir(dir);



    getchar();
}