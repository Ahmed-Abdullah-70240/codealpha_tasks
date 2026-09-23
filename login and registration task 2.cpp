#include <iostream>
#include <fstream>
#include <string>

const std::string USER_FILE = "users.txt";

// Function to check if a username already exists in the file
bool usernameExists(const std::string& username) {
    std::ifstream file(USER_FILE.c_str());
    if (!file.is_open()) return false;

    std::string fileUser, filePass;
    while (file >> fileUser >> filePass) {
        if (fileUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function to handle user registration
void registerUser() {
    std::string username, password;
    std::cout << "\n====================================\n";
    std::cout << "          USER REGISTRATION         \n";
    std::cout << "====================================\n";
    std::cout << "Enter username: ";
    std::cin >> username;

    if (usernameExists(username)) {
        std::cout << "\n[ERROR] Username '" << username << "' already exists! Please try a different username.\n";
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> password;

    std::ofstream file(USER_FILE.c_str(), std::ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
        std::cout << "\n[SUCCESS] Registration successful! You can now log in.\n";
    } else {
        std::cout << "\n[ERROR] Unable to open database file for writing.\n";
    }
}

// Function to handle user login
void loginUser() {
    std::string username, password;
    std::cout << "\n====================================\n";
    std::cout << "             USER LOGIN             \n";
    std::cout << "====================================\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream file(USER_FILE.c_str());
    if (!file.is_open()) {
        std::cout << "\n[ERROR] User database not found. Please register first.\n";
        return;
    }

    std::string fileUser, filePass;
    bool authenticated = false;

    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            authenticated = true;
            break;
        }
    }
    file.close();

    if (authenticated) {
        std::cout << "\n[SUCCESS] Welcome back, " << username << "! Login successful.\n";
    } else {
        std::cout << "\n[ERROR] Invalid username or password. Please try again.\n";
    }
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n====================================\n";
        std::cout << "    LOGIN & REGISTRATION SYSTEM     \n";
        std::cout << "====================================\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "\nExiting the program. Goodbye!\n";
                return 0;
            default:
                std::cout << "\n[ERROR] Invalid choice. Please select 1, 2, or 3.\n";
        }
    }
}
