#ifndef BOXES_H
#define BOXES_H

/*
    This file implements boxes.
    Read <id, ticket> map table from "boxes.cfg"
*/

#include <fstream>
#include <assert.h>

extern int prisoner_count;

class Box {
    private:
        int id;
        int ticket;
    private:
        void set(const int& id, const int& ticket);
    friend class Boxes;
};

class Boxes {
    private:
        Box* boxes;
    public:
        Boxes() {
            this->boxes = (Box*)malloc(sizeof(Box*) * prisoner_count);
            
            // init the boxes
            Box* cur_box = this->boxes;
            std::fstream fs;
            fs.open("boxes.cfg", std::fstream::in);
            while (fs.peek() != EOF) {
                fs >> cur_box->id >> cur_box->ticket;
                cur_box++;
            }
            fs.close();
            // check the number
            assert(cur_box - this->boxes == prisoner_count);
        }
};

#endif