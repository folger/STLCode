# cc = c++-mp-4.8
cc = c++
copt = -c -std=c++0x -Wall -Werror -g

objects = utils.o STL.o Pairs.o Tuples.o shared_ptr.o algorithms.o iterators.o array.o vector.o list.o set.o map.o unordered_container.o functor.o

STL:$(objects)
		$(cc) -o STL $(objects)

utils.o : utils.h
STL.o : Pairs.h Tuples.h shared_ptr.h algorithms.h iterators.h array.h vector.h list.h set.h map.h unordered_container.h functor.h
Pairs.o : Pairs.h utils.h
Tuples.o : Tuples.h utils.h
shared_ptr.o : shared_ptr.h utils.h
algorithms.o : algorithms.h utils.h
iterators.o : iterators.h utils.h
array.o : array.h utils.h
vector.o : vector.h utils.h
list.o : list.h utils.h
set.o : set.h utils.h
map.o : map.h utils.h
unordered_container.o : unordered_container.h utils.h
functor.o : functor.h utils.h

%.o : %.cpp
		$(cc) $(copt) $< -o $@

.PHONY : clean
clean:
		rm -f $(objects)
		rm -f STL.exe