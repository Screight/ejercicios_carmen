#include "GraphSearchDFS.h"
#include <stack>

GraphSearchDFS::GraphSearchDFS(const SparseGraph& p_graph, int p_sourceIndex) :
	m_sourceIndex(p_sourceIndex),
	m_targetIndex(-1),
	m_graph(p_graph),
	m_isTargetFound(false),
	m_visitedNodes(m_graph.NumberOfActiveNodes(), unvisited),
	m_route(m_graph.NumberOfActiveNodes(), no_parent_assigned)
	{
	Search();
}

std::list<int> GraphSearchDFS::GetPathToTarget() const {
	int currentNodeIndex = m_targetIndex;
	std::list<int> pathToTarget;
	while(currentNodeIndex != m_sourceIndex) {
		pathToTarget.push_front(m_targetIndex);
		currentNodeIndex = m_route[m_route[currentNodeIndex]];
	}

	return pathToTarget;
}

void GraphSearchDFS::Search() {
	std::stack<const GraphEdge*> stack; // stack of pointers to edges
	GraphEdge Dummy(m_sourceIndex, m_targetIndex, 0); // edge that points to itself to start the search

}