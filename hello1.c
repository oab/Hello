// quick syscall overview at
// https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md

// calling convention 
// x86-64  rdi   rsi   rdx   r10   r8    r9 
// syscall "clobbers" rcx r11

static const int STDOUT = 1;
static const int SYS_write = 1;
static const int SYS_exit  = 60;

static inline int __write(unsigned int fp, void* ptr, unsigned size) {
  int ret;
  asm volatile(
    "movq %[write], %%rax \n"           
    "syscall"
    : "+a" (ret)
    : "D" (fp), "S" (ptr), "d" (size), [write] "i" (SYS_write));
  return ret;
}

static inline void __exit(int errcode) {
    asm volatile (
      "syscall"
      : 
      : "a" (SYS_exit), "D" (errcode)
      : "rcx", "r11"
      );
    
}

void _start() 
{
     __write(STDOUT,"Hello, World!\n",sizeof("Hello, World!\n")-1);
    __exit(0);

}
