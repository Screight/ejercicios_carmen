#ifndef  GRAPH_EDGE
#define GRAPH_EDGE

class GraphEdge {
protected:
	int m_originNodeIndex;
	int m_destinationNodeIndex;
	float m_cost;

public:
	GraphEdge(int p_originNodeIndex, int p_destinationNodeIndex, float p_cost):m_originNodeIndex(p_originNodeIndex), m_destinationNodeIndex(p_destinationNodeIndex), m_cost(p_cost){}

	GraphEdge(int p_originNodeIndex, int p_destinationNodeIndex):m_originNodeIndex(p_originNodeIndex), m_destinationNodeIndex(p_destinationNodeIndex), m_cost(1) {}

	GraphEdge(): m_originNodeIndex(-1), m_destinationNodeIndex(-1), m_cost(1) {}

	int GetOriginNodeIndex() const { return m_originNodeIndex; }
	int SetOriginNodeIndex(int p_index) { m_originNodeIndex = p_index; }

	int GetDestinationNodeIndex() const { return m_destinationNodeIndex; }
	int SetDestinationNodeIndex(int p_index) { m_destinationNodeIndex = p_index; }

	float GetCost() { return m_cost; }
	float SetCost(float p_value) { m_cost = p_value; }

};
#endif