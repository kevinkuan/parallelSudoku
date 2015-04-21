Parallelizing a Sudoku SolverKevin Kuan (kkuan)

Checkpoint:

Project CheckpointWork completed so far:March 30 – April 2: Finished the proposalApril 3 – 11: Began researching different ways to implement a serial implementation, began my attempt at an implementationApril 12 – 16: Begin work on a parallel implementation of the Sudoku solver. Finishing up a serial implementation, have not started on a parallel implementationApril 17 – 21: Continue to work on the parallel implementation. Finished a working serial implementation, have not started on the parallel implementation	New project schedule:March 30 – April 2: Research and write a proposal for a projectApril 3 – 11: Research various algorithms for a serial implementation, begin implementing the serial implementationApril 12 – 16: Continue to work on the serial implementation April 17 – 21: Finish working on the serial implementation, begin to collect data on the algorithm for different processorsApril 22 – April 25: Finish gathering data for serial implementation, begin working on the parallel implementationApril 26 - 30: Continue working on the parallel implementationMay 1 – May 4: Finish the parallel implementation, clean up code in anticipation for gathering dataMay 5 - 11: Collect data on the parallel algorithm for different processors. Finish the final project report.
SummaryTo reiterate, my goal is to write both a serial and parallel Sudoku solver, then run the program on different processors to compare the speedup times between my serial and parallel implementation. After some research, I determined that a backtracking serial implementation is the most reasonable algorithm to implement for the sake of having a working solver that could be parallelized. In my current serial implementation, I utilize backtracking in order to permute all of the possible Sudoku board states, and then narrow down the boards until I find my solution. This will make it trivial to parallelize because my optimization will focus on creating every board permutation from different starting locations. However, I have not begun doing initial time tests on different processors for this serial implementation. At the moment, I am more focused on making sure this serial implementation cannot be optimized anymore, and I would also like to write a more clean method of testing different boards, as my current implementation of testing makes it difficult to efficiently try different Sudoku boards. Once I finish cleaning up the serial implementation and gather data on the speedup for the serial implementation, I will begin writing the parallelized implementation.ProgressWith respect to the goals and deliverables stated in my proposal, I have a working serial implementation of my Sudoku solver. I have not had time to clean up my test cases so that it will make it easier to record the timings, but I have tested it on multiple boards of varying difficult and it will eventually solve the board, even if it may be slow on extremely difficult boards.However, I do not think I can reach my stretch goal of implementing multiple serial/parallel implementations, as I’ve now realized that it makes a lot more sense to focus on one efficient serial/parallel implementation rather than many average serial/parallel implementations. I want to refocus my attention on comparing the differences between a serial and parallel implementation of the solver, so I want to devote more time towards optimizing one implementation than making many of them. But once again, this was only a “nice to have” goal, so I will not prioritize my attention towards getting to this goal, but rather heavily consider coming back to this goal if I somehow happen to have time. This reasoning also applies to my “nice to have” goal of extending my algorithm for boards bigger than 9x9. Plan to show at the parallelism competitionI intend to show graphs and tables of the speedup differences between the serial and parallel implementation. I don’t think it makes a lot of sense to show a demo of the algorithm, as some of the more difficult boards may take longer to solve.Preliminary ResultsUnfortunately, I currently do not have preliminary results of the speedup of the serial implementation of different processors. However, I have tested my current implementation on boards of varying difficulty, and I have confirmed that my implementation can eventually solve any kind of Sudoku board of varying difficulty.Issues/concernsThere aren’t a lot of things that are concerning to me so far in this project. I suppose the only small struggle I had was settling on a serial implementation, but once I decided to implement a backtracking solution, my work was very straightforward. I don’t think I will encounter many problems in my parallel implementation, as I am only concerned with needing time to code. However, I will be sure to visit a TA if I happen to have any concerns or ideas.


First proposal:Summary:

I am going to make my own serial and parallel implementation of a Sudoku solver in order to analyze the speedup difference between a serial and parallel implementation of the solver. 
I will be using OpenMP to help me with the parallelization process, as well as use various Gates machines with different processors in order to better analyze the speedups.Background:Sudoku is a classic puzzle where the user must fill in a 9x9 grid with numbers such that each row, column and 3x3 grid will have the numbers 1 through 9 occur only once. 
Some Sudoku puzzles can go beyond 9x9 grids, but my implementation will focus specifically on the 9x9 size. 
All Sudoku puzzles will have some given numbers on them, and the difficulty of the puzzle varies depending on how many numbers are given, as well as the location of the numbers that are given.

Since the main purpose of Sudoku solvers is to quickly permute through all of the possible combinations of numbers that can be selected, my implementation will focus on efficiently searching through all of these possible number configurations. 
In particular, the basic way of solving Sudoku puzzles is to look for specific patterns, and having parallelism can allow the program to search for these patterns much more quickly, as they can be searched in parallel due to the fact that they’re not dependent on each other. Challenge:This problem is challenging because for a standard 9x9 grid Sudoku puzzle, there are 6.671 x 1021 different possible solutions. 
Evidently, even if the player is given around 20 numbers, that still leaves a lot of solutions that need to be permuted in order to find the one correct solution. 
Therefore, it is of the upmost important for my implementation to maximize my CPU usage, as it will be the main area of focus when it comes to getting the fastest solution time.
Communication costs will also be an aspect I need to look at closely, as I definitely anticipate the use of multiple workers/threads to permute different combinations of numbers. 
On the other hand, memory is a concept that I don’t have to worry about since traditional Sudoku boards are not very big, just 81 integers. 
However, I may have to reconsider memory if I choose to try using bigger Sudoku boards (such as 20 by 20 grids, etc.) or use an algorithm that remembers the state of the boards. Resources:I will be starting my code primarily from scratch, with a little bit of starter code from my previous homework assignments involving CUDA. 
I will be using the following website’s proposed algorithm as a starting point for my implementation: https://alitarhini.wordpress.com/2011/04/06/parallel-depth-first-sudoku-solver-algorithm/
I have access to all of the resources I need to use, which are primarily the Gates machines that will be running the algorithm. 
It might also be worthwhile to have access to the Blacklight machines if I want to try to compare the speedups on different processors. Goals:In order to have a successful project, I plan to have both a serial and parallel implementation of a Sudoku solver so that I can compare the speedup differences on different machines. 
If I happen to get ahead of my proposed schedule, I hope I can implement multiple serial/parallel implementations that utilize different algorithms, as well as extend my original serial/parallel implementation to work efficiently on Sudoku boards bigger than 9x9.
The demo I plan to show at the parallelism competition will be my algorithm running on various Sudoku boards. 
This will focus on comparing the computing time of the serial implementation versus that of the parallel implementation on Sudoku boards of varying difficulty. 
I will also present graphs of the speed-up on different machines that ran my algorithm to further emphasize how the parallelism optimized is much more optimal than the serial implementation.Platform ChoiceI am planning on using OpenMP to help implement my algorithm. 
Not only is it the language I am most comfortable using thus far in the course, but it is also useful since I anticipate there will be a fair amount of data sharing, and OpenMP is useful in that regard. 
If there are other implementations of a Sudoku solver that show a lot of promise, I will consider switching languages, especially if I have extra time towards the end of the project and I want to work on a different implementation.	 Schedule:
March 30 – April 2: Research and write a proposal for a project
April 3 – 11 : Implement a serial implementation of the Sudoku solver, start thinking about places to optimize for parallelization
April 12 – 16 : Finish a working serial implementation. Begin work on a parallel implementation of the Sudoku solver.
April 17 – 21 : Continue to work on the parallel implementation
April 22 – April 27 : Finish up the parallel implementation, study for Exam II
April 28 – May 4 :Talk to TA’s, look for ways to optimize the implementation
May 5 - 11 : Clean up code and finish the final project report.