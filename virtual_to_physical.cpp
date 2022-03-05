#include "virtual_to_physical.hpp"

void
split_virtual_address(int virtual_address, int page_size, int* VPN, int* offset)
{
  return;
}

void
split_VPN(int VPN, int k, int* index, int* tag)
{
  return ;
}

int
TLB_lookup(TLB* tlb, int VPN)
{
  return -1;
}


int
table_lookup(PageTable* table, TLB* tlb, int VPN)
{
  return -1;
}

int
get_physical_address(int PFN, int offset, int page_size)
{
  return -1;
}


int
virtual_to_physical(int virtual_address, int page_size, TLB* tlb, PageTable* table)
{
  return -1;
}

