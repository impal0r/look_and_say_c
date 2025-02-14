**Iteratively compute the terms of the Look and Say Sequence**

Written in portable C using minimal library functions (malloc, free, printf, and getchar)

### How to use
- clone the repository or simply download the self-contained `look_and_say.c` file
- compile the code to an executable binary on your local system    
  eg. `gcc look_and_say.c -o look_and_say -O3` on a linux system
- run the resulting binary on the command line
- the program will wait for you to press "Enter" and then calculate and print the next term

### The Look and Say Sequence

This is a fun mathematical sequence where you can get the next term by saying the previous
term out loud. For example, the term after

    1211

is

    111221

because 1211 is "one one, one two, and two ones".

### Implementation details
- optimised for speed
- uses 1 byte of heap memory per digit, but heuristically over-allocates to avoid frequent capacity checks
- fails gracefully if malloc fails
- alternates between two buffers to compute even and odd terms in the sequence
- the buffers are like a simple implementation of vector<char>, but capacity is only checked once each time the next term is computed

### Possible improvements
- reduce memory consumption for long numbers later in the sequence

### Further reading and references:
- The Look and Say Sequence on Wikipedia https://en.wikipedia.org/wiki/Look-and-say_sequence
- The OEIS entry for the sequence https://oeis.org/A005150
- This Numberphile video, where I first learnt about the sequence https://www.youtube.com/watch?v=ea7lJkEhytA

If this is your first time using a C compiler (Linux)
- `gcc` is the easiest compiler to get started with. It works from the command line
- There are many tutorials online, but here's a good one for beginners https://riptutorial.com/gcc
- Here's a good linux command line cheat sheet: https://linuxstans.com/bash-cheat-sheet/
1. Navigate to the folder containing `look_and_say.c`
2. To make `gcc` compile your code, all you need to do is type the single command
   `gcc look_and_say.c -o look_and_say`
3. Now type `./look_and_say` to run the resulting binary
4. If you get a permission error, you need to set execute permissions on the binary file using the `chmod` command

If this is your first time using a C compiler (Windows)
- There are many compilers for Windows, I'm afraid I don't have any recommendations for beginners
- The option I went with is to set up a development environment using Windows Subsystem for Linux. Microsoft have a pretty good tutorial on their website: https://learn.microsoft.com/en-us/windows/wsl/setup/environment