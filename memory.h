//
// Created by Anas on 30/9/2022.
//

#ifndef ASSEMBLY_DO_MEMORY_H
#define ASSEMBLY_DO_MEMORY_H


#include "common.h"
#include "object.h"


void* reallocate(void* pointer, size_t oldSize, size_t newSize);
//< grow-array
//> Garbage Collection mark-object-h
void markObject(Obj* object);
//< Garbage Collection mark-object-h
//> Garbage Collection mark-value-h
void markValue(Value value);
//< Garbage Collection mark-value-h
//> Garbage Collection collect-garbage-h
void collectGarbage();
//< Garbage Collection collect-garbage-h
//> Strings free-objects-h
void freeObjects();
//< Strings free-objects-h
#endif //ASSEMBLY_DO_MEMORY_H
