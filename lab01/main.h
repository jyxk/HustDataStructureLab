#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayList.h"
void PrintMenu(void);
    /*
     * Function Name: PrintMenu
     * Parameter: None
     * Return: None
     * Use: print the menu 
     */

Status LoadData(PtrToSet ListSet);
/*
 * Function Name: LoadData
 * Parameter: PtrToSet 
 * Return Status(int)
 * Use: load data
 */

Status SaveData(PtrToSet list_set);
/* 
 * Function Name: SaveData
 * Parameter: PtrToSet
 * Return: Status(int)
 * Use: save data
 */

#endif