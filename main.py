from collections import deque


def bfs_with_parents(graph, start):
    visited = {start}
    distance = {start: 0}
    parent = {start: None}
    queue = deque([start])

    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                distance[neighbor] = distance[node] + 1
                parent[neighbor] = node
                queue.append(neighbor)

    # находим самую удалённую вершину
    farthest_node = max(distance, key=distance.get)
    return farthest_node, distance, parent


def find_diameter_path(graph):
    # Шаг 1: находим вершину v, которая дальше всего от произвольной вершины
    u = next(iter(graph))  # берем любую вершину
    v, _, _ = bfs_with_parents(graph, u)

    # Шаг 2: из v находим самую удалённую вершину w и сохраняем предков
    w, _, parent = bfs_with_parents(graph, v)

    # Шаг 3: восстанавливаем путь от w до v
    path = []
    current = w
    while current is not None:
        path.append(current)
        current = parent[current]

    path.reverse()  # путь от v до w
    return path


# Пример графа
graph = {
    "A": ["B", "C"],
    "B": ["A", "D"],
    "C": ["A", "D"],
    "D": ["B", "C", "E"],
    "E": ["D"],
}

diameter_path = find_diameter_path(graph)
print("Путь, соответствующий диаметру графа:", diameter_path)
print("Длина пути (диаметр):", len(diameter_path) - 1)
