#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>

std::string read_till_comma(std::istringstream& iss){
    std::string answr;
    char inp_c;
    while (iss >> inp_c) {
        if(inp_c == ',') break;
        answr.push_back(inp_c);
    }
    // std::cout << "! " << answr << " !\n";
    return answr;
}

template<typename T>
T read_value(std::istringstream& iss){
    auto buffer = read_till_comma(iss);
    std::istringstream tmp(buffer);
    T value;
    tmp >> value;
    // std::cout << value << "\n";
    return value;
}

template<typename... args>
std::tuple<args...> parse_line(std::istringstream& iss){
    return std::tuple<args...>{read_value<args>(iss) ...};
}

template<typename... args>
std::vector<std::tuple<args...>> csv_read(std::ifstream& inpfile){
    std::string buffer_line;
    std::vector<std::tuple<args...>> ret_arr;
    if (inpfile.is_open()) {
        while ( getline (inpfile, buffer_line) ) {
            std::istringstream buffer_stream(buffer_line);
            ret_arr.push_back(parse_line<args...>(buffer_stream));
        }
        inpfile.close();
    }
    return ret_arr;
}

int main(){
    std::ifstream fin("test.csv");
    if(!fin.is_open()){
        std::cout << "Error while opening file test.csv" << std::endl;
        return 1;
    }
    auto data = csv_read<int, std::string, double>(fin);
    for(auto& tup : data){
        std::cout << std::get<0>(tup) << '\t';
        std::cout << std::get<1>(tup) << '\t';
        std::cout << std::get<2>(tup) << '\n';
    }
    return 0;
}