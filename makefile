# cc = c++-mp-4.8
cc = c++
copt = -c -std=c++0x -Wall -Werror -g

objects = utils.o STL.o Pairs.o Tuples.o shared_ptr.o algorithms.o iterators.o array.o vector.o list.o set.o map.o unordered_container.o functor.o

STL:$(objects)
		$(cc) -o STL $(objects)

utils.o : utils.h
STL.o : STL_test.h
Pairs.o : STL_test.h utils.h
Tuples.o : STL_test.h utils.h
shared_ptr.o : STL_test.h utils.h
algorithms.o : STL_test.h utils.h
iterators.o : STL_test.h utils.h
array.o : STL_test.h utils.h
vector.o : STL_test.h utils.h
list.o : STL_test.h utils.h
set.o : STL_test.h utils.h
map.o : STL_test.h utils.h
unordered_container.o : STL_test.h utils.h
functor.o : STL_test.h utils.h

%.o : %.cpp
		$(cc) $(copt) $< -o $@

.PHONY : clean
clean:
		rm -f $(objects)
		rm -f STL.exe