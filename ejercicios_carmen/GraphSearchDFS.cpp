#include "GraphSearchDFS.h"
#include <stack>

GraphSearchDFS::GraphSearchDFS(SparseGraph& p_graph, int p_sourceIndex, int p_targetIndex) :
	m_sourceIndex(p_sourceIndex),
	m_targetIndex(p_targetIndex),
	m_graph(p_graph),
	m_isTargetFound(false),
	m_visitedNodes(m_graph.NumberOfActiveNodes(), unvisited),
	m_route(m_graph.NumberOfActiveNodes(), no_parent_assigned)
	{
	m_isTargetFound = Search();
}

std::vector<int> GraphSearchDFS::GetPathToTarget() const {
	int currentNodeIndex = m_targetIndex;
	std::vector<int> pathToTarget;
	pathToTarget.push_back(m_targetIndex);
	while(currentNodeIndex != m_sourceIndex) {
		pathToTarget.push_back(m_route[currentNodeIndex]);
		currentNodeIndex = m_route[currentNodeIndex];
	}

	return pathToTarget;
}

bool GraphSearchDFS::Search() {
	std::stack<const GraphEdge*> stack; // stack of pointers to edges
	GraphEdge dummy(m_sourceIndex, m_sourceIndex, 0); // edge that points to itself to start the search
	std::vector<GraphEdge> edges;

	stack.push(&dummy);

	while (!stack.empty()) {
			// grab next edge
			const GraphEdge* nextEdge = stack.top();
			// remove the edge from the stack
			stack.pop();
			// the vector route saves the node the edge comes from
			m_route[nextEdge->GetDestinationNodeIndex()] = nextEdge->GetOriginNodeIndex();
			// mark the destination node as visited
			m_visitedNodes[nextEdge->GetDestinationNodeIndex()] = visited;

			if (nextEdge->GetDestinationNodeIndex() == m_targetIndex) { return true; }

			std::vector<GraphEdge>* edges = m_graph.GetEdges(nextEdge->GetDestinationNodeIndex());
			int size = edges->size();

			for (int i = 0; i < size; i++){
					if (m_visitedNodes[(*edges)[i].GetDestinationNodeIndex()] == unvisited) {
							stack.push(&(*edges)[i]);
					}
			}
	}
	// no path to target
	return false;
}