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
public:
	std::vector<Vertex> vertices;

	void addVertex(std::string name) {
		vertices.emplace_back(name);
	}

	void addEdge(Vertex* src, Vertex* dest, int weight) {
		src->conns.push_back(new Edge(src, dest, weight));
	}

	void DFS() {
		DFSUtil(&vertices[0]);
	}

void DFSUtil(Vertex* current) {
	// VISITED HASH - STATIC
	static std::unordered_set<std::string> visited;

	// BASE EXIT - NULLPTR = RETURN
	if (current == nullptr) return;

	// DO THE ACTUAL "VISIT"
	std::cout << "Visiting: " << current->name << '\n';

	// INSERT INTO VISITED HASH
	visited.insert(current->name);

	// ITERATE THROUGH ALL CONNS
	for (const auto& conn : current->conns) {
		if (visited.find(conn->dest->name) == visited.end()) {
			// RECURSE ON FIRST NOT VISITED
			DFSUtil(conn->dest);
		}
	}

}

};
