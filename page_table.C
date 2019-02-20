#include "assert.H"
#include "exceptions.H"
#include "console.H"
#include "paging_low.H"
#include "page_table.H"

PageTable * PageTable::current_page_table = NULL;
unsigned int PageTable::paging_enabled = 0;
ContFramePool * PageTable::kernel_mem_pool = NULL;
ContFramePool * PageTable::process_mem_pool = NULL;
unsigned long PageTable::shared_size = 0;



void PageTable::init_paging(ContFramePool * _kernel_mem_pool,
                            ContFramePool * _process_mem_pool,
                            const unsigned long _shared_size)
{
   //assert(false);
   kernel_mem_pool = _kernel_mem_pool;
   process_mem_pool = _process_mem_pool;
   shared_size = _shared_size;
   Console:R:puts("Initialized Paging System\n");
}

PageTable::PageTable()
{
   //assert(false);
   Console::puts("Constructed Page Table object\n");
   *page_directory = (unsigned long *) 0x9C000;
   unsigned long *page_table = (unsigned long *) 0x9D000; // the page table comes right after the page directory
   unsigned long address=0; // holds the physical address of where a page is
   unsigned int i;
   // map the first 4MB of memory
   for(i=0; i<1024; i++)
   {
     page_table[i] = address | 3; // attribute set to: supervisor level, read/write, present(011 in binary)
     address = address + 4096; // 4096 = 4kb
   };
  // fill the first entry of the page directory
  page_directory[0] = page_table; // attribute set to: supervisor level, read/write, present(011 in binary)
  page_directory[0] = page_directory[0] | 3;
  for(i=1; i<1024; i++)
  {
    page_directory[i] = 0 | 2; // attribute set to: supervisor level, read/write, not present(010 in binary)
  };
  /*
  // write_cr3, read_cr3, write_cr0, and read_cr0 all come from the assembly functions
     write_cr3(page_directory); // put that page directory address into CR3
     write_cr0(read_cr0() | 0x80000000); // set the paging bit in CR0 to 1

  // go celebrate or something 'cause PAGING IS ENABLED!!!!!!!!!!
  */
}


void PageTable::load()
{
   assert(false);
   Console::puts("Loaded page table\n");
}

void PageTable::enable_paging()
{
   assert(false);
   Console::puts("Enabled paging\n");
}

void PageTable::handle_fault(REGS * _r)
{
  assert(false);
  Console::puts("handled page fault\n");
}

