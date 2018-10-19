/*
 * @Author: Xiuxu Jin(jyxk)
 * @Date: 2018-10-19 09:04:01
 * @LastEditors: Xiuxu Jin
 * @LastEditTime: 2018-10-19 09:04:01
 * @Description: file content
 * @Email: jyxking007@gmail.com
 */

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