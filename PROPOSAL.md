# CS 225 Final Project Proposal
- <b>Team:</b> dijkstra's problem child
- <b>Members:</b> atran49, minhtp2, dvalen25, jonahlt2

## Leading Question
What is the most popular website? What is the shortest path between two websites?
 
## Dataset Acquisition and Processing:
<b>Dataset:</b>
- Source: https://snap.stanford.edu/data/web-Google.html 
- Description: Our Dataset is a Google web graph, in which Nodes represent web pages and directed edges represent hyperlinks between them. That means that the graph data can tell us about how we can get from one site to another through hyperlinks.

<b>Data Acquisition and Processing </b>
- We will download the dataset from the Stanford Network Analysis Project site, and include the authors' citation in our project:
    - J. Leskovec, K. Lang, A. Dasgupta, M. Mahoney. Community Structure in Large Networks: Natural Cluster Sizes and the Absence of Large Well-Defined Clusters. Internet Mathematics 6(1) 29--123, 2009.
Google programming contest, 2002


- We then store our dataset locally, in our respective machines. For testing on EWS purposes we will upload our dataset there too. We want to also take a subset of our dataset for testing and push it to the github repository.
- Dataset specifications:
    - Directed, unweighted
    - 875713 nodes, 5105039 edges
    - 2 columns representing source node and target node
    - Each node should be represented as a unique integer ID
 
<b> Error Handling </b>
- ???
 
 
## Graph Algorithms:
 Your final project must implement at least two graph data algorithms as well as a graph traversal from the list of example goals or you must propose an algorithm or set of graph algorithms that represent an equivalent amount of coding development. Accordingly, your proposal should clearly state what algorithms you will complete by the project's end. When describing your choices, be sure to include the following: What are the inputs you expect each method to take in? What output are you expecting for each method? If there are multiple ways to implement an algorithm, what is your target big O or efficiency benchmark? For the more complex algorithms, be sure to include as part of the input any additional information you might need. For example, A* search requires a heuristic. If you choose to do A*, what are some possible heuristics you might use?
 
1. Djikstra's Algorithm
- Input: 2 websites (or 2 nodes).
- Output: The shortest path between 2 websites.
- ???
2. PageRank
- Input: Directed graph of websites and links to each other, alpha, dangling, max number of iterations.
- Output: Output a set of websites (nodes), and their weights.
- ???
 
## Timeline:
### Week 1: <br>
- Setup the repo environment (Makefile)
- Parse the data (.txt)
- Implement the data structure storing the data (adjacency list)
- Unit Tests for parser and data structure
= Implement 1 kind of traversal (partially implemented)
### Week 2: <br>
- Finish traversal
- Implement Dijkstra’s algorithm
- Unit Tests for traversal and Dijkstra
### Week 3: <br>
- Implement PageRank algorithm (partially implemented or fully implemented)
- Unit Tests for PageRank algorithm
### Week 4: <br>
- Implement PageRank algorithm (fully implemented)
- Unit Tests for PageRank algorithm
- (Sketch Goal) Add visualization to the project (cs225::PNG)