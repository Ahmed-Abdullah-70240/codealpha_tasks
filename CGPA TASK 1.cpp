#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Course {
    std::string name;
    double gradePoint;
    double creditHours;
};

int main() {
    int numCourses;
    std::cout << "=== CGPA Calculator ===\n";
    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;

    std::vector<Course> courses(numCourses);
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; ++i) {
        std::cout << "\nCourse " << i + 1 << " Name: ";
        std::cin.ignore();
        std::getline(std::cin, courses[i].name);

        std::cout << "Enter Grade Point (e.g., 4.0, 3.5, 3.0): ";
        std::cin >> courses[i].gradePoint;

        std::cout << "Enter Credit Hours: ";
        std::cin >> courses[i].creditHours;

        totalCredits += courses[i].creditHours;
        totalGradePoints += (courses[i].gradePoint * courses[i].creditHours);
    }

    std::cout << "\n-----------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Course Name"
              << std::setw(15) << "Grade Point"
              << std::setw(15) << "Credit Hours" << "\n";
    std::cout << "-----------------------------------------\n";

    for (size_t i = 0; i < courses.size(); ++i) {
    std::cout << std::left << std::setw(20) << courses[i].name
              << std::setw(15) << courses[i].gradePoint
              << std::setw(15) << courses[i].creditHours << "\n";
}

    double cgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;

    std::cout << "-----------------------------------------\n";
    std::cout << "Total Credits: " << totalCredits << "\n";
    std::cout << "Total Grade Points: " << totalGradePoints << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Final CGPA: " << cgpa << "\n";

    return 0;
}
