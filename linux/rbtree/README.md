rbtree
======

rbtree implementation adapted from linux kernel thus can be used in your own c program(of course in userspace).

using random generator in c lib, srand, rand, to get the number
insert 1000000 times, elapsed time: 1.11406
delete 1000000 times, elapsed time: 1.85949
insert 1000000 times, and then delete 1000000 times, elapsed time: 2.97355
in 951548 insert operation and 952176 delete operation, 90627 numbers is same.

sequence number from 0 to 1000000-1
insert 1000000 times, elapsed time: 0.490051
delete 1000000 times, elapsed time: 0.286170
insert 1000000 numbers, and then delete 1000000 numbers, elapsed time: 0.776221

Hard Info:

