#include <iostream>
#include <map>
#include <vector>
#include <utility>
 
// 定义顶点类型，这里使用字符
using Vertex = char;
 
// 边的表示，这里使用std::pair表示起点和终点
using Edge = std::pair<Vertex, Vertex>;
 
// 建图函数
void buildGraph(std::map<Vertex, std::vector<Edge>> &graph) {
    // 添加顶点和边
    graph['A'].push_back({'A', 'B'});
    graph['A'].push_back({'A', 'C'});
    graph['B'].push_back({'B', 'C'});
    graph['C'].push_back({'C', 'D'});
    // ... 添加其他顶点和边
}
 
int main() {
    std::map<Vertex, std::vector<Edge>> graph;
    buildGraph(graph);
 
    // 输出图中的边
    for (const auto &vertex : graph) {
        Vertex from = vertex.first;
        const std::vector<Edge> &edges = vertex.second;
        for (const Edge &edge : edges) {
            Vertex to = edge.second;
            std::cout << "Edge: " << from << " -> " << to << std::endl;
        }
    }
 
    return 0;
}
