The Metro app utilizes the Dijkstra algorithm, as well as BFS (Breadth-First Search) and DFS (Depth-First Search) algorithms, to determine the shortest route between two given routes. The Dijkstra algorithm is primarily employed for finding the shortest path between two nodes in a graph, in this case representing the metro stations.
It calculates the shortest path by iteratively exploring neighboring nodes and updating the shortest path information.

BFS and DFS algorithms are auxiliary tools used in conjunction with Dijkstra's algorithm. BFS explores the graph in a breadth-first manner, examining all the neighbors of 
a node before moving on to the next level of nodes. On the other hand, DFS explores the graph by going as deep as possible along each branch before backtracking.

By combining these algorithms, the Metro app can effectively find the shortest route between two metro stations. Dijkstra's algorithm determines the overall shortest path,
while BFS and DFS aid in traversing the graph and examining neighboring stations. This comprehensive approach ensures accurate and efficient route calculations for users of the Metro app.
