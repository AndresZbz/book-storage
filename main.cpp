#include <iostream>
#include <fstream>
#include <string>

class Book {
    public:
        std::string name;
        std::string author;
        std::ofstream data_file_write;
        std::ifstream data_file_read;

    void show_data() {
        data_file_read.open("data.txt");

        if(data_file_read.is_open()) {
            char data;
             while ( data_file_read ) {
                data = data_file_read.get();
                std::cout << data;
             }
        }
    }

    void save_data() {
        data_file_write.open("data.txt", std::ios_base::app);

        if(data_file_write.is_open()) {
            data_file_write << name << " by " << author << std::endl;
           
            data_file_write.close();
        }
    }
};

void add_book() {
    system("cls");

    Book new_book;
    std::cout << "Insert the book's name\n";

    std::cin.ignore();
    std::cout << "\n-> ";
    std::getline(std::cin, new_book.name);

    std::cout << "\nInsert the author's name\n";
    std::cout << "-> ";
    std::getline(std::cin, new_book.author);

    std::cout << "\nBook saved";
    new_book.save_data();
}

void current_books() {
    system("cls");

    std::cout << "Current books saved: \n";

    Book current_books;
    current_books.show_data();
}

int main() {
    system("cls");
    std::cout << "Welcome, please choose an option\n 1 - Add a new book \n 2 - See current books saved\n";
    std::cout << "\n-> ";
    int input;
    std::cin >> input;

    switch(input) {
        case 1:
            add_book();
        break;
        case 2:
            current_books();
        break;
        default:
            std::cout << "Invalid input, try again.";
    }

    return 0;
}