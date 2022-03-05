#ifndef FRAMELIST_HPP
#define FRAMELIST_HPP

#include <stdio.h>
#include <stdlib.h>

class FrameList
{
    public:
        FrameList(int _idx)
        {
            next = NULL;
            clock_bit = 1;
            idx = _idx;
        }

        ~FrameList()
        {

        }


        void access(int _idx)
        {
            clock_bit = 1;
            idx = _idx;
        }

        FrameList* next;
        int idx;
        int clock_bit;
};

#endif
