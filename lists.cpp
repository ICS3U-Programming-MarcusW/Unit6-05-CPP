// Copyright (c) 2022 Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Created on: December 18 2022
// This program gets marks from the user and
// then calculates and displays the averages of the all
// the marks the user entered

#include <iostream>
#include <list>

// This function returns the average of the marks
float Calc_Average(std::list<float> listOfMarks) {
    // Initializes the sum and average variables
    float sum, average;

    // Iterates through the list
    for (float index : listOfMarks) {
        // Adds each mark to the sum for division
        sum += index;
    }
    // Formula to calculate  average
    average = sum / listOfMarks.size();

    // Returns the average
    return average;
}

// Function to get the users marks and display the average of all the marks
int main() {
    // Declare list
    std::list<float> userMarks;

    // Declare string and float Variables
    std::string userMarkString;
    float userMark, marksAverage;

    // Explain the programs purpose
    std::cout << "This program calculates the average of the marks entered."
    << std::endl;

    // Try catch to catch erroneous input
    try {
        // Keep asking the user for marks until they input -1
        while (userMark != -1) {
            // Get a mark from the user as a float
            std::cout << "Enter a mark (input -1 to stop): ";
            std::getline(std::cin, userMarkString);

            // Casts the users mark to a float
            userMark = stof(userMarkString);

            // Make sure the user did not enter -1, if they did, leave the loop
            if (userMark == -1) {
                break;
                // Make sure the user did not entered a mark outside the range
            } else if (userMark < -1 || userMark > 100) {
                std::cout << "Invalid mark!" << std::endl;
                // Add the mark to the list of marks
            } else {
                userMarks.push_back(userMark);
            }
        }

        // If the list is empty - user did not enter any marks
        // tell them
        if (userMarks.size() == 0) {
            std::cout << "You did not enter any marks!"
            << std::endl;
        } else {
            // Calls the function to calculate the average of all marks
            marksAverage = Calc_Average(userMarks);

            // Displays the list of marks
            std::cout << "\nHere are all the marks: ";
            // Iterates through the list of marks to display them
            for (float mark : userMarks) {
                std::cout << mark << " ";
            }

            // Displays the average of all the marks
            std::cout << "\nThe average is: " << marksAverage << "%"
                      << std::endl;
        }
        // Exception statement if erroneous data is encountered
    } catch (std::invalid_argument) {
        std::cout << "You must enter a valid mark!" << std::endl;
    }
}
