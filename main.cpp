#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct data_base{
    std::string name = " ";
    std::string surname = " ";
    std::string date = " ";
    std::string sum = " ";
};
bool test () {
    char tempo;
    std::ifstream checking;
    checking.open("P:\\Meaning.txt");
    checking >> tempo;
    checking.close();
    if (tempo == '\0') {
        return false;
    }
    return true;
}

int main() {
    std::vector<data_base> meaning;
    meaning.push_back(data_base());
    std::string date_name[4] {"Name", "Surname", "Date", "Sum"};
    std::string command, word, answer = "yes";
    do {
        std::cout << "Enter command: (add/list)";
        std::cin >> command;
        if (command == "add") {
            std::ofstream book;
            book.open("P:\\Meaning.txt");
            book << "";
            int b = 0;
            while (answer == "yes") {
                std::cout << "Enter " << date_name[b];
                std::cin >> word;
                book << word << " ";
                b++;
                if (b > 0 && b % 4 == 0) {
                    book << "\n";
                    std::cout << "Do you want to continue entering data? (yes/no)";
                    std::cin >> answer;
                    b = 0;
                }
            }
            book.close();
        }
        else if (command == "list") {
            std::ifstream load;
            load.open("P:\\Meaning.txt");
            if (!test()) {
                std::cout << "The file is empty, enter the data!";
            }
            else {
                for (int count = 0; !load.eof(); count++) {
                    meaning.push_back(data_base());
                    load >> meaning[count].name >> meaning[count].surname >> meaning[count].date >> meaning[count].sum;
                }
            }
            load.close();
            for (int r = 0; r < meaning.size(); r++) {
                std::cout << meaning[r].name << " " << meaning[r].surname << " " << meaning[r].date << " " << meaning[r].sum << "\n";
            }


        }
        else {
            std::cout << "Command error!";
        }
        std::cout << "Continue the program? (yes/no)";
        std::cin >> answer;
    } while (answer == "yes");
}
