#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
    if (argc < 1){
        return EXIT_FAILURE;
    }

    std::string file_csv_txt = argv[1];
    BitcoinExchange *bitcoinExchange = new BitcoinExchange();
    bitcoinExchange->DisplayDataCSV(bitcoinExchange->ReadFileCSV(file_csv_txt, bitcoinExchange));
    delete bitcoinExchange;
    return 0;
}

int main__(){

    char *str = new char[200];
    strcpy(str, "hello world");
    // str = strdup("hello world");
    std::cout << str << std::endl;
    delete [] str;
    return 0;
}