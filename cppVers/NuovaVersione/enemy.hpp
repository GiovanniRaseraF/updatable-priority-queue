#pragma once
#include <random>
#include <string>
#include "updatable_priority_queue.hpp"

class enemy{
    private:
    string name;
    int pos_in_queue;
    int pos_x, pos_y;
    int priority = 0;
    updatable_priority_queue my_queue;
    
    public:
    enemy(string name){
        this->name = name;
        this->my_queue{};
        this->pos_x = 0;
        this->pos_y = 0;
    }

    int update_pos(updatable_priority_queue& caller, int new_pos){
        this->pos_in_queue = new_pos;
    }

    void update_priority(){
        this->priority = rand() % 10;
    }

    string to_string(){
        return this->name;
    }    
};

