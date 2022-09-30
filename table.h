//
// Created by Anas on 30/9/2022.
//

#ifndef ASSEMBLY_DO_TABLE_H
#define ASSEMBLY_DO_TABLE_H

#include "common.h"
#include "value.h"
#include "object.h"
//> entry

typedef struct {
    ObjString* key;
    Value value;
} Entry;
//< entry

typedef struct {
    int count;
    int capacity;
    Entry* entries;
} Table;


void initTable(Table* table);

void freeTable(Table* table);

bool tableGet(Table* table, ObjString* key, Value* value);

bool tableSet(Table* table, ObjString* key, Value value);

bool tableDelete(Table* table, ObjString* key);

void tableAddAll(Table* from, Table* to);

ObjString* tableFindString(Table* table, const char* chars,
                           int length, uint32_t hash);

void tableRemoveWhite(Table* table);

void markTable(Table* table);


#endif //ASSEMBLY_DO_TABLE_H
