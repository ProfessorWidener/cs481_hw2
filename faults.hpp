#ifndef FAULTS_HPP
#define FAULTS_HPP

#include <stdio.h>
#include <stdlib.h>

void protection_fault();
void segmentation_fault();
void page_fault();
void tlb_miss();

#endif
