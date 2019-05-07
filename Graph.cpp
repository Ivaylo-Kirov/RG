class Edge;
class Vertex;
class Graph;

class Vertex {
public:
	std::string name;
	std::vector<Edge*> conns;
	Vertex(const std::string& name)
		: name(name)
	{}
};

class Edge {
public:
	Vertex * src;
	Vertex* dest;
	int weight;
	Edge(Vertex* src, Vertex* dest, int weight = 1)
		: src(src)
		, dest(dest)
		, weight(weight)
	{}
};

class Graph {
	std::vector<Vertex*> vertices;

	void addVertex(Vertex* v) {
		vertices.push_back(v);
	}

	void addEdge(Vertex* src, Vertex* dest, int weight) {
		src->conns.push_back(new Edge(src, dest, weight));
	}

};
