default:
	g++ -fopenmp -g -o parallel parallel.cpp 
	g++ -fopenmp -g -o serial serial.cpp 

run: ./parallel cases/worst-case.txt $(N_THREADS)

clean:
	rm -rf parallel *.o *~ *.*~
