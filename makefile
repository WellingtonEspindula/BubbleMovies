############################# Makefile ##########################
all: bubblemovies
bubblemovies: tst.o movie.o rating.o user.o tag.o stringHashable.o intHC.o utils.o api.o main.o
		# O compilador faz a ligação entre os dois objetos
		g++ -o bubblemovies Debug/datastructures/tst.o Debug/model/movie.o Debug/model/rating.o Debug/model/user.o Debug/model/tag.o Debug/utils/stringHashable.o Debug/utils/intHC.o Debug/utils/utils.o Debug/api.o Debug/main.o -g -O3 -std=c++17

#interfaces
# comparable.o:
# 		g++ -o Debug/interfaces/comparable.o -c source/interfaces/comparable.cpp -W -Wall -pedantic -g -O3 -std=c11
# hashable.o:
# 		g++ -o Debug/interfaces/hashable.o -c source/interfaces/hashable.cpp -W -Wall -pedantic -g -O3 -std=c11

#models
movie.o:
		g++ -o Debug/model/movie.o -c source/model/movie.cpp -W -Wall -pedantic -g -O3 -std=c++17
rating.o:
		g++ -o Debug/model/rating.o -c source/model/rating.cpp -W -Wall -pedantic -g -O3 -std=c++17
user.o:
		g++ -o Debug/model/user.o -c source/model/user.cpp -W -Wall -pedantic -g -O3 -std=c++17
tag.o:
		g++ -o Debug/model/tag.o -c source/model/tag.cpp -W -Wall -pedantic -g -O3 -std=c++17

#datastructs
tst.o:
		g++ -o Debug/datastructures/tst.o -c source/datastructures/tst.cpp -W -Wall -pedantic -g -O3 -std=c++17


#utils
stringHashable.o:
		g++ -o Debug/utils/stringHashable.o -c source/utils/stringHashable.cpp -W -Wall -pedantic -g -O3 -std=c++17

intHC.o:
		g++ -o Debug/utils/intHC.o -c source/utils/intHC.cpp -W -Wall -pedantic -g -O3 -std=c++17

utils.o:
		g++ -o Debug/utils/utils.o -c source/utils/utils.cpp -W -Wall -pedantic -g -O3 -std=c++17

#api and main
api.o:
		g++ -o Debug/api.o -c source/api.cpp -W -Wall -pedantic -g -O3 -std=c++17

main.o:
		g++ -o Debug/main.o -c source/main.cpp -W -Wall -pedantic -g -O3 -std=c++17

clean:
		rm Debug/*.o


run:	bubblemovies clean
		./bubblemovies