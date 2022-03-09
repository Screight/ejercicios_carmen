#include <vector>
#include <list>
#include "GraphEdge.h"
#include "NavigationGraphNode.h"

class SparseGraph {
private: 
	std::vector<NavigationGraphNode> m_nodes; // nodes that form this graph
	std::vector<std::vector<GraphEdge>> m_edges; // each node index keys into the list of edges associated with that node

	bool m_isDiGraph;
	int m_nextNodeIndex; // the index of the next node to be added

public:
	SparseGraph(bool p_isDiGraph): m_isDiGraph(p_isDiGraph), m_nextNodeIndex(0){}
	
	// returns the node at the given index if it exists
	const NavigationGraphNode& GetNode(int p_index) const{
		if (m_nodes.size() < p_index && p_index > 0) { return m_nodes[p_index]; }
	}
	// not constant version
	NavigationGraphNode& GetNode(int p_index) {
		if (p_index < m_nodes.size() && p_index >= 0) {
			return m_nodes[p_index]; }
	}

	const GraphEdge& GetEdge(int p_originNodeIndex, int p_destinationNodeIndex) {
		
		if (p_originNodeIndex < m_nodes.size() &&
			p_destinationNodeIndex < m_nodes.size() &&
			m_nodes[p_originNodeIndex].Index() >= 0) {

			for (int i = 0; i < m_edges[p_originNodeIndex].size(); i++) {
				if (m_edges[p_originNodeIndex][i].GetDestinationNodeIndex() == p_destinationNodeIndex) {
					return m_edges[p_originNodeIndex][i];
				}
			}
		}
	}

	int GetNextFreeNodeIndex() const {
		return m_nextNodeIndex;
	}

	int AddNode(NavigationGraphNode p_node) {
		p_node.SetIndex(m_nextNodeIndex);
		m_nodes.push_back(p_node);
		m_edges.push_back(std::vector<GraphEdge>());
		m_nextNodeIndex++;
		return p_node.Index();
	}

	void RemoveNode(int p_nodeIndex) {
		if (p_nodeIndex >= m_nodes.size()) { return; }
		if (p_nodeIndex < 0) { return; }
		m_nodes[p_nodeIndex].SetIndex(-1);
	}

	void AddEdge(GraphEdge p_edge) {
		if (p_edge.GetOriginNodeIndex() >= m_nodes.size()) { return; }
		if (p_edge.GetDestinationNodeIndex() >= m_nodes.size()) { return; }
		m_edges[p_edge.GetOriginNodeIndex()].push_back(p_edge);
	}

	void RemoveEdge(int p_originNodeIndex, int p_destinationNodeIndex) {
		if (p_originNodeIndex >= m_nodes.size()) { return; }
		if (p_destinationNodeIndex >= m_nodes.size()) { return; }
		for (int i = 0; i < m_edges[p_originNodeIndex].size(); i++) {
			if (m_edges[p_originNodeIndex][i].GetDestinationNodeIndex() == p_destinationNodeIndex) {
				m_edges[p_originNodeIndex].erase(m_edges[p_originNodeIndex].begin() + i);
			}
		}
	}

	int NumberOfNodes() const {
		return m_nodes.size();
	}

	int NumberOfActiveNodes()const {
		int numberOfActiveNodes = 0;
		for (int i = 0; i < m_nodes.size(); i++) {
			if (m_nodes[i].Index() > 0) { numberOfActiveNodes++; }
		}
		return numberOfActiveNodes;
	}

	int NumberOfEdges() const {
		int numberOfEdges = 0;
		for (int i = 0; i < m_edges.size(); i++) {
			numberOfEdges += m_edges[i].size();
		}
	}

	int NumberOfActiveEdges() const {
		int numberOfEdges = 0;
		for (int i = 0; i < m_edges.size(); i++) {
			if (m_nodes[i].Index() > 0) {
				numberOfEdges += m_edges[i].size();
			}
		}
		return numberOfEdges;
	}

	bool isDiGraph() const { return m_isDiGraph; }
	bool isEmpty() const {
		if (NumberOfActiveNodes() == 0) { return true; }
		return false;
	}

	bool IsNodePresent(int p_nodeIndex) const {
		if (p_nodeIndex < m_nodes.size()) {
			if (m_nodes[p_nodeIndex].Index() > 0) { return true; }
			return false;
		}
	}

};
