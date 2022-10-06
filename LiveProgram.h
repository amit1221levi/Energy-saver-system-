//
// Created by amit levi on 06/10/2022.
//

#ifndef LIVEPROGRAM_H
#define LIVEPROGRAM_H

#include <iostream>
#include "System.h"
namespace live_{
    void main_(System<int> &system);

    //Account functions
    void account_(System<int> system);
    //
    void account_functions(System<int> system);
    void new_request(const System<int>& system);
    void print_account(const System<int>& system);
    void previous_request(const System<int>& system);


    //System functions
    void system_(System<int> system);
    //


    //Energy producer function
    void energy_(System<int> system);
    //

}

using namespace live_;
void live_::main_(System<int> &system){
    int command=0;
    try {
        std::cout << "\nWelcome to Engy terminal!\n"
                     "Please type the following one of the numbers for the following function:\n\n\n"
                     "          System                                1\n"
                     "          Account                               2\n"
                     "          Energy producer                       3\n"
                  << endl;
        if(cin >>command&&(command==1||command==2||command==3)){
            switch (command) {
                case 1:
                    system_(system);
                case 2:
                    account_(system);
                case 3:
                    energy_(system);
            }
        } else throw invalid_argument("invalid number, please try again\n");

    }catch (invalid_argument){
        main_(system);
    }
}








void account_functions(System<int> system) {
    int command = 0;
    try {
        if (Node<struct Consumer>::find(system.accounts, command)) {
            cout <<
                 "Please type the following one of the numbers for the following function:\n\n\n"
                 "          New request                                       1\n"
                 "          Account print all info                            2\n"
                 "          Account find previous specific request            3\n"
                 "          Return to the main screen                         4\n"
                 << endl;
            if (cin >> command && (command == 1 || command == 2 || command == 3)) {
                switch (command) {
                    case 1:
                        system.accounts->find(system.accounts,command)->data.new_request();
                    case 2:
                        system.accounts->find(system.accounts,command)->data.print_account();
                    case 3:
                        system.accounts->find(system.accounts,command)->data.find_request();
                    case 4:
                        main_(system);
                }
            }
        } else throw invalid_argument("invalid number, please try again\n");
    } catch (invalid_argument) {
        ::account_functions(system);
    }
}


void live_::account_(System<int> system) {
    int command;
    try {
        std::cout << "\nplease type id account or 0 for create a new account!\n" << endl;
        cin >> command;
        if(command==0) {
            system.add_consumer();
        } else {
            if (system.accounts->find(system.accounts, command)) {

                ::account_functions(system);
            } else {
                throw invalid_argument("invalid id, please try again\n");
            }
        }
    } catch (invalid_argument) {
        account_(system);
    }
}





void live_::new_request(const System<int>& system) {

}

void live_::previous_request(const System<int>& system) {

}

void live_::print_account(const System<int>& system) {

}





#endif //LIVEPROGRAM_H
