# Resources
https://github.com/nodakai/tree-command 
http://web.eecs.utk.edu/~plank/plank/classes/cs360/360/notes/Stat/lecture.html //opendir readdir closedir
https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html // struct dirent
https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program // read current path getcwd()
https://stackoverflow.com/questions/4553012/checking-if-a-file-is-a-directory-or-just-a-file // check if a file is directory
 
Discussion with Yuan Ning.

# Overview
Like classwork 7, this is a complete program.  You will need to write your own Makefile, and test it with a shell script.  A good way to do testing would be for your shell script to actually create the directory structure using `mkdir` and `touch` (which creates an empty file), and then to run your program.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem
Write an implementation of the Linux utility `tree`, which prints out the subdirectory structure of the directory specified on the command line.  If no directory is specified, use the current working directory.

You should indent each successive directory level by 4 spaces.
You do not need to print the pretty lines or color labels (although these are nice features of `tree`).

Some functions that will be helpful (use `man` to read about them):
* `opendir`
* `readdir`
* `closedir` (It's important to clean up after yourself, even if your code works without doing so.)
* `snprintf`

Your Makefile should produce a binary called `mytree`.

This is a common problem, and there are implementations online if you search for them.  Remember that 1) all code you write must be your own, and 2) you need to document any sources you used to develop your solution.

