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

// std::vector<int> getDays(time_t startTimestamp,time_t stopTimestamp)
// {
//     std::vector<int> dateList;
//     // char buffer[256];

//     // while ( startTimestamp < stopTimestamp )
//     // {
//     //     struct tm * timeinfo;
//     //     timeinfo = localtime ( &startTimestamp );

//     //     strftime (buffer,256,"%Y-%m-%d",timeinfo);
//     //     std::cout << buffer << std::endl;
//     //     dateList.push_back( buffer );

//     //     startTimestamp += 24 * 60 * 60;
//     // }
//     dateList.push_back(startTimestamp - stopTimestamp );
//     return dateList;
// }

// int main(){
//     double number = 2156384444499.4333333;
//     if (number > 100)
//         std::cout << number << std::endl;
        
//     std::vector<int> node = getDays(2011, 1970);
//     std::vector<int>::iterator first = node.begin();
//     std::vector<int>::iterator last = node.end();
//     while(first != last){
//         std::cout << *first << std::endl;
//         first++;
//     }
// }