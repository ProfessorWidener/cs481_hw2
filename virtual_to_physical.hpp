#ifndef VIRTUAL_TO_PHYSICAL_HPP
#define VIRTUAL_TO_PHYSICAL_HPP

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <bitset>
#include <iostream>
#include "tlb.hpp"
#include "page_table.hpp"
#include "faults.hpp"


void split_virtual_address(int virtual_address, int page_size, int* VPN, int* offset);
void split_VPN(int VPN, int k, int* index, int* tag);
int TLB_lookup(TLB* tlb, int VPN);
int table_lookup(PageTable* table, TLB* tlb, int VPN);
int get_physical_address(int PFN, int offset, int page_size);
int virtual_to_physical(int virtual_address, int page_size, TLB* tlb, PageTable* table);



#endif
