//
// Created by jyxk on 18-12-13.
//

#ifndef LAB04_GRAPH_H
#define LAB04_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define OK 0
#define ERROR 1

#define NOT_FOUND 0xff
#define NOT_EXIST 0xab

#define DIRECTED_GRAPH 0
#define UNDIRECTED_GRAPH 1
#define DIRECTED_NET 2
#define UNDIRECTED_NET 3

struct ArcNode;
struct VertexNode;
struct Graph;
struct GraphSet;

typedef struct ArcNode* PtrToArc;
typedef struct VertexNode* PtrToVertex;
typedef struct Graph* PtrToGraph;

typedef int Status;
typedef int Bool;
typedef int ElementType;

typedef struct ArcNode {
    int vertex;
    struct ArcNode* next;
    int weight;
} ArcNode;

typedef struct VertexNode {
    int index;
    ElementType value;
    PtrToArc first_arc;
    struct VertexNode* next;
}VertexNode;

typedef struct Graph {
    int id;
    PtrToVertex first_vertex;
    int vertex_num;
    int arc_num;
    int kind;
    struct Graph* next;
} Graph;

typedef struct GraphSet {
    PtrToGraph head;
} GraphSet;

typedef struct Arc {
    int src_index;
    int dst_index;
} Arc;

typedef struct Vertex {
    int index;
    ElementType value;
} Vertex;

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
Status CreateGraph(PtrToGraph G, int kind, int v_num, int a_num, int *v_index, int *v_value, int *a_matrix);

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
int LocateVex(PtrToGraph G, int value);

/**
 *
 * @param G
 * @param v
 * @return
 */
int GetVex(PtrToGraph G, int index);

/**
 *
 * @param G
 * @param v
 * @param value
 * @return
 */
Status PutVex(PtrToGraph G, int index, int value);

/**
 *
 * @param G
 * @param target_arc
 * @param weight
 * @return
 */
Status SetWeight(PtrToGraph G, Arc target_arc, int weight);

/**
 *
 * @param G
 * @param v
 * @return
 */
PtrToVertex FirstAdjVex(PtrToGraph G, int index);

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
PtrToVertex NextAdjVex(PtrToGraph G, int v_index, int w_index);

/**
 *
 * @param G
 * @param v
 * @return
 */
Status InsertVex(PtrToGraph G, Vertex v);

/**
 *
 * @param G
 * @param v
 * @return
 */
Status DeleteVex(PtrToGraph G, int v_index);

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
Status InsertArc(PtrToGraph G, int src_index, int dst_index, int weight);

/**
 *
 * @param G
 * @param v
 * @param w
 * @return
 */
Status DeleteArc(PtrToGraph G, int src_index, int dst_index);

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


#endif //LAB04_GRAPH_H
