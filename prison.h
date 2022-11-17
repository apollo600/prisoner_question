/*
    This file implements a prisoner model to solve.
    Offer limited interfaces to force others obey the rule.
*/

#ifndef PRISON_H
#define PRISON_H

#include <stdlib.h>
#include <fstream>
#include <assert.h>

#include "boxes.h"


static int cur_malloc_id  = 1;
static int prisoner_count = 5;

class Prisoner {
    private:
        int id;
        int ticket;
        bool solved;
    private:
        
    public:
        // interface1: create a new prisoner
        Prisoner() : id(cur_malloc_id), ticket(0), solved(false) {
                cur_malloc_id++;
        }
        // Interface2: update the prisoner's state
        void update() {
            if (ticket == id) {
                this->solved = true;
            } else {
                this->solved = false;
            }
        }
        // Interface3: change the ticket
        void set_ticket(const int& ticket) {
            this->ticket = ticket;
        }
};

class Prison {
    /* variables */
    private:
        static Prison* instance;
        Prisoner* prisoners;
        Boxes* boxes;
        bool all_prisoner_solved = false;
    public:

    /* funtions */
    private: 
        Prison() {
            this->prisoners = (Prisoner*)malloc(sizeof(Prisoner) * prisoner_count);
            for (int i = 0; i < prisoner_count; i++) {
                prisoners[i] = Prisoner();
            }

            this->boxes = new Boxes();
        }

        ~Prison() {
            free(this->prisoners);
            free(this->instance);
        }
        

    public: 
        // cannot use "this->" here
        static Prison* getInstance() {
            if (instance == nullptr) {
                instance = new Prison();
            }
            return instance;
        }

    
};

#endif