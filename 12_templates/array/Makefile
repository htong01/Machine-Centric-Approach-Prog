CC := g++
CFLAGS := -Wall
SUBSRC := /array
# TESTSRC := /array

# Check whether the student submitted a cpp file, or included all their code in
# the header file.  If the former, we need to compile it.
STUDENTCPP := $(wildcard $SUBSRC/array.cpp)

student_test:
	$(CC) $(STUDENTCPP) test_array.cpp -o student_test

template_test_int:
	$(CC) $(CFLAGS) -I$(SUBSRC) -DTEMPLATE_TYPE_INT $(STUDENTCPP) /template_test.cpp -o template_test_int

template_test_class:
	$(CC) $(CFLAGS) -I$(SUBSRC) -DTEMPLATE_TYPE_CLASS $(STUDENTCPP) $(TESTSRC)/template_test.cpp -o template_test_class

template_test_intptr:
	$(CC) $(CFLAGS) -I$(SUBSRC) -DTEMPLATE_TYPE_INTPTR $(STUDENTCPP) $(TESTSRC)/template_test.cpp -o template_test_intptr

