all:
	flex -o scanner.cpp scanner.l
	bison -o parser.cpp parser.y
	clang++ -g main.cpp scanner.cpp parser.cpp interpreter.cpp command.cpp -o a.out

clean:
	rm -rf scanner.cpp
	rm -rf parser.cpp parser.hpp location.hh position.hh stack.hh
	rm -rf a.out

transfer:
	cp command.h parser.y scanner.l command.cpp scanner.h scanner.cpp interpreter.h interpreter.cpp location.hh stack.hh position.hh parser.hpp parser.cpp json.hpp ~/work/client-coherent-NodeGen-Lib-fs1/jsonpath_parser/