#pragma once

#include <algorithm>
#include <utility>
#include <vector>

#include "matrix.hpp"

// NOTE: Graph module is still in progress and not feature-complete yet.

class Graph
{
private:
    int vertices;
    bool directed;
    std::vector<std::pair<int, int>> edge_list;

    void validate_vertex(int vertex) const
    {
        if (vertex < 0 || vertex >= this->vertices)
        {
            std::cerr << "Error: Vertex index out of range.";
            std::exit(1);
        }
    }

public:
    Graph() : vertices(0), directed(false) {}

    Graph(int vertices, bool directed = false)
    {
        if (vertices < 0)
        {
            std::cerr << "Error: Number of vertices cannot be negative.";
            std::exit(1);
        }

        this->vertices = vertices;
        this->directed = directed;
    }

    void add_edge(int from, int to)
    {
        validate_vertex(from);
        validate_vertex(to);
        this->edge_list.push_back({from, to});
    }

    int vertex_count() const
    {
        return this->vertices;
    }

    int edge_count() const
    {
        return static_cast<int>(this->edge_list.size());
    }

    Matrix adjacency_matrix() const
    {
        std::vector<int> matrix(this->vertices * this->vertices, 0);

        for (const auto &edge : this->edge_list)
        {
            int u = edge.first;
            int v = edge.second;

            matrix[u * this->vertices + v] += 1;
            if (!this->directed && u != v)
            {
                matrix[v * this->vertices + u] += 1;
            }
        }

        return Matrix(matrix, this->vertices, this->vertices);
    }

    // Returns a V x E incidence matrix.
    // Undirected: each edge contributes +1 on both endpoint rows.
    // Directed: source contributes -1, destination contributes +1.
    Matrix incidence_matrix() const
    {
        int e = static_cast<int>(this->edge_list.size());
        std::vector<int> matrix(this->vertices * e, 0);

        for (int col = 0; col < e; ++col)
        {
            int u = this->edge_list[col].first;
            int v = this->edge_list[col].second;

            if (this->directed)
            {
                matrix[u * e + col] = -1;
                matrix[v * e + col] += 1;
            }
            else
            {
                matrix[u * e + col] += 1;
                matrix[v * e + col] += 1;
            }
        }

        return Matrix(matrix, this->vertices, e);
    }

    void visualize(int max_vertices_to_print = 40, int max_neighbors_per_vertex = 20) const
    {
        if (max_vertices_to_print <= 0)
        {
            max_vertices_to_print = 1;
        }
        if (max_neighbors_per_vertex <= 0)
        {
            max_neighbors_per_vertex = 1;
        }

        std::vector<std::vector<int>> adjacency(this->vertices);
        for (const auto &edge : this->edge_list)
        {
            int u = edge.first;
            int v = edge.second;

            adjacency[u].push_back(v);
            if (!this->directed && u != v)
            {
                adjacency[v].push_back(u);
            }
        }

        for (int i = 0; i < this->vertices; ++i)
        {
            std::sort(adjacency[i].begin(), adjacency[i].end());
        }

        std::cout << (this->directed ? "Directed" : "Undirected")
                  << " Graph: V=" << this->vertices
                  << ", E=" << edge_count() << "\n";

        int vertices_to_print = std::min(this->vertices, max_vertices_to_print);
        for (int v = 0; v < vertices_to_print; ++v)
        {
            std::cout << "[" << v << "] -> ";

            int degree = static_cast<int>(adjacency[v].size());
            int neighbors_to_print = std::min(degree, max_neighbors_per_vertex);

            if (neighbors_to_print == 0)
            {
                std::cout << "(none)";
            }
            else
            {
                for (int i = 0; i < neighbors_to_print; ++i)
                {
                    std::cout << adjacency[v][i];
                    if (i + 1 < neighbors_to_print)
                    {
                        std::cout << ", ";
                    }
                }
            }

            if (degree > neighbors_to_print)
            {
                std::cout << " ... (+" << (degree - neighbors_to_print) << " more)";
            }

            std::cout << "\n";
        }

        if (this->vertices > vertices_to_print)
        {
            std::cout << "... (" << (this->vertices - vertices_to_print)
                      << " more vertices not shown)\n";
        }
    }
};
