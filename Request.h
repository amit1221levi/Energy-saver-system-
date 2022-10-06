
//
// Created by amit levi on 04/10/2022.
//

#ifndef REQUEST_H
#define REQUEST_H

#include <utility>

#include "datetime.h"
enum Type{consumer,producer};

class Request{
protected:
    Type type;
    int energy;
    //Start time of period supply energy rate
    jed_utils::datetime start;
    //End time of period supply energy rate
    jed_utils::datetime end;
    //The rate of the consumption time
    jed_utils::period rate;
    int id;
    int owner_id;
public:
    //Creation of new request included a default start time for now
    Request(int id,int energy,jed_utils::period rate,jed_utils::datetime end,jed_utils::datetime start,Type type);
    void print_request();
};

Request::Request(int id,int energy,jed_utils::period rate,jed_utils::datetime start,jed_utils::datetime end,Type type):
        start(std::move(start)),end(std::move(end)),id(id),rate(rate),energy(energy){}

void Request::print_request() {
    cout<<"Request info:\n"
    <<"Start time of period supply energy rate: "<<start<<"\n"
    <<"End time of period supply energy rate "<<end<<"\n"
    <<"Request id: "<<id<<"\n"
    <<"Owner id: "<<owner_id<<"\n"<<endl;
}

#endif//REQUEST_H
