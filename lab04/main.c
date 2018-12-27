#include "main.h"

void PrintMenu(void) {
    /*
     * Function Name: PrintMenu
     * Parameter: None
     * Return: None
     * Use: print the menu
     */

    printf("\n+-----------------------------------------------------+\n");
    printf("|                jyxk's Graph demo                    |\n");
    printf("|                                                     |\n");
    printf("|                   Function List:                    |\n");
    printf("|                                                     |\n");
    printf("|      1.CreateGraph            2.DestroyGraph        |\n");
    printf("|      3.LocateVex              4.GetVexValue         |\n");
    printf("|      5.SetVexValue            6.SetArcWeight        |\n");
    printf("|      7.FirstAdjVex            8.NextAdjVex          |\n");
    printf("|      9.InsertVex             10.DeleteVex           |\n");
    printf("|     11.InsertArc             12.DeleteArc           |\n");
    printf("|     13.DFSTraverse           14.BFSTraverse         |\n");
    printf("|     15.ListGraph             16.NewLocateVex        |\n");
    printf("|                                                     |\n");
    printf("| Enter the num of the function that you wanna see.   |\n");
    printf("| Enter 0 to exit this demo system.                   |\n");
    printf("|                                                     |\n");
    printf("|                                                     |\n");
    printf("| CopyLeft 2018 Xiuxu Jin                             |\n");
    printf("|                                    Power by:jyxk    |\n");
    printf("+-----------------------------------------------------+\n");
    printf("\n");
}

void loadData(GraphSet *graph_set) {

    FILE *fp = fopen("GraphDataBase", "rb");
    if (fp == NULL)
        return ;

    Graph graphs;
    PtrToGraph graph = &graphs;
    graph->next = NULL;

    int size = 0xff;
    while (1) {
        GraphStore definition;
        PtrToGraph tmp_graph = NULL;

        size = fread(&definition, sizeof(GraphStore), 1, fp);
        if (size == 0)
            break;

        tmp_graph = (PtrToGraph)malloc(sizeof(Graph));
        memset(tmp_graph, 0, sizeof(Graph));

        definition.v_indexs = (int *)malloc(sizeof(int) * definition.vertex_num);
        definition.v_values = (int *)malloc(sizeof(int) * definition.vertex_num);
        definition.a_matrix = (int *)malloc(sizeof(int) * definition.vertex_num*definition.vertex_num);
        fread(definition.v_indexs, sizeof(int) * definition.vertex_num, 1, fp);
        fread(definition.v_values, sizeof(int) * definition.vertex_num, 1, fp);
        fread(definition.a_matrix, sizeof(int) * definition.vertex_num*definition.vertex_num, 1, fp);
        CreateGraph(tmp_graph, definition.kind, definition.vertex_num, definition.arc_num, definition.v_indexs, definition.v_values, definition.a_matrix);

        tmp_graph->id = definition.id;
        tmp_graph->next = NULL;
        graph->next = tmp_graph;
        graph = graph->next;

    }

    graph_set->head = graphs.next;

    fclose(fp);

}

void traverseSave(PtrToGraph G, int *indexs, int *values, int *matrix, int size) {

    PtrToVertex node = G->first_vertex;
    int pos = 0;
    while (node != NULL) {
        indexs[pos] = node->index;
        values[pos] = node->value;
        PtrToArc arc = node->first_arc;

        while (arc != NULL) {
            matrix[pos*size + get_vertex_pos(G, arc->vertex)] = arc->weight;
            arc = arc->next;
        }
        pos++;
        node = node->next;
    }
}

void saveData(GraphSet *graph_set) {

    FILE *fp = fopen("GraphDataBase", "wb");
    if (fp == NULL)
        return ;

    PtrToGraph graph = graph_set->head;
    while (graph != NULL) {
        GraphStore definition;
        definition.id = graph->id;
        definition.kind = graph->kind;
        definition.vertex_num = graph->vertex_num;
        definition.arc_num = graph->arc_num;
        definition.v_indexs = (int *)malloc(sizeof(int) * definition.vertex_num);
        definition.v_values = (int *)malloc(sizeof(int) * definition.vertex_num);
        definition.a_matrix = (int *)malloc(sizeof(int) * definition.vertex_num*definition.vertex_num);
        memset(definition.a_matrix, 0, sizeof(int) * definition.vertex_num*definition.vertex_num);
        traverseSave(graph, definition.v_indexs, definition.v_values, definition.a_matrix, definition.vertex_num);
        fwrite(&definition, sizeof(GraphStore), 1, fp);
        fwrite(definition.v_indexs, sizeof(int) * definition.vertex_num, 1, fp);
        fwrite(definition.v_values, sizeof(int) * definition.vertex_num, 1, fp);
        fwrite(definition.a_matrix, sizeof(int) * definition.vertex_num*definition.vertex_num, 1, fp);
        graph = graph->next;
    }

    fclose(fp);
}

int main(void) {

    int function_flag = 0xff;

    while (function_flag != 0) {
        PrintMenu();
        scanf("%d", &function_flag);
        GraphSet graph_set;
        graph_set.head = NULL;
        loadData(&graph_set);

        int id, kind, v_num, a_num, index, value, src, dst, weight;
        PtrToGraph G = NULL;

        switch (function_flag) {
            case 1:
                printf("/*\n");
                printf(" * Function Name: creat_graph\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int v_num, int kind,\n");
                printf(" * int a_num, int *v_indexs, int *v_values, int *a_matrix\n");
                printf(" * Return: int(status)\n");
                printf(" * Use: create a graph\n");
                printf(" */\n");
                printf("\n");
                printf("                                              Format: id kind v_num a_num\n");
                printf("Then, enter the graph id, kind, vertex num, arc num : ");

                scanf("%d %d %d %d", &id, &kind, &v_num, &a_num);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G != NULL) {
                    printf("Creat error, this graph is already exists!\n");
                }
                else {
                    int *v_indexs = (int*)malloc(sizeof(int) * v_num);
                    int *v_values = (int*)malloc(sizeof(int) * v_num);
                    int *a_matrix = (int*)malloc(sizeof(int) * v_num * v_num);
                    int legal_flag = 0;
                    printf("Please enter the node info (Format: index value):\n");
                    for (int i = 0; i < v_num; i++) { scanf("%d %d", &v_indexs[i], &v_values[i]); }
                    printf("please enter the adjacency matrix:\n");
                    for (int i = 0; i < v_num; i++) {
                        for (int j = 0; j < v_num; j++) { scanf("%d", a_matrix + i * v_num + j); }
                    }

                    for (int i = 0; i < v_num; i++) {
                        if (*(a_matrix + i * v_num + i) != 0)
                            legal_flag  = 1;
                    }
                    if (legal_flag) {
                        printf("You cannot create a graph which has a self-loop!\n");
                        break;
                    }
                    Graph new_G;
                    new_G.next = NULL;
                    CreateGraph(&new_G, kind, v_num, a_num, v_indexs, v_values, a_matrix);
                    printf("Create graph %d succeed!\n", id);
                    new_G.id = id;
                    new_G.next = graph_set.head;
                    graph_set.head = &new_G;
                }

                printf("\n");
                break;

            case 2:
                printf("/*\n");
                printf(" * Function Name: destory_graph\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G\n");
                printf(" * Return: int(status)\n");
                printf(" * Use: destory a graph\n");
                printf(" */\n");
                printf("\n");
                printf("Then, enter the graph id: ");

                scanf("%d", &id);
                G = graph_set.head;
                if (G == NULL) {
                    printf("Destory error, this graph is not exist!\n");
                    break;
                }
                if (G->id == id) {
                    graph_set.head = graph_set.head->next;
                    DestroyGraph(G);
                    printf("Graph %d has been delected!", id);
                    printf("\n");
                    break;
                }
                else {
                    while (G != NULL && G->next != NULL) {
                        if (G->next->id == id)
                            break;
                        G = G->next;
                    }
                }
                if (G->next == NULL) {
                    printf("Destory error, this graph is not exists!\n");
                }
                else {
                    Graph *to_be_del = G->next;
                    G->next = G->next->next;
                    DestroyGraph(to_be_del);
                    printf("Graph %d has been deleted!\n", id);
                }

                printf("\n");
                break;

            case 3:
                printf("/*\n");
                printf(" * Function Name: locate_vex\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph *G, int value\n");
                printf(" * Return: int(the index)\n");
                printf(" * Use: find a vertex in graph\n");
                printf(" */\n");
                printf("\n");
                printf("                                   Format: id value\n");
                printf("Then, enter the graph id and vertex value: ");

                scanf("%d %d", &id, &value);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    int index = LocateVex(G, value);
                    if (index != NOT_EXIST) {
                        printf("The index is %d.\n", index);
                    }
                    else {
                        printf("The vertex is not in the graph!\n");
                    }
                }

                printf("\n");
                break;

            case 4:
                printf("/*\n");
                printf(" * Function Name: get_vex_value\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph *G, int index\n");
                printf(" * Return: int(the index)\n");
                printf(" * Use: find a value of a vertex\n");
                printf(" */\n");
                printf("\n");
                printf("                                   Format: id index\n");
                printf("Then, enter the graph id and vertex index: ");

                scanf("%d %d", &id, &index);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    int value = GetVex(G, index);
                    if (value != NOT_FOUND) {
                        printf("The value of %d is %d.\n", index, value);
                    }
                    else {
                        printf("The vertex is not in the Graph!\n");
                    }
                }

                printf("\n");
                break;

            case 5:
                printf("/*\n");
                printf(" * Function Name: set_vex_value\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int index, int value\n");
                printf(" * Return: int(the index)\n");
                printf(" * Use: set a vertex's value\n");
                printf(" */\n");
                printf("\n");
                printf("                                          Format: id index value\n");
                printf("Then, enter the graph id, vertex index and value: ");

                scanf("%d %d %d", &id, &index, &value);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (PutVex(G, index, value) == OK) {
                        printf("Set value %d of index %d succeed!\n", value, index);
                    }
                    else {
                        printf("Error, the index %d is not exists!\n", index);
                    }
                }

                printf("\n");
                break;

            case 6:
                printf("/*\n");
                printf(" * Function Name: set_arc_weight\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph *G, int src_index, int dst_index, int weight\n");
                printf(" * Return: int(the index)\n");
                printf(" * Use: set an arc's weight\n");
                printf(" */\n");
                printf("\n");
                printf("                                                     Format: id src_index dst_index weight\n");
                printf("Then, enter the graph id, src and dst index, and arc weight: ");

                scanf("%d %d %d %d", &id, &src, &dst, &weight);
                Arc arc;
                arc.src_index = src;
                arc.dst_index = dst;
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (SetWeight(G, arc, weight) == OK) {
                        printf("Set the arc between %d and %d weight %d succeed!\n", src, dst, weight);
                    }
                    else {
                        printf("Set error, this arc is not exists!\n");
                    }
                }

                printf("\n");
                break;

            case 7:
                printf("/*\n");
                printf(" * Function Name: first_adj_vex\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int index\n");
                printf(" * Return: vertex_node*(the first vertex)\n");
                printf(" * Use: get the fitst adjacency vertex\n");
                printf(" */\n");
                printf("\n");
                printf("Format: id index\n");
                printf("Then, enter the graph id and index: ");

                scanf("%d %d", &id, &index);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    PtrToVertex first_adj_vertex = FirstAdjVex(G, index);
                    if (first_adj_vertex == NULL) {
                        printf("Error, the required vertex is not exists!\n");
                    }
                    else {
                        printf("The first adjacency vertex of %d is %d.\n", index, first_adj_vertex->index);
                    }
                }

                printf("\n");
                break;

            case 8:
                printf("/*\n");
                printf(" * Function Name: next_adj_vex\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int index, int now_index\n");
                printf(" * Return: vertex_node*(the next vertex)\n");
                printf(" * Use: get the next adjacency vertex\n");
                printf(" */\n");
                printf("\n");
                printf("                                       Format: id index now_index\n");
                printf("Then, enter the graph id, index and now index: ");

                int now_index;
                scanf("%d %d %d", &id, &index, &now_index);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    PtrToVertex next_adj_vertex = NextAdjVex(G, index, now_index);
                    if (next_adj_vertex == NULL) {
                        printf("Error, the required vertex is not exists!\n");
                    }
                    else {
                        printf("The nex adjacency vertex is %d.\n", next_adj_vertex->index);
                    }
                }

                printf("\n");
                break;

            case 9:
                printf("/*\n");
                printf(" * Function Name: insert_vex\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph *G, int index, int value\n");
                printf(" * Return: int(statue)\n");
                printf(" * Use: insert a vertex in graph\n");
                printf(" */\n");
                printf("\n");
                printf("                                   Format: id index value\n");
                printf("Then, enter the graph id, index and value: ");

                scanf("%d %d %d", &id, &index, &value);
                Vertex vertex;
                vertex.index = index;
                vertex.value = value;
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (InsertVex(G, vertex) == OK) {
                        printf("Insert vertex %d succeed!\n", index);
                    }
                    else {
                        printf("Error, please check your input!\n");
                    }
                }

                printf("\n");
                break;

            case 10:
                printf("/*\n");
                printf(" * Function Name: delete_vex\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int index\n");
                printf(" * Return: int(statue)\n");
                printf(" * Use: delete a vertex in graph\n");
                printf(" */\n");
                printf("\n");
                printf("                            Format: id index\n");
                printf("Then, enter the graph id and index: ");

                scanf("%d %d", &id, &index);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (DeleteVex(G, index) == OK) {
                        printf("Delete vertex %d succeed!\n", index);
                    }
                    else {
                        printf("Error, this vertex is not exists!\n");
                    }
                }

                printf("\n");
                break;

            case 11:
                printf("/*\n");
                printf(" * Function Name: insert_arc\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int src_vex, int dst_vex, int weight\n");
                printf(" * Return: int(statue)\n");
                printf(" * Use: insert an arc in graph\n");
                printf(" */\n");
                printf("\n");
                printf("                                                 Format: id src_index dst_index weight\n");
                printf("Then, enter the graph id, src and dst index, and weight: ");

                scanf("%d %d %d %d", &id, &src, &dst, &weight);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (InsertArc(G, src, dst, weight) == OK) {
                        printf("Insert arc between %d and %d weight %d succeed!\n", src, dst, weight);
                    }
                    else {
                        printf("Error, please check your input!\n");
                    }
                }

                printf("\n");\
        break;

            case 12:
                printf("/*\n");
                printf(" * Function Name: delete_arc\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G, int src_vex, int dst_vex\n");
                printf(" * Return: int(statue)\n");
                printf(" * Use: delete an arc in graph\n");
                printf(" */\n");
                printf("\n");
                printf("                                     Format: id src_index dst_index\n");
                printf("Then, enter the graph id, src and dst index: ");

                scanf("%d %d %d", &id, &src, &dst);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (DeleteArc(G, src, dst) == OK) {
                        printf("Delete the arc between %d and %d succeed!\n", src, dst);
                    }
                    else {
                        printf("Error, this arc is not exists!\n");
                    }
                }

                printf("\n");
                break;

            case 13:
                printf("/*\n");
                printf(" * Function Name: dfs_traverse\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G\n");
                printf(" * Return: int(statue)\n");
                printf(" * Use: Depth_First Search traverse the graph\n");
                printf(" */\n");
                printf("\n");
                printf("Then, enter the graph id: ");

                scanf("%d", &id);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (DFSTraverse(G) == ERROR)
                        printf("Error, this graph is empty!\n");
                }

                printf("\n");
                break;

            case 14:
                printf("/*\n");
                printf(" * Function Name: bfs_traverse\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph &G\n");
                printf(" * Return: int(statue)\n");
                printf(" * Use: Broadth_First Search traverse the graph\n");
                printf(" */\n");
                printf("\n");
                printf("Then, enter the graph id: ");

                scanf("%d", &id);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    if (BFSTraverse(G) == ERROR)
                        printf("Error, this graph is empty!\n");
                }

                printf("\n");
                break;

            case 15:
                G = graph_set.head;
                while (G != NULL) {
                    printf("ID: %d\n", G->id);
                    G = G->next;
                }

                printf("\n");
                break;

            case 16:
                printf("/*\n");
                printf(" * Function Name: new_locate_vex\n");
                printf(" * Module: Data structures\n");
                printf(" * Parameter: graph *G, int value\n");
                printf(" * Return: int(the index)\n");
                printf(" * Use: find a vertex in graph\n");
                printf(" */\n");
                printf("\n");
                printf("                                   Format: id index\n");
                printf("Then, enter the graph id and vertex index: ");

                scanf("%d %d", &id, &index);
                G = graph_set.head;
                while (G != NULL) {
                    if (G->id == id)
                        break;
                    G = G->next;
                }
                if (G == NULL) {
                    printf("Error, this graph is not exists!\n");
                }
                else {
                    int fxxkme = NewLocateVex(G, index);
                    if (fxxkme != NOT_EXIST) {
                        printf("The location is %d.\n", fxxkme);
                    }
                    else {
                        printf("The vertex is not in the graph!\n");
                    }
                }

                printf("\n");
                break;

            case 0:
                printf("Thanks for using my demo system!\n");
                break;

            default:
                printf("You entered the wrong num, please re-enter the num.\n");
                break;
        }

        saveData(&graph_set);
    }

    return 0;
}