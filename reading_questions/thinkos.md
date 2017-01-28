## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

- Interpreted languages support dynamic types (think Python without setting variable types), however compiled languages usually require static types (Java with setting variables like int x).

2) Name two advantages of static typing over dynamic typing.

- Static typing is great for a programmer because they know exactly what the variables are, which makes it more convenient to write code. As well, the types are set and can be checked for errors before compile time, which just speeds up the program. As well, these static values take less space.

3) Give an example of a static semantic error.

- int x = "wrong"; x is declared as an int, but the variable is assigned to a String, which is wrong.

4) What are two reasons you might want to turn off code optimization?

- Optimizations may take more compilation time, subbing operations with simpler ones or even changing code structure for higher efficiency. This means runtime is faster, but if there is a random bug because you rely on one function and another one is subbed in, that makes it difficult for debugging. Also, longer compile time can be bad, especially if you are compiling often to test things.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

- All computer hardware is different. Machine code for an AMD machine vs. an Intel machine are two very different things.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

- If you spell a function name wrong it breaks the linking process, showing a longer error message with an exit status, while if you spell a variable wrong it will have a syntax error that just shows the expected result.

7) What is a segmentation fault?

- Reading/writing to an incorrect memory location.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

- When I deposit cash into my bank account, there is no location where my account is sitting with all its cash, because that would be stupid and banks wouldn't be able to do anything with it. Instead, I deposit an amount, which is then stored and the value is added to my account. That means I can go to a different bank and take out an amount of cash, which isn't actually my original cash.

2) What is the difference between a program and a process?

- A process contains: text of the program, data associated with the program, state of i/o for the program, and the hardware state of the program. The program itself can launch one or many processes. This then enables multitasking and such.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

- To avoid race conditions and breaking hardware. Hardware requires some level of coordination, such that multiple browsers don't try to send and read data off the network card at the same time, resulting in you searching for something and receiving the search request in another browser.

4) What is the kernel?

- Responsible for core capabilities like threads.

5) What is a daemon?

- Responsible for providing operating system services.


## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

- Well 5 bits is one off (32), which is inconvenient. So let's throw more data at it and give it 6 bits (64). What a terrible waste of space.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

- Let's assume each character takes up 32 bits. That means to represent the 26 letters of the alphabet, we would need 832 bits, which is only 104 bytes which is tiny.

3) What is the difference between "memory" and "storage" as defined in Think OS?

- Memory is volatile storage (RAM), storage is non-volatile storage (HDD and SSDs).

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

- GiB is binary units, GB is decimal units. 1073741824 bits vs 1000000000 bits. A difference of 73741824 bits.

5) How does the virtual memory system help isolate processes from each other?

- When the OS converts virtual memory that the process uses to the actual physical location of the data, it does so on a per process basis. This means no two processes, even with the same virtual memory address, could hit the same physical address and break things.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

- Stack and heap both need to grow to accept new addresses. So having the stack and heap next to each other wouldn't make much sense because if the stack grew, it would eventually hit the heap start and have to account for that, poorly. So put the two growers at different ends and hope they don't hit each other as they get bigger.

7) What Python data structure would you use to represent a sparse array?

- A dictionary?

8) What is a context switch?

- Saving a process, stopping it, and running another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

Mine: main is 0x102270e90, global is 0x102271020, local is 0x7fff5d98f528, p is 0x7fd928c027c0.

Yours: main is 0x40057c, global is 0x60104c, local is  0x7fffd26139c4, p is 0x1c3b010.

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).

- Address of p is 0x7ff72cc027c0, p is now 0x7ff72cc02840. YUP.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.

- Yep, grows down from 0x7fff52535528 to 0x7fff525354ec.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

- i 0x7ff502c028c0, j 0x7ff502c028d0 which is a difference of 0x10.


## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically true about files systems but not true of their implementations.

- Hierarchical storage of string based file names so you can reference items easily, and find them easily. "Files are byte-based and persistent storage is block-based."

2) What information do you imagine is stored in an `OpenFileTableEntry`?

- Shows that a file is open for writing.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

- They make it seem that there is no logical difference in speed. You can: transfer larger amounts because they use about the same amount of time, prefetch files that might be needed in the future, buffer by writing the file from memory to the hard drive while the process continues.

4) Suppose your program writes a file and prints a message indicating that it is done writing. Then a power cut crashes your computer. After you restore power and reboot the computer, you find that the file you wrote is not there. What happened?

- The file was in a buffer to write it, however it was kept in memory still and not written to the hard drive yet.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode? Or an advantage of a inode over a FAT?

- FAT is more folder organized it seems while inode is more concerning with extra files to organize.

6) What is overhead? What is fragmentation?

- How much of an extra you might need, in this case probably space overhead in that you don't want to take up space that you could be storing files in. Fragmentation is where unused blocks are left open. This also spawned the idea of disk defrag, which reorganizes hard drives for higher efficiency. SSDs don't need this because of how their file system is defined and organized.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

- Smart, because networking and many other computing ideas can be organized in that mindset. Helps with making sure you do not corrupt in-use files or processes.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?



## Chapter 11


### Semaphores in C
