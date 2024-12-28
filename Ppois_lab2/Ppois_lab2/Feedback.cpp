#include "Feedback.h"
#include <iostream>

Feedback::Feedback(const std::string& customerName, const std::string& comments)
    : customerName(customerName), comments(comments) {}

void Feedback::displayFeedback() {
    std::cout << "Feedback from " << customerName << ": " << comments << std::endl;
}