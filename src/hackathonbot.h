//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include <utility>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:

    HackathonBot();
    double getBalance();
    bool isHold();
    void execute(float price);

private:
    double purchasePrice;
    double balance;
    bool holding;
    int conseqcycles;
    int conseq_change;

    std::vector<float> priceHistory;
    bool sellWhen(float price);
    bool buyWhen(float price);

};

#endif //LEARNSOMETHING_HACKATHONBOT_H
