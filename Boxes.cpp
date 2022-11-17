#include <fstream>
#include <cassert>
#include <cstdlib>

#include "Boxes.h"

Boxes::Boxes() {
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

int Boxes::get_ticket(const int& b_id) {
    return boxes[b_id].ticket;
}