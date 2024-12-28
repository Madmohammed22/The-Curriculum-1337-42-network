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