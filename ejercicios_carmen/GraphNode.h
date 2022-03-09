class GraphNode {

protected:
	int m_index;

public:
	GraphNode() :m_index(-1) {}
	GraphNode(int p_index) :m_index(p_index) {}

	virtual ~GraphNode(){}

	int Index() const { 
		return m_index; }
	void SetIndex(int p_index) { m_index = p_index; }

};