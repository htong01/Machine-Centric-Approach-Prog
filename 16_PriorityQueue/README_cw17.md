# Resources
Discussion with Fan and Yuan.

https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/

# Overview
Many applications which use priority queues have separate threads for reading and writing, and it's important that the priority queue doesn't get corrupted if two threads access it at once.

Your job is to update your PriorityQueue class to be thread-safe.  That is, it should always produce correct results, even if multiple threads a reading and writing to it at the same time.
You should try to maximize performance (i.e., don't lock more than you need to), but not at the expense of correctness!

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Testing
Testing multithreaded code is notoriously hard, because it is non-deterministic.  However, you can build confidence that your code is working by creating scenarios where bugs would likely occur if your code was incorrect.  You'll want to read and write many elements (not just a few, or even a few hundred), and you'll probably want to have many threads competing for access, not just two.

