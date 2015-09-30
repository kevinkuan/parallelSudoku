import sys
import time
import os, glob
import subprocess 

path = []
files = []

if len(sys.argv) > 1:
    if sys.argv[1].endswith('.txt'):
        [files.append(x) for x in sys.argv[1:]]
    else:
        files = glob.glob(os.path.join(sys.argv[1], '*.txt'))
else:
    path = 'cases/ex/'
    files = glob.glob(os.path.join(path, '*.txt'))


times = []
times_all = {}
run_no_times = 10

for sudoku in files:
    one_sum = 0
    print "%s" % sudoku
    for x in range(1,run_no_times+1):
        output,error = subprocess.Popen(['time', './omp', sudoku], 
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE).communicate()
        [real] = error.strip().split()[:1]
        print "\t%d,%f" % (x,float(real))
        times.append(float(real))
        times_all[(sudoku,x)] = float(real)
        one_sum = one_sum + float(real)

    one_avg = one_sum/run_no_times
    times.append(one_avg)
        

total = sum(times)
avg = total/len(times)
print 'Total average: %f' % avg

# persistance
logfile = open(str(time.time()) + '.log', 'w')
logfile.write(str(path) + '\n')
for sudoku,x in times_all.iteritems():
    (name,key) = sudoku
    logfile.write("%s,%d,%f\n" % (name,key,x))

logfile.close()
