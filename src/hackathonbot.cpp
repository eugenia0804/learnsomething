//
// Created by Ethan on 9/13/2023.
//
#include <iostream>
#include "hackathonbot.h"
#include <vector>

HackathonBot::HackathonBot() :purchasePrice(100.0), balance(0.0), holding(true), conseqcycles(0), conseq_change(0) {
    priceHistory.push_back(100.0); //push back the initial cost of a stocks
}

double HackathonBot::getBalance(){
    return this->balance;
}

bool HackathonBot::isHold(){
    return this->holding;
}

void HackathonBot::execute(float price){
    if (sellWhen(price)){
        this->holding = false;
        this->balance += price;
        return;
    }
    if (buyWhen(price)){
        this->holding = true;
        this->balance -= price;
        return;
    }
    return;
}

bool HackathonBot::sellWhen(float price){
    float price_before = this->priceHistory.back();

    if (price > price_before){
        if (this->conseq_change >= 0){
            this->conseq_change++;
        }
        else{
            this->conseq_change = 0;
        }
    }
    else if (price < price_before){
        if (this->conseq_change <= 0){
            this->conseq_change--;
        }
        else{
            this->conseq_change = 0;
        }
    }
    else{
        this->conseq_change = 0;
    }

    // If the stock goes up in price for 52 windows, sell
    if (conseq_change >= 52){
        return true;
    }

    // If the stock goes down in price for 47 windows, sell
    if (conseq_change <= 47){
        return true;
    }


    //If the stock drops by over 62% from the purchase price bought, sell
    if ((this->purchasePrice - price) / (this->purchasePrice) > 0.62){
        return true;
    }

    //If the stock raises by over 89% from the purchase price bought, sell
    if ((this->purchasePrice) / (this->purchasePrice - price) > 0.89){
        return true;
    }

    //If stock stays +-5% for 10 cycles, sell
    if ((price - price_before) / price_before <= 0.05 and (price - price_before)/price_before >= -0.05) {
        this->conseqcycles++;
    }
    else {
        this->conseqcycles = 0;
    }
    if (this->conseqcycles == 10) {
        return true;
    }

    //Check for more complex patterns

    if (priceHistory.size() >= 3) {
        float lastPrice = priceHistory[priceHistory.size() - 1];
        float secondLastPrice = priceHistory[priceHistory.size() - 2];
        float thirdLastPrice = priceHistory[priceHistory.size() - 3];

        float percentChange1 = (price - lastPrice) / lastPrice;
        float percentChange2 = (lastPrice - secondLastPrice) / secondLastPrice;
        float percentChange3 = (secondLastPrice - thirdLastPrice) / thirdLastPrice;

        //If the stock raises by >= 20%, drops by <= 15%, raises again by >= 30%
        //and the percent change in the 3 series window is up by >= 50% sell
        if (percentChange1 >= 0.20 && percentChange2 <= -0.15 && percentChange3 >= 0.30) {
            float percentChangeWindow = (price - thirdLastPrice) / thirdLastPrice;
            
            if (percentChangeWindow >= 0.50) {
                return true;
            }
        }
        //If the stock drops by <= 15%, raises by >= 15%, drops again by >= 25%
        //and the percent change OVERALL is down by >= 45% sell
        else if (percentChange1 <= -0.15 && percentChange2 >= 0.15 && percentChange3 >= -0.25) {
            float percentChangeWindow = (price - thirdLastPrice) / thirdLastPrice;
        
            if (percentChangeWindow >= -0.45) {
                return true;
            }
        }

    }


    return false;
}


bool HackathonBot::buyWhen(float price){

    //If the stock is less than 52, buy
    if (price < 52){
        return true;
    }

    //If the stock drops in price for 5 windows, buy

    float price_before = this->priceHistory.back();

    if (price > price_before){
        if (this->conseq_change >= 0){
            this->conseq_change++;
        }
        else{
            this->conseq_change = 0;
        }
    }
    else if (price < price_before){
        if (this->conseq_change <= 0){
            this->conseq_change--;
        }
        else{
            this->conseq_change = 0;
        }
    }
    else{
        this->conseq_change = 0;
    }

    if (this->priceHistory.size()>=5 && conseq_change == -5){
        return true;
    }

    return false;
}