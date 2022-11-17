#ifndef BOXES_H
#define BOXES_H

/*
    This file implements boxes.
    Read <id, ticket> map table from "boxes.cfg"
*/

static int prisoner_count = 5;

class Box {
    /* variables */
    private:
        int id;
        int ticket;
    
    friend class Boxes;
};

class Boxes {
    /* variables */
    private:
        Box* boxes;

    /* functions */
    private:
        Boxes();

        ~Boxes();
        
        /* interface to get box's ticket */
        int get_ticket(const int& b_id);
    
    friend class Prison;
};

#endif