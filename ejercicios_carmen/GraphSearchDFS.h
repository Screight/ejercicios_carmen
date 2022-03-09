#include "SparceGraph.h"

class GraphSearchDFS {

enum{visited, unvisited, no_parent_assigned};

private:
	SparseGraph& m_graph;
	// records the indexes of all the nodes that are visited as the search progresses
	// contains the same number of elements as there are nodes in the graphs
	std::vector<int> m_visitedNodes;
	std::vector<int> m_route; // contains the route taken to the target
	// contains the same number of elements as there are nodes in the graph. Each element is initially set to no_parent_assigned. This vector stores the route to the target node by recording the parents of each node at the relevant index.
	int m_sourceIndex;
	int m_targetIndex;
	bool m_isTargetFound;

public:
	GraphSearchDFS(SparseGraph& graph, int p_sourceIndex, int p_targetIndex);
	bool Search();
	bool IsFound() const { return m_isTargetFound; }
	std::vector<int> GetPathToTarget() const;
};