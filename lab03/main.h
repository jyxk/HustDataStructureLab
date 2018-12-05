/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-11-18 09:36:21
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-11-18 09:37:14
 * @Description: the header file of the BinTree system
 * @Email: jyxking007@gmail.com
 */

#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BinTree.h"

void PrintMenu(void);
/*
 * Function Name: PrintMenu
 * Parameter: None
 * Return: None
 * Use: print the menu
 */


void LoadData(PtrToSet TreeSet);
/*
 * Function Name: LoadData
 * Parameter: PtrToSet
 * Return Status(int)
 * Use: load data
 */

void SaveData(PtrToSet TreeSet);
/*
 * Function Name: SaveData
 * Parameter: PtrToSet
 * Return: Status(int)
 * Use: save data
 */

#endif