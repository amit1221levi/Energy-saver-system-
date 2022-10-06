
//
// Created by amit levi on 04/10/2022.
//


#ifndef ENERGYPRODUCER_H
#define ENERGYPRODUCER_H

#include <vector>
#include "Request.h"
class Producer{
protected:
    int id;
    std::vector<std::unique_ptr<Request>> History_Consumption;
public:
    Producer(int id);
    //Add a new consumption request from the current consumption
    int get_id();
    void new_request(Request request,Type type=producer);
};

Producer::Producer(int
                   id):id(id)
{}


int
Producer::get_id()
{
    return id;
}


#endif//ENERGYPRODUCER_H



