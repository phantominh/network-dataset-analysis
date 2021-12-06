#include "pagerank.h"

PageRank::PageRank(double decay, int iteration) {
    decay_ = decay;
    iteration_ = iteration;
}

PageRank::PageRank(Graph g, double decay, int iteration) {
    g_ = g;
    decay_ = decay;
    iteration_ = iteration;

    double initial_rank = 0.25;
    // Init rank of all nodes
    for (auto i : g_.getOutgoingAdjacencyDict()) {
        rank_.insert(std::pair<int, double>(i.first, initial_rank));
    }

    ranked_ = false;
}

void PageRank::rank() {
    // TODO: Implement rank until convergence
    for (int i = 0; i < iteration_; i++) {
        std::unordered_map<int, double> old_rank(rank_);
        for (auto iter : rank_) {
            int node = iter.first;
            double new_rank = 0;
            for (auto incoming_node : g_.incomingAdjacentVertexes(node)) {
                new_rank += old_rank[incoming_node] / g_.outgoingAdjacentVertexes(incoming_node).size();
            }
            new_rank = (new_rank * decay_) + (1 - decay_) / rank_.size();
            
            // Store new rank
            rank_[node] = new_rank;
        }
    }
}

std::unordered_map<int, double> PageRank::get_rank() {
    return rank_;
}