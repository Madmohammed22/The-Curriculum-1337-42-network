#include <iostream>

class Megaphone{
    public : void toUpper(char *str){
        for (int i = 0; i < ft_strlen(str); i++){
            char c = str[i];
            std :: cout << (char)toupper(c);
        }       
        std::cout << std::ends;
    }
    int ft_strlen(char *str);
};

int Megaphone :: ft_strlen(char *str){
    int i = 0;
    while (str[i])
        i++;
    return (i);
}


int main(int argc, char **argv){
    if (argc < 2){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_FAILURE); 
    }
    Megaphone result;
    for (int i = 1; i < argc; i++) {
        result.toUpper(argv[i]);
    }
    std :: cout << std :: endl;

    return (EXIT_SUCCESS);
}
