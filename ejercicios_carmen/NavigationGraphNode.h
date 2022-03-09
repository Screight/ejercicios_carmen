#ifndef NAVIGATION_GRAPH_NODE
#define NAVIGATION_GRAPH_NODE

#include "GraphNode.h"
#include "Vector2D.h"

class NavigationGraphNode : public GraphNode {
protected:
	Vector2D<float> m_position;
public:
	NavigationGraphNode(Vector2D<float> p_position):GraphNode(),
		m_position(p_position) {};

	NavigationGraphNode(Vector2D<float> p_position, int p_index)
		:GraphNode(p_index), m_position(p_position) {};

	Vector2D<float> GetPosition() { return m_position; }
	void SetPosition(Vector2D<float> p_position) { m_position = p_position; }
};

#endif // ! NAVIGATION_GRAPH_NODE