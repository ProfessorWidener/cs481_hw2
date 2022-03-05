#ifndef PAGETABLE_HPP
#define PAGETABLE_HPP

class PTE
{
    public:
        PTE()
        {
            PFN = 0;
            protect_bit = 0;
            valid_bit = 1;
            present_bit = 0;
        }

        ~PTE()
        {

        }

        void update_entry(int _PFN, int _protect_bit = 0, int _valid_bit = 1)
        {
            PFN = _PFN;
            protect_bit = _protect_bit;
            valid_bit = _valid_bit;
            present_bit = 1;
        }

        bool can_access()
        {
            return not protect_bit;
        }

        int PFN;
        int protect_bit;
        int valid_bit;
        int present_bit;
};


class PageTable
{
    public:
        PageTable(int _num_pages)
        {
            num_pages = _num_pages;
            entries = new PTE*[num_pages];
            for (int i = 0; i < num_pages; i++)
                entries[i] = new PTE();
        }

        ~PageTable()
        {
            for (int i = 0; i < num_pages; i++)
                delete entries[i];
            delete[] entries;
        }

        void add_page(int VPN, int PFN, int protect_bit = 0, int valid_bit = 1)
        {
            entries[VPN]->update_entry(PFN, protect_bit, valid_bit);
        }

        PTE* lookup(int VPN)
        {
            return entries[VPN];
        }


        PTE** entries;
        int num_pages;
};

#endif
