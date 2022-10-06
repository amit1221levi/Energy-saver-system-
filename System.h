
//
// Created by amit levi on 04/10/2022.
//


#ifndef SYSTEM_H
#define SYSTEM_H



/**
 * *Clients interface
 */
#include "Consumer.h"

/**
 * Energy producer , solar, wind etc
**/
#include "EnergyProducer.h"

/**
 * Adapter format from generic data structures for open options like changing the searching algorithms
 * or the data structures#include "DataStructure.h"
**/
#include "BinaryTree.h"


/**
 * download a defined period for analyze, graphing etc, pulling out data with from structure of
 * requests pointers for searching faster according date (complexity years*12*30*24*60) for start point
 * then minutesLen for download the rest
**/
#include "PeriodData.h"
#include <list>
#include <vector>
#include <iostream>
#include <map>
//Request type is or consumer or producer


template<class RequestType>
class System{
protected:
    //Stuck of the future consumption
    // std::vector<std::unique_ptr<Request>> future_requests;
    //Data structure of requests pointers for searching faster according date (complexity years*12*30*24*60)
    //std::map<int,std::unique_ptr<Request>> requestsHistory;
    //Data structure of consumers pointers for searching faster according id (complexity 8*10)
    std::map<int,Producer*> energySources;
    // jed_utils::datetime clock;
     int number_of_consumer;
public:
    Node<struct Consumer> *accounts;
    //Period of consumptions and producer forcast
    System();
    //PeriodData get_forecast_of_energy_producer(jed_utils::datetime start,jed_utils::datetime end);
    //void optimize(PeriodData forecast_of_energy_producer);

    Consumer* find_consumer(int id);
    void add_consumer();

    Producer* find_producer(int id);
    void add_producer(const Producer &new_producer);

};




template<class T>
System<T>::System():number_of_consumer(0) {
    this->accounts=nullptr;
}



template<class T>
void System<T>::add_consumer() {
    Node<Consumer> node((Consumer(number_of_consumer)));
    accounts = Node<Consumer>::insertNode(accounts,&node);
    std::cout << "New account created!\n" << endl;
    node.data.print_account();
    number_of_consumer++;

}

template<class T>
Consumer *System<T>::find_consumer(int id) {
    accounts->find(this->accounts,id);
}




template<class T>
Producer* System<T>::find_producer(int id) {
    if(energySources[id]){
        return energySources[id];
    } else{
        std::cout<<"Producer not exists\n";
        return nullptr;
    }
}

template<class T>
void System<T>::add_producer(const Producer& new_producer)  {
    if (find_producer(this->new_producer.get_id())) {
        std::cout << "The client already exists\n" << std::endl;
        return;
    }
    energySources[this->new_producer.get_id()]=new_producer;
}

#endif//SYSTEM_H