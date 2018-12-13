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

}

/**
 *
 * @param G
 * @return
 */
Status DestroyGraph(PtrToGraph G);

/**
 *
 * @param G
 * @param u
 * @return
 */
int LocateVex(PtrToGraph G, PtrToVertex u);

/**
 *
 * @param G
 * @param v
 * @return
 */
int GetVex(PtrToGraph G, PtrToVertex v);

/**
 *
 * @param G
 * @param v
 * @param value
 * @return
 */
Status PutVex(PtrToGraph G, PtrToVertex v, int value);

/**
 *
 * @param G
 * @param target_arc
 * @param weight
 * @return
 */
Status SetWeight(PtrToGraph G, PtrToArc target_arc, int weight);

/**
 *
 * @param G
 * @param v
 * @return
 */
PtrToVertex FristAdjVex(PtrToGraph G, PtrToVertex v);

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
PtrToVertex NextAdjVex(PtrToGraph G, PtrToVertex v, PtrToVertex w);

/**
 *
 * @param G
 * @param v
 * @return
 */
Status InsertVex(PtrToGraph G, PtrToVertex v);

/**
 *
 * @param G
 * @param v
 * @return
 */
Status DeleteVex(PtrToGraph G, PtrToVertex v);

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
Status InsertArc(PtrToGraph G, PtrToVertex v, PtrToVertex w ,int weight);

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
Status DeleteArc(PtrToGraph G, PtrToVertex v, PtrToVertex w);

/**
 *
 * @param G
 * @return
 */
Status DFSTraverse(PtrToGraph G);

/**
 *
 * @param G
 * @return
 */
Status BFSTraverse(PtrToGraph G);