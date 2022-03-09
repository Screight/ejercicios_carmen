#include "GraphSearchBFS.h"
#include <queue>

GraphSearchBFS::GraphSearchBFS(SparseGraph& p_graph, int p_sourceIndex, int p_targetIndex) :
	m_sourceIndex(p_sourceIndex),
	m_targetIndex(p_targetIndex),
	m_graph(p_graph),
	m_isTargetFound(false),
	m_visitedNodes(m_graph.NumberOfActiveNodes(), unvisited),
	m_route(m_graph.NumberOfActiveNodes(), unvisited)
{
	m_isTargetFound = Search();
}

std::vector<int> GraphSearchBFS::GetPathToTarget() const {
	int currentNodeIndex = m_targetIndex;
	std::vector<int> pathToTarget;
	pathToTarget.push_back(m_targetIndex);
	while (currentNodeIndex != m_sourceIndex) {
		pathToTarget.push_back(m_route[currentNodeIndex]);
		currentNodeIndex = m_route[currentNodeIndex];
	}

	return pathToTarget;
}

bool GraphSearchBFS::Search() {
	std::queue<const GraphEdge*> queue; // stack of pointers to edges
	GraphEdge dummy(m_sourceIndex, m_sourceIndex, 0); // edge that points to itself to start the search
	std::vector<GraphEdge> edges;

	queue.push(&dummy);

	//mark the source node as visited
	m_visitedNodes[m_sourceIndex] = visited;

	while (!queue.empty()) {
		// grab next edge
		const GraphEdge* nextEdge = queue.front();
		// remove the edge from the stack
		queue.pop();
		// the vector route saves the node the edge comes from
		m_route[nextEdge->GetDestinationNodeIndex()] = nextEdge->GetOriginNodeIndex();
		// mark the destination node as visited
		m_visitedNodes[nextEdge->GetDestinationNodeIndex()] = visited;

		if (nextEdge->GetDestinationNodeIndex() == m_targetIndex) {
			return true; }

		std::vector<GraphEdge>* edges = m_graph.GetEdges(nextEdge->GetDestinationNodeIndex());
		int size = edges->size();

		for (int i = 0; i < size; i++) {
			if (m_visitedNodes[(*edges)[i].GetDestinationNodeIndex()] == unvisited) {
				queue.push(&(*edges)[i]);

				//the node is marked as visited here, BEFORE it is examined, because
				//it ensures a maximum of N edges are ever placed in the queue,
				// rather than E edges.

				m_visitedNodes[(*edges)[i].GetDestinationNodeIndex()] = visited;
			}
		}
	}
	// no path to target
	return false;
}