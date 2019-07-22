/*

// unordered_set visited
// queue<Vertex> Q

// Q.push(start)
// visited.insert(start)

// while (!Q.empty())
// for conn in Q.conns (assuming Q maintains its connections in an internal structure like a vector)
// if not visited
// Q.push(conn)
// visited.insert(conn)
// Q.pop()

*/

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

	void BFS() {

		// QUEUE
		std::queue<Vertex*> Q;
		// VISITED HASH
		std::unordered_set<std::string> visited;
		// ADD PATIENT 0
		Q.push(&vertices[0]);
		visited.insert(vertices[0].name);

		// WHILE NOT EMPTY
		while (!Q.empty()) {
			auto current = Q.front();
			Q.pop();
			// EACH UNVISITED CONN DEST IN CURRENT
			for (const auto& conn : current->conns) {
				if (visited.find(conn->dest->name) == visited.end()) {
					// VISIT AND ADD TO QUEUE
					std::cout << "Visiting " << conn->dest->name << '\n';
					visited.insert(conn->dest->name);
					Q.push(conn->dest);
				}
			}

		}

	}

};
