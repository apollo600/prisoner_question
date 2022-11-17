/*
    This file implements a prisoner model to solve.
    Offer limited interfaces to force users obey the rule.
*/

#ifndef PRISON_H
#define PRISON_H

#include "Boxes.h"

static int cur_malloc_id  = 1;
extern int prisoner_count;

class Prisoner {
    /* variables */
    private:
        int id;
        int ticket;
        int keys;
        bool solved;
    
    /* functions */
    private:
        Prisoner() : id(cur_malloc_id), ticket(0), keys(0), solved(false) {
            cur_malloc_id++;
        }
        
        /* update the state of prisoner */
        int update();        

    friend class Prison;
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
        Prison();

        ~Prison();

        /* update the state of prisoner */
        int update_prisoner(const int& id, const int& ticket);

        /*
            update the prison's state if a prisoner's state changed
        */
        int update(const int& p_id);

    public: 
        /* single instance mode */
        static Prison* getInstance() {
            // cannot use "this->" here
            if (instance == nullptr) {
                instance = new Prison();
            }
            return instance;
        }

        /* 
            use prisoner p_id fetch box b_id,
            return box->ticket.
        */
        int prisoner_fetch(int p_id, int b_id);

        int get_state(const int& p_id);
};

#endif