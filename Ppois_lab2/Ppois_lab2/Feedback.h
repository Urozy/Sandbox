#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>

class Feedback {
public:
    std::string customerName;
    std::string comments;

    Feedback(const std::string& customerName, const std::string& comments);
    void displayFeedback();
};

#endif
