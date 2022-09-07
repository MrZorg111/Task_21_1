#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

struct data_base{
    std::string name = " ";
    std::string surname = " ";
    std::string date = " ";
    std::string sum = " ";
};
int main() {
    std::vector<data_base> meaning;
    std::string command, word, answer = "yes";
    do {
        std::cout << "Enter command: (add/list) ";
        std::cin >> command;
        if (command == "add") {
            std::ofstream write;
            for (int i = 0; answer == "yes"; i++) {
                meaning.push_back(data_base());
                std::cout << "Enter name: " << "\n";
                std::cin >> word;
                meaning[i].name = word;
                std::cout << "Enter surname: " << "\n";
                std::cin >> word;
                meaning[i].surname = word;
                std::cout << "Enter date: " << "\n";
                std::cin >> word;
                meaning[i].date = word;
                std::cout << "Enter sum: " << "\n";
                std::cin >> word;
                meaning[i].sum = word;
                std::cout << "Continue the program? (yes/no) ";
                std::cin >> answer;
            }
            write.open("P:\\Meaning.txt");
            for (int w = 0; w < meaning.size(); w++) {
                write << meaning[w].name << "\t" << meaning[w].surname << "\t" << meaning[w].date << "\t"
                      << meaning[w].sum << "\n";
            }
            write.close();
        }
        else if (command == "list") {
            std::fstream read;
            std::string tempo = " ";
            int count = 0;
            read.open("P:\\Meaning.txt");
            if (!read.eof()) {
                read >> tempo;
                count++;
                std::cout << tempo << " ";
                if (count % 4 == 0) {
                    std::cout << "\n";
                }
                read.close();
            }
                else {
                std::cout << "The list is empty, enter the data. \n";
            }
        }
        else {
            std::cout << "Command error!";
        }
        std::cout << "Continue the program? (yes/no) ";
        std::cin >> answer;
    } while (answer == "yes");
}
