#pragma once

#include <vector>
#include <list>
#include <map>

class Graph {
    public:
        /** @brief Default Constructor */
        Graph();

        /** @brief Copy Constructor */
        Graph(const Graph& other);

        /**
         * @brief Constructs a graph with a given vector of edge pairs 
         * @param data Input data
         */
        Graph(std::vector<std::pair<int, int>> data);

        /**
         * @brief Inserts a new vertex into the graph
         * @param v Vertex key
         */
        void insertVertex(int v);

        /**
         * @brief Returns incident vertexes of a vertex
         * 
         * @param v
         */
        std::list<int> incidentVertexes(int v);

        /**
         * @brief Insert an edge between 2 vertexes
         * 
         * @param v1 
         * @param v2 
         */
        void insertEdge(int v1, int v2);

        /** Adjacency dictionary getter */
        std::map<int, std::list<int>> getAdjacencyDict();

    private:
        std::map<int, std::list<int>> _adjacency_dict;
};