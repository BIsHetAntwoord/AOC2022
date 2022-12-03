// Utility to convert input files to templates

#include <iostream>
#include <string>

std::string escape(char c) {
    if(c == '\n')
        return "\\n";
    else
        return std::string(1, c);
}

int main() {
    size_t read_characters = 0;
    std::cout << "// Auto-generated input file" << std::endl;

    std::cout << "#include \"utils/list.hpp\"" << std::endl;
    std::cout << "#include \"utils/primitives.hpp\"" << std::endl << std::endl;

    std::cout << "using Input = ";

    while(std::cin) {
        char c = std::cin.get();

        if(std::cin) {
            if(c == '\r')
                continue;

            std::cout << "List<Char<\'" << escape(c) << "\'>, ";
            ++read_characters;
        }
    }

    std::cout << "ListEnd";

    for(size_t i = 0; i < read_characters; ++i)
        std::cout << ">";
    std::cout << ";" << std::endl;

    return 0;
}