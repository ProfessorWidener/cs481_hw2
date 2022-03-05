#ifndef REPLACEMENT_HPP
#define REPLACEMENT_HPP

#include "frame_list.hpp"

int fifo(FrameList* active_frames, FrameList** frame_to_remove_ptr);
int lru(FrameList* active_frames, FrameList** frame_to_remove_ptr);
int clock_lru(FrameList* active_frames, FrameList** frame_to_remove_ptr);

#endif
