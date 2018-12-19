//
// Created by jyxk on 18-12-13.
//

#include "Graph.h"
#include "queue.h"

PtrToVertex search_graph(PtrToGraph G, int index) {

    PtrToVertex node = G->first_vertex;
    while (node != NULL) {
        if (node->index == index)
            break;
        node = node->next;
    }
    return node;
}

PtrToArc search_arc(PtrToGraph G, int src, int dst) {

    PtrToVertex src_node = search_graph(G, src);
    if (src_node == NULL)
        return NULL;
    PtrToArc arc = src_node->first_arc;
    while (arc != NULL) {
        if (arc->vertex == dst)
            break;
        arc = arc->next;
    }
    return arc;
}

/**
 *
 * @param G
 * @param kind
 * @param v_num
 * @param a_num
 * @param v_index
 * @param v_value
 * @param a_matrix
 * @return
 */
Status CreateGraph(PtrToGraph G, int kind, int v_num, int a_num, int *v_index, int *v_value, int *a_matrix) {
    int i, j;
    int status = OK;
    G->kind = kind;
    Vertex vertex;
    // insert vertexs
    for(i = 0; i < v_num; i++) {
        vertex.index = v_index[i], vertex.value = v_value[i];
        status = InsertVex(G, vertex);
    }
    // insert arcs
    for (i = 0; i < v_num; i++) {
        for (j = 0; j < v_num; j++) {
            if (*(a_matrix + i * v_num + j) != 0) {
                InsertArc(G, v_index[i], v_index[j], *(a_matrix + i * v_num + j));
            }
        }
    }
    G->vertex_num = v_num;
    G->arc_num = a_num;
    return status;
}

/**
 *
 * @param G
 * @return
 */
Status DestroyGraph(PtrToGraph G) {

    PtrToVertex node = G->first_vertex;
    while (node != NULL) {
        PtrToVertex tmp = node;
        node = node ->next;
        free(tmp);
    }

    if (G->first_vertex != NULL)
        return ERROR;

    free(G);
    if (G != NULL)
        return ERROR;
    return OK;
}

/**
 *
 * @param G
 * @param u
 * @return
 */
int LocateVex(PtrToGraph G, int value) {

    PtrToVertex node = G->first_vertex;
    while (node != NULL) {
        if (node->value == value)
            return node->index;
        node = node->next;
    }
    return NOT_EXIST;
}

/**
 *
 * @param G
 * @param v
 * @return
 */
int GetVex(PtrToGraph G, int index) {

    PtrToVertex node = G->first_vertex;

    while (node != NULL) {
        if (node->index == index)
            return node->value;
        node = node->next;
    }
    return NOT_FOUND;

}

/**
 *
 * @param G
 * @param v
 * @param value
 * @return
 */
Status PutVex(PtrToGraph G, int index, int value) {

    PtrToVertex node = G->first_vertex;
    while (node != NULL) {
        if (node->index == index) {
            node->value = value;
            break;
        }
        node = node->next;
    }
    if (node == NULL)
        return ERROR;
    else
        return OK;
}

/**
 *
 * @param G
 * @param target_arc
 * @param weight
 * @return
 */
Status SetWeight(PtrToGraph G, Arc target_arc, int weight) {

    PtrToArc arc = search_arc(G, target_arc.src_index, target_arc.dst_index);
    if (arc == NULL)
        return ERROR;
    arc->weight = weight;

    // if the graph is undirected, add a arc
    if (G->kind == UNDIRECTED_GRAPH || G->kind == UNDIRECTED_NET) {
        arc = search_arc(G, target_arc.dst_index, target_arc.src_index);
        arc->weight = weight;
    }
    return OK;
}

/**
 *
 * @param G
 * @param v
 * @return
 */
PtrToVertex FirstAdjVex(PtrToGraph G, int index) {

    PtrToVertex node = G->first_vertex;
    PtrToVertex frist_adj_vertex = NULL;
    while (node != NULL) {
        if (node->index == index) {
            if (node->first_arc != NULL)
                frist_adj_vertex = search_graph(G, node->first_arc->vertex);
            break;
        }
        node = node->next;
    }
    return frist_adj_vertex;
}

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
PtrToVertex NextAdjVex(PtrToGraph G, int v_index, int w_index) {

    if (v_index == w_index)
        FirstAdjVex(G, v_index);

    PtrToVertex node = G->first_vertex;
    PtrToVertex next_adj_vertex = NULL;
    while (node != NULL) {
        if (node->index == v_index) {
            PtrToArc arc = node->first_arc;
            while (arc != NULL) {
                if (arc->vertex == w_index && arc->next != NULL) {
                    next_adj_vertex = search_graph(G, arc->next->vertex);
                    break;
                }
                arc = arc->next;
            }
            break;
        }
        node = node->next;
    }
    return next_adj_vertex;
}

/**
 *
 * @param G
 * @param v
 * @return
 */
Status InsertVex(PtrToGraph G, Vertex v) {

    if (search_graph(G, v.index) != NULL)
        return ERROR;
    PtrToVertex new_node = (PtrToVertex)malloc(sizeof(VertexNode));
    if (new_node == NULL)
        return ERROR;

    G->vertex_num++;
    new_node->index = v.index;
    new_node->value = v.value;
    new_node->next = NULL;
    new_node->first_arc = NULL;

    //insert
    if (G->first_vertex == NULL) {
        G->first_vertex = new_node;
    }
    else {
        PtrToVertex node = G->first_vertex;
        while (node->next != NULL)
            node = node->next;
        node->next = new_node;
    }
    return OK;
}

/**
 *
 * @param G
 * @param v
 * @return
 */
Status DeleteVex(PtrToGraph G, int v_index) {

    if (search_graph(G, v_index) == NULL)
        return ERROR;
    G->vertex_num--;

    PtrToVertex node = G->first_vertex;
    while (node != NULL) {
        PtrToArc arc = node->first_arc;
        if (arc == NULL) {
            node = node->next;
            continue;
        }

        if (arc->vertex == v_index) {
            node->first_arc = node->first_arc->next;
            free(arc);
            G->arc_num--;
            node = node->next;
            continue;
        }

        while (arc->next != NULL) {
            if (arc->next->vertex == v_index) {
                PtrToArc tmp_arc = arc->next;
                arc->next = arc->next->next;
                free(tmp_arc);
                G->arc_num--;
                break;
            }
            arc = arc->next;
        }
        node = node->next;
    }

    node = G->first_vertex;

    if (node->index == v_index) {
        PtrToArc arc = node->first_arc;
        while (arc != NULL) {
            PtrToArc tmp_arc = arc;
            arc = arc->next;
            free(tmp_arc);
            G->arc_num--;
        }

        G->first_vertex = G->first_vertex->next;
        free(node);
        return OK;
    }

    while (node != NULL && node->next != NULL) {

        if (node->next->index == v_index) {
            PtrToVertex tmp_node = node->next;
            PtrToArc arc = tmp_node->first_arc;
            while (arc != NULL) {
                PtrToArc tmp_arc = arc;
                arc = arc->next;
                free(tmp_arc);
                G->arc_num--;
            }
            node->next = node->next->next;
            free(tmp_node);
        }
        node = node->next;
    }
    return OK;
}

void add_an_arc(PtrToVertex src_vex, int dst_vex, int weight) {
    PtrToArc new_arc = (PtrToArc)malloc(sizeof(ArcNode));
    new_arc->vertex = dst_vex;
    new_arc->weight = weight;
    new_arc->next = NULL;

    if (src_vex->first_arc == NULL)
        src_vex->first_arc = new_arc;
    else {
        PtrToArc arc = src_vex->first_arc;
        while (arc->next != NULL)
            arc = arc->next;
        arc->next = new_arc;
    }
}

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
Status InsertArc(PtrToGraph G, int src_index, int dst_index, int weight) {

    PtrToVertex src_vertex = search_graph(G, src_index);
    PtrToVertex dst_vertex = search_graph(G, dst_index);
    if (src_vertex == NULL || dst_vertex == NULL)
        return ERROR;
    if (search_arc(G, src_index, dst_index) != NULL)
        return ERROR;

    if (G->kind == UNDIRECTED_GRAPH || G->kind == UNDIRECTED_NET) {
        add_an_arc(dst_vertex, src_index, weight);
        G->arc_num++;
    }
    add_an_arc(src_vertex, dst_index, weight);
    G->arc_num++;
    return OK;
}

void del_arc(PtrToVertex src_vertex, int dst_vex) {

    if (src_vertex->first_arc->vertex == dst_vex) {
        PtrToArc tmp_arc = src_vertex->first_arc;
        src_vertex->first_arc = src_vertex->first_arc->next;
        free(tmp_arc);
    }
    else {
        PtrToArc arc = src_vertex->first_arc;
        while (arc->next != NULL) {
            if (arc->next->vertex == dst_vex) {
                PtrToArc tmp_arc = arc->next;
                arc->next = arc->next->next;
                free(tmp_arc);
            }
            arc = arc->next;
        }
    }
}

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
Status DeleteArc(PtrToGraph G, int src_index, int dst_index) {

    PtrToVertex src_node = search_graph(G, src_index);
    PtrToVertex dst_node = search_graph(G, dst_index);
    if (src_node == NULL || dst_node == NULL)
        return ERROR;
    if (search_arc(G, src_index, dst_index) == NULL)
        return ERROR;

    if (G->kind == UNDIRECTED_NET || G->kind == UNDIRECTED_GRAPH) {
        del_arc(dst_node, dst_index);
        G->arc_num--;
    }
    del_arc(src_node, dst_index);
    G->arc_num--;
    return OK;
}

int get_vertex_pos(PtrToGraph G, int index) {

    int pos = 0;
    PtrToVertex node = G->first_vertex;
    while (node->index != index) {
        pos++;
        node = node->next;
    }
    return pos;
}

void DFS(PtrToGraph G, PtrToVertex vertex, int *visit, int pos) {

    visit[pos] = 1;
    printf("Index: %d, Value: %d\n", vertex->index, vertex->value);
    PtrToVertex node = NULL;
    for (node = FirstAdjVex(G, vertex->index); node != NULL; node = NextAdjVex(G, vertex->index, node->index)) {
        int pos = get_vertex_pos(G, node->index);
        if (!visit[pos])
            DFS(G, node, visit, pos);
    }
}

/**
 *
 * @param G
 * @return
 */
Status DFSTraverse(PtrToGraph G) {

    PtrToVertex node = G->first_vertex;
    if (node == NULL)
        return ERROR;
    int pos = 0;
    int *visit = (int *)malloc(sizeof(int) * G->vertex_num);
    memset(visit, 0, sizeof(int) * G->vertex_num);
    printf("Graph: %d\n", G->id);
    printf("DFS traverse:\n");
    printf("Vertex num: %d\n", G->vertex_num);
    while (node != NULL) {
        if (!visit[pos])
            DFS(G, node, visit, pos);
        node = node->next;
        pos++;
    }
    return OK;
}

/**
 *
 * @param G
 * @return
 */
Status BFSTraverse(PtrToGraph G) {

    PtrToVertex traverse_node = G->first_vertex;
    PtrToVertex node = NULL;
    if (traverse_node == NULL)
        return ERROR;
    int pos = 0;
    int *visit = (int *)malloc(sizeof(int) * G->vertex_num);
    memset(visit, 0, sizeof(int) * G->vertex_num);
    Queue node_queue = CreateQueue(20);
    printf("Graph: %d\n", G->id);
    printf("BFS traverse:\n");
    printf("Vertex num: %d\n", G->vertex_num);

    while (traverse_node != NULL) {
        if (!visit[pos]) {
            visit[pos] = 1;
            Enqueue(traverse_node, node_queue);
            while (!IsQueueEmpty(node_queue)) {
                node = FrontAndDequeue(node_queue);
                printf("Index: %d, value: %d\n", node->index, node->value);
                PtrToVertex a_node = NULL;
                for (a_node = FirstAdjVex(G, node->index); a_node != NULL; a_node = NextAdjVex(G, node->index, a_node->index)) {
                    int next_pos = get_vertex_pos(G, a_node->index);
                    if (!visit[next_pos]) {
                        visit[next_pos] = 1;
                        Enqueue(a_node, node_queue);
                    }
                }
            }
        }
        traverse_node = traverse_node->next;
        pos++;
    }
    return OK;
}