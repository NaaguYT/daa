# Comprehensive Notes for DAA Lab Syllabus

Sunday, July 20, 2025

## 1. Euclid’s GCD Algorithms  
**Algorithms**  
- **Consecutive Integer Checking**  
  - Let t = min(m,n); while t>0, test if t divides both m,n; decrement t.  
  - *Ops counted*: one comparison per t, two modulo ops per test.  
  - *Worst-case*: Θ(n) when m,n≈n and only t=1 works.  
- **Modified Euclid (Division)**  
  - While n≠0, compute r = m mod n; set m←n,n←r.  
  - *Ops counted*: one comparison and one modulo per iteration.  
  - *Worst-case*: Θ(log n) by Euclid’s analysis.  

**Comparative Analysis**  
- **Range of inputs**: sizes from 100 → 10 000 in steps of 500.  
- **Trials**: 10 random pairs per size; record min/avg/max op-counts.  
- **Expected Plot**:  
  - X-axis: input magnitude  
  - Y-axis: basic ops  
  - Two curves: straight line (consecutive) vs shallow log curve (Euclid).  

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
