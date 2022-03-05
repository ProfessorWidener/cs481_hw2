#ifndef TLB_HPP
#define TLB_HPP

class TLB_entry
{
    public:
        TLB_entry()
        {
            tag = 0;
            PFN = 0;
            protect_bit = 0;
            valid_bit = 0;
            idx = 0;
        }

        ~TLB_entry()
        {

        }

        void update_entry(int _tag, int _PFN, int _protect_bit = 0, int _idx = 0)
        {
            tag = _tag;
            PFN = _PFN;
            protect_bit = _protect_bit;
            idx = _idx;
            valid_bit = 1;
        }

        bool can_access()
        {
            return not protect_bit;
        }

        int tag;
        int PFN;
        int protect_bit;
        int valid_bit;
        int idx;
};

class TLB_set
{
    public:
        TLB_set()
        {
            entries = NULL;
            set_size = 0;
            counter = 0;
        }

        ~TLB_set()
        {
            for (int i = 0; i < set_size; i++)
                delete entries[i];
            delete[] entries;
        }

        void create_set(int _set_size)
        {
            set_size = _set_size;
            entries = new TLB_entry*[set_size];
            for (int i = 0; i < set_size; i++)
                entries[i] = new TLB_entry();
        }

        void add_entry(int tag, int PFN, int protect_bit = 0)
        {
            // If available spot in set, add TLB entry
            for (int i = 0; i < set_size; i++)
            {
                if (entries[i]->valid_bit == 0)
                {
                    entries[i]->update_entry(tag, PFN, protect_bit, counter++);
                    return;
                }
            }

            // If no available spots in set, 
            //    1. remove entry with lowest idx
            //    2. add TLB entry to this position
            int min_counter = counter;
            int min_idx = -1;
            for (int i = 0; i < set_size; i++)
            {
                if (entries[i]->idx < min_counter)
                {
                    min_idx = i;
                    min_counter = entries[i]->idx;
                }
            }
            entries[min_idx]->update_entry(tag, PFN, protect_bit, counter++);
        }

        bool lookup(int tag, TLB_entry** entry)
        {
            for (int i = 0; i < set_size; i++)
            {
                if (entries[i]->tag == tag && entries[i]->valid_bit==1)
                {
                    *entry = entries[i];
                    return true;
                }
            }
            return false;
        }

        TLB_entry** entries;
        int set_size;
        int counter;
};

class TLB
{
    public:
        TLB(int _k, int set_size)
        {
            k = _k;
            sets = new TLB_set[k];
            for (int i = 0; i < k; i++)
                sets[i].create_set(set_size);
        }

        ~TLB()
        {
            delete[] sets;

        }

        void add_entry(int idx, int tag, int PFN, int protect_bit = 0)
        {
            sets[idx].add_entry(tag, PFN, protect_bit);
        }
        
        bool lookup(int idx, int tag, TLB_entry** entry)
        {
            return sets[idx].lookup(tag, entry); 
        }

        TLB_set* sets;
        int k;
};


#endif
