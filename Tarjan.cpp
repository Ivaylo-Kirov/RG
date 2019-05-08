#include "pch.h"

// USAGE
//Graph g;
//g.addVertex("Toronto"); // 0
//g.addVertex("Markham"); // 1
//g.addVertex("Pickering"); // 2
//g.addVertex("Mississauga"); // 3
//g.addVertex("North Bay"); // 4
//g.addVertex("Ajax"); // 5
//g.addVertex("Niagara"); // 6
//g.addVertex("Buffalo"); // 7
//
//g.addEdge(&g.vertices[0], &g.vertices[1], 4);
//g.addEdge(&g.vertices[0], &g.vertices[2], 6);
//g.addEdge(&g.vertices[0], &g.vertices[3], 4);
//g.addEdge(&g.vertices[1], &g.vertices[4], 35);
//g.addEdge(&g.vertices[1], &g.vertices[3], 5);
//g.addEdge(&g.vertices[2], &g.vertices[5], 7);
//g.addEdge(&g.vertices[2], &g.vertices[1], 9);
//g.addEdge(&g.vertices[3], &g.vertices[6], 28);
//g.addEdge(&g.vertices[6], &g.vertices[7], 12);
//g.addEdge(&g.vertices[6], &g.vertices[0], 108);
//
//
////g.DFS();
std::map<std::string, int> result;
result = g.Tarjan();

std::map<int, std::string> tarjanMapToSort;

for (auto item : result) {
	tarjanMapToSort[item.second] = item.first;
}

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
		static std::unordered_set<std::string> visited;
		if (current == nullptr) return;
		std::cout << "Visiting " << current->name << '\n';
		visited.insert(current->name);
		for (const auto& conn : current->conns) {
			if (visited.find(conn->dest->name) == visited.end()) {
				DFSUtil(conn->dest);
			}
		}
	}

	std::map<std::string, int> Tarjan() {
		return TarjanUtil(&vertices[0]);
	}

	std::map<std::string, int> TarjanUtil(Vertex* current) {

		static std::deque<Vertex*> S;
		static std::map<std::string, int> index;
		static std::map<std::string, int> lowLink;
		static int globalIndex = 0;

		index[current->name] = globalIndex;
		lowLink[current->name] = globalIndex;

		globalIndex++;

		S.push_back(current);

		for (const auto& conn : current->conns) {
			if (std::find(begin(S), end(S), conn->dest) == S.end()) {
				TarjanUtil(conn->dest);
				lowLink[current->name] = std::min(lowLink[current->name], lowLink[conn->dest->name]);
			}
			else {
				lowLink[current->name] = std::min(lowLink[current->name], index[conn->dest->name]);
			}
		}

		return lowLink;

	}

};
