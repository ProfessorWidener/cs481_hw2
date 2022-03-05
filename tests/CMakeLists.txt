include_directories(${hw2_INCDIR})

add_executable(test_vpn test_vpn.cpp)
target_link_libraries(test_vpn hw2 googletest )
add_test(ExtractVPN ./test_vpn)

add_executable(test_offset test_offset.cpp)
target_link_libraries(test_offset hw2 googletest )
add_test(ExtractOffset ./test_offset)





add_executable(test_tlb_index test_tlb_index.cpp)
target_link_libraries(test_tlb_index hw2 googletest )
add_test(ExtractTLBIndex ./test_tlb_index)

add_executable(test_tlb_tag test_tlb_tag.cpp)
target_link_libraries(test_tlb_tag hw2 googletest )
add_test(ExtractTLBTag ./test_tlb_tag)




add_executable(test_tlb_miss test_tlb_miss.cpp)
target_link_libraries(test_tlb_miss hw2 googletest )
add_test(TLBMissLookup ./test_tlb_miss)

add_executable(test_tlb_protection test_tlb_protection.cpp)
target_link_libraries(test_tlb_protection hw2 googletest )
add_test(TLBProtectLookup ./test_tlb_protection)

add_executable(test_tlb_pfn test_tlb_pfn.cpp)
target_link_libraries(test_tlb_pfn hw2 googletest )
add_test(TLBPFNLookup ./test_tlb_pfn)

add_executable(test_tlb test_tlb.cpp)
target_link_libraries(test_tlb hw2 googletest )
add_test(TLBLookup ./test_tlb)


add_executable(test_pfn test_pfn.cpp)
target_link_libraries(test_pfn hw2 googletest )
add_test(PFNtoAddr ./test_pfn)




add_executable(test_table_seg test_table_seg.cpp)
target_link_libraries(test_table_seg hw2 googletest )
add_test(PageTableSegFault ./test_table_seg)

add_executable(test_table_protect test_table_protect.cpp)
target_link_libraries(test_table_protect hw2 googletest )
add_test(PageTableProtectFault ./test_table_protect)

add_executable(test_table_page test_table_page.cpp)
target_link_libraries(test_table_page hw2 googletest )
add_test(PageTablePageFault ./test_table_page)

add_executable(test_table_pfn test_table_pfn.cpp)
target_link_libraries(test_table_pfn hw2 googletest )
add_test(PageTablePFN ./test_table_pfn)

add_executable(test_table_to_tlb test_table_to_tlb.cpp)
target_link_libraries(test_table_to_tlb hw2 googletest )
add_test(PageTableToTLB ./test_table_to_tlb)

add_executable(test_table test_table.cpp)
target_link_libraries(test_table hw2 googletest )
add_test(PageTableLookup ./test_table)





add_executable(test_addr test_addr.cpp)
target_link_libraries(test_addr hw2 googletest )
add_test(TestPhysicalAddress ./test_addr)





add_executable(test_virtual_to_physical1 test_virtual_to_physical1.cpp)
target_link_libraries(test_virtual_to_physical1 hw2 googletest )
add_test(TestVirtualToPhysical1 ./test_virtual_to_physical1)

add_executable(test_virtual_to_physical2 test_virtual_to_physical2.cpp)
target_link_libraries(test_virtual_to_physical2 hw2 googletest )
add_test(TestVirtualToPhysical2 ./test_virtual_to_physical2)

add_executable(test_virtual_to_physical3 test_virtual_to_physical3.cpp)
target_link_libraries(test_virtual_to_physical3 hw2 googletest )
add_test(TestVirtualToPhysical3 ./test_virtual_to_physical3)

add_executable(test_virtual_to_physical4 test_virtual_to_physical4.cpp)
target_link_libraries(test_virtual_to_physical4 hw2 googletest )
add_test(TestVirtualToPhysical4 ./test_virtual_to_physical4)

add_executable(test_virtual_to_physical5 test_virtual_to_physical5.cpp)
target_link_libraries(test_virtual_to_physical5 hw2 googletest )
add_test(TestVirtualToPhysical5 ./test_virtual_to_physical5)






add_executable(test_fifo test_fifo.cpp)
target_link_libraries(test_fifo hw2 googletest)
add_test(FIFOTest ./test_fifo)

add_executable(test_fifo_steps test_fifo_steps.cpp)
target_link_libraries(test_fifo_steps hw2 googletest)
add_test(FIFOStepsTest ./test_fifo_steps)

add_executable(test_lru test_lru.cpp)
target_link_libraries(test_lru hw2 googletest)
add_test(LRUTest ./test_lru)

add_executable(test_lru_steps test_lru_steps.cpp)
target_link_libraries(test_lru_steps hw2 googletest)
add_test(LRUStepsTest ./test_lru_steps)

add_executable(test_clock_lru test_clock_lru.cpp)
target_link_libraries(test_clock_lru hw2 googletest)
add_test(ClockLRUTest ./test_clock_lru)

add_executable(test_clock_lru_steps test_clock_lru_steps.cpp)
target_link_libraries(test_clock_lru_steps hw2 googletest)
add_test(ClockLRUStepsTest ./test_clock_lru_steps)

