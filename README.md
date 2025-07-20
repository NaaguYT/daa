## Algorithms  
** 1. Euclid’s GCD Algorithms**  
Algorithms and Time Complexities for GCD Methods

1. Euclid’s Division Algorithm  
   -  Algorithm  
     – While n ≠ 0: compute r = m mod n; set m ← n; n ← r.  
   -  Ops counted  
     – One comparison (n≠0) and one modulo per iteration; plus assignments.  
   -  Best-case: Θ(1) (when initial n divides m immediately)  
   -  Worst-case: Θ(log min(m,n)) (Euclid’s bound)  
   -  Average-case: Θ(log n)

2. Consecutive-Integer Checking  
   -  Algorithm  
     – Let t = min(m,n).  
     – While t > 0: test if both m mod t == 0 and n mod t == 0; if so, return t; else t--.  
   -  Ops counted  
     – One loop check per t, two modulo tests per t.  
   -  Best-case: Θ(1) (when m=n or one divides the other at t = min)  
   -  Worst-case: Θ(n) (when the only common divisor is 1)  
   -  Average-case: Θ(n)

3. Subtractive (Modified Euclid) Algorithm  
   -  Algorithm  
     – While m ≠ n: subtract the smaller from the larger.  
   -  Ops counted  
     – One comparison and one subtraction per iteration.  
   -  Best-case: Θ(1) (when m=n at start)  
   -  Worst-case: Θ(m + n) in very unbalanced cases (but generally Θ(n²) worst)  
   -  Average-case: Θ(n log n) (rough heuristic)

Comparative Analysis  
- Range of inputs: choose N from 100 to 10 000 in steps of 500.  
- Trials per N: 10 random pairs (m,n).  
- Record minimum and maximum operation counts for each method.  

Expected Plot  
- X-axis: maximum input value N.  
- Y-axis: basic operations.  
- Curves:  
  -  Euclid: shallow logarithmic rise (Θ(log N)).  
  -  Consecutive: linear rise (Θ(N)).  
  -  Subtractive: intermediate slope, steeper than logarithmic but shallower than pure linear in many cases.

## 2. Searching Algorithms  
### a) Sequential Search  
- Scan array[0…n–1] until key found or end.  
- Best-case: Θ(1) (found at index 0)  
- Worst-case: Θ(n) (not found or at end)  
- Average: Θ(n).  
### b) Binary Search (Recursive)  
- Divide array in half each call.  
- Best-case: Θ(1) (mid = key)  
- Worst/average: Θ(log n).  

**Tester & Plotter**  
- **Sizes**: 1 000→32 000 step 2 000  
- **Trials**: 5 per size for best, worst, random average.  
- **Plot**: two series of Min/Avg/Max curves on same axes; linear vs log shapes.  

## 3. Elementary Sorting  
### a) Selection Sort  
- Repeatedly select min of unsorted suffix and swap.  
- Always Θ(n²); few swaps.  
### b) Bubble Sort  
- Repeated adjacent swaps; early exit if no swaps.  
- Best: Θ(n); worst/avg: Θ(n²).  
### c) Insertion Sort  
- Insert each element into sorted prefix.  
- Best: Θ(n); worst/avg: Θ(n²).  

**Tester & Plotter**  
- **Sizes**: 1 000→10 000 step 1 000  
- **Trials**: 3 for sorted (best), reverse (worst), random (avg).  
- **Plot**: three curves; parabolic for all but insertion’s best linear.  

## 4. Brute-Force String Matching  
- Try aligning pattern (length M) at each text index (length N).  
- Best: Θ(M) (match at pos 0); worst: Θ(M·N) (many partial matches); avg: ~Θ(N·M).  
- **Sizes**: N=1 000→10 000 step 1 000; M fixed at 10.  
- **Trials**: 5 for best, worst, average.  
- **Plot**: upward parabola.  

## 5. Merge Sort  
- Divide-and-conquer; merges in Θ(n).  
- Always Θ(n log n).  
- **Sizes**: 1 000→32 000 step 2 000; 5 trials best/worst/avg identical.  
- **Plot**: smooth n log n convex.  

## 6. Quick Sort  
- Partition around pivot.  
- Best/avg: Θ(n log n); worst: Θ(n²) (sorted input with naive pivot).  
- **Sizes**: 1 000→16 000 step 1 000; 5 trials for random (avg), sorted (worst), random (best-like).  
- **Plot**: two distinct curves; avg gentle convex, worst steep parabola.  

## 7. Graph Traversals  
### a) DFS Connectivity & Acyclicity  
- DFS from each unvisited vertex; count components; detect back-edges.  
- Θ(V+E).  
### b) BFS Connectivity  
- Level-order with queue; same connectivity and component detection.  
- Θ(V+E).  

**Tester & Plotter**  
- **Vertices**: 10→100 step 10; **Density**: p=0.1→0.9 over 5 trials.  
- **Plot**: near-linear lines; slight slope variation with density.  

## 8. Topological Ordering  
### a) DFS-based Topo Sort  
- Run DFS, push nodes post-visit onto stack.  
- Θ(V+E).  
### b) Source Removal  
- Repeatedly remove vertices of in-degree 0, update in-degrees with queue.  
- Θ(V+E).  

**Tester & Plotter**  
- **Vertices**: 10→100 step 10; **Density**: p=0.1→0.9.  
- **Plot**: linear.  

## 9. Graph Closure & Shortest Paths  
### a) Warshall’s Transitive Closure  
- Triple nested loops k,i,j; Θ(n³).  
### b) Floyd’s All-Pairs Shortest Paths  
- Triple nested loops; Θ(n³).  

**Tester & Plotter**  
- **Vertices**: 2→12 step 1;  – Trials incorporate random weighted/directed graphs.  
- **Plot**: steep cubic; use `set logscale y` for clarity.  

## 10. 0/1 Knapsack (DP)  
- DP table of size (n+1)×(W+1); Θ(n·W).  
- **Inputs**: n=10→50 step 5; W≈100–150; Trials=5.  
- **Plot**: linear in n (with W fixed); 2D surface if both varied.  

## 11. Dijkstra’s Shortest Paths  
- From single source with min-heap: Θ((V+E) log V).  
- **Inputs**: V=10→50 step 5; density p=0.3→0.7; Trials=3.  
- **Plot**:  
  - Sparse (E≈V): near-linear.  
  - Dense (E≈V²): superlinear (quadratic-like).  
