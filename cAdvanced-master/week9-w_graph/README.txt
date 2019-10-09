Then if we want the shortest travel distance between cities an appropriate weight would be the road mileage. 
If we are concerned with the dollar cost of a trip and went the cheapest trip then an appropriate weight for the edges would be the cost to travel between the cities.

Applications
static/dynamic network routing
robot motion planning
map/route generation in traffic

Shortest-Path problems
Single-source (single-destination). Find a shortest path from a given source (vertex s) to each of the vertices. 
Single-pair. Given two vertices, find a shortest path between them. Solution to single-source problem solves this problem efficiently, too.
All-pairs. Find shortest-paths for every pair of vertices. Dynamic programming algorithm

Negative edges are OK, as long as there are no negative weight cycles (otherwise paths with arbitrary small “lengths” would be possible)
Shortest-paths can have no cycles (otherwise we could improve them by removing cycles)
Any shortest-path in graph G can be no longer than n – 1 edges, where n is the number of vertices

Non-negative edge weights
Like breadth-first search (if all weights = 1, one can simply use BFS)
Use Q, a priority queue ADT keyed by v.d() (BFS used FIFO queue, here we use a PQ, which is re-organized whenever some d decreases)
Basic idea
maintain a set S of solved vertices
at each step select "closest" vertex u, add it to S, and relax all edges from u

