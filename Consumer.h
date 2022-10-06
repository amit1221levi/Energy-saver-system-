
//
// Created by amit levi on 04/10/2022.
//

#ifndef CONSUMER_H
#define CONSUMER_H


#include <vector>
#include "Request.h"


class Consumer{
protected:
    int id;
    vector<Request> requests;

public:
    explicit Consumer(int id);
    //Add a new consumption request from the current consumption
    [[nodiscard]] int get_id() const;
    void print_account();
    void new_request();
    void find_request();
};



Consumer::Consumer(int id):id(id){}

void Consumer::print_account() {
    cout<<"Id: "<<id<<"\n"<<endl;
    for(Request request:requests){
        request.print_request();
    }

}
int Consumer::get_id() const {
    return id;
}



#endif //CONSUMER_H
