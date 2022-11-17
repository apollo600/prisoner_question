#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cassert>

#include "Prison.h"

extern Prison* Prison::instance;
extern int prisoner_count;

int Prisoner::update() {
    if (ticket == id) {
        this->solved = true;
        return 1;
    } else {
        this->solved = false;
        return 0;
    }
}

Prison::Prison() {
    this->prisoners = (Prisoner*)malloc(sizeof(Prisoner) * prisoner_count);
    for (int i = 0; i < prisoner_count; i++) {
        prisoners[i] = Prisoner();
    }

    this->boxes = new Boxes();
}

Prison::~Prison() {
    free(prisoners);
    free(instance);
}

int Prison::prisoner_fetch(int p_id, int b_id) {
    assert(p_id < prisoner_count);
    assert(b_id < prisoner_count);
    // get ticket from box
    int ticket = boxes->get_ticket(b_id);
    // update prisoner
    if (update_prisoner(p_id, ticket)) {
        update(p_id);
    }
    
    return ticket;
}

int Prison::update_prisoner(const int& id, const int& ticket) {
    prisoners[id].ticket = ticket;
    return prisoners[id].update();
}

int Prison::update(const int& p_id) {
    for (int i = 0; i < prisoner_count; i++) {
        if (prisoners[i].solved != true) {
            return false;
        }
    }

    all_prisoner_solved = true;
    return true;
}

int Prison::get_state(const int& p_id) {
    assert(p_id < prisoner_count);
    return prisoners[p_id].solved;
}