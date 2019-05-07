#include "pch.h"

// USAGE
//
//Graph g;
//g.addVertex("Toronto"); // 0
//g.addVertex("Markham"); // 1
//g.addVertex("Pickering"); // 2
//g.addVertex("Mississauga"); // 3
//g.addVertex("North Bay"); // 4
//g.addVertex("Ajax"); // 5
//
//g.addEdge(&g.vertices[0], &g.vertices[1], 4);
//g.addEdge(&g.vertices[0], &g.vertices[2], 6);
//g.addEdge(&g.vertices[0], &g.vertices[3], 4);
//g.addEdge(&g.vertices[1], &g.vertices[4], 35);
//g.addEdge(&g.vertices[2], &g.vertices[5], 7);
//
//auto result = g.Dijkstra();
//
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

	std::map<Vertex*, int> Dijkstra() {
		return DijkstraUtil(&vertices[0]);
	}

	std::map<Vertex*, int> DijkstraUtil(Vertex* start) {

		std::map<Vertex*, int> distances; // maintains distance as they get updated
		std::map<Vertex*, int> distances_tracking; // used for most operations like getting MIN and ERASe

		std::deque<Vertex*> Q;

		for (auto& v : vertices) {
			Q.push_back(&v);
			distances[&v] = INT_MAX;
			distances_tracking[&v] = INT_MAX;
		}

		distances[start] = 0;
		distances_tracking[start] = 0;

		while (!Q.empty()) {
			// First step is to pick LOWEST DISTANCE
			auto minNode = std::min_element(distances_tracking.begin(), distances_tracking.end(), [](std::pair<Vertex*, int> lhs, std::pair<Vertex*, int> rhs) {
				return lhs.second < rhs.second; });
			auto current = minNode->first;

			for (const auto& conn : current->conns) {
				// RELAXATION
				int distance_to_conn = distances[current] + conn->weight;
				if (distances[conn->dest] > distance_to_conn) {
					distances[conn->dest] = distance_to_conn;
					distances_tracking[conn->dest] = distance_to_conn;
				}
			}

			auto iter = distances_tracking.begin();
			auto endIter = distances_tracking.end();
			for (; iter != endIter; ) {
				if (iter->first == current) {
					distances_tracking.erase(iter++);
				}
				else {
					iter++;
				}
			}
			Q.erase(std::remove(begin(Q), end(Q), current), Q.end());

		}
		return distances;

	}

};
