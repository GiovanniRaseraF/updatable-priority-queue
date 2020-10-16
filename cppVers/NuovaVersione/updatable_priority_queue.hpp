#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <mutex>
#include <assert.h>
using namespace std;
class updatable_priority_queue;
class enemy;

class updatable_priority_queue{
    private:    
    vector<enemy> heap;
	std::mutex stop;

    public:
    updatable_priority_queue();

    int update(enemy& to_update);

    void to_print();
};

updatable_priority_queue::updatable_priority_queue() : heap{}{}

int updatable_priority_queue::update(enemy& to_update){
    this->heap.push_back(to_update);
    to_update.update_pos(this, this->heap.size()-1);
    return 0;
}

void updatable_priority_queue::to_print(){
    cout<<"QueueP:\n";
    for(auto i : heap) {
        cout<<i.to_string()<<endl;
    }
}

class enemy{
    public:
    string name;
    int pos_in_queue;
    int pos_x, pos_y;
    int priority = 0;
    updatable_priority_queue my_queue;

    enemy(string name);
    int update_pos(updatable_priority_queue* caller, int new_pos);
    void update_priority();
    string to_string();    
};


enemy::enemy(string name): my_queue{}{
        this->name = name;
        this->pos_x = 0;
        this->pos_y = 0;
}

int enemy::update_pos(updatable_priority_queue* caller, int new_pos){
        this->pos_in_queue = new_pos;
}

void enemy::update_priority(){
        this->priority = rand() % 10;
}

string enemy::to_string(){
        return this->name;
}    
