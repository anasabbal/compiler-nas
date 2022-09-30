//
// Created by Anas on 30/9/2022.
//

#ifndef ASSEMBLY_DO_OBJECT_H
#define ASSEMBLY_DO_OBJECT_H

#include "common.h"
//> Calls and Functions object-include-chunk
#include "chunk.h"
//< Calls and Functions object-include-chunk
//> Classes and Instances object-include-table
#include "table.h"
//< Classes and Instances object-include-table
#include "value.h"


typedef enum {
    OBJ_BOUND_METHOD,
    OBJ_CLASS,
    OBJ_CLOSURE,
    OBJ_FUNCTION,
    OBJ_INSTANCE,
    OBJ_NATIVE,
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    bool isMarked;
    struct Obj* next;
};

typedef struct {
    Obj obj;
    int arity;
    int upvalueCount;
    Chunk chunk;
    ObjString* name;
} ObjFunction;

typedef Value (*NativeFn)(int argCount, Value* args);

typedef struct {
    Obj obj;
    NativeFn function;
} ObjNative;

struct ObjString {
    Obj obj;
    int length;
    char* chars;
    uint32_t hash;
};
typedef struct ObjUpvalue {
    Obj obj;
    Value* location;
    Value closed;
    struct ObjUpvalue* next;
} ObjUpvalue;
typedef struct {
    Obj obj;
    ObjFunction* function;
    ObjUpvalue** upvalues;
    int upvalueCount;
} ObjClosure;

typedef struct {
    Obj obj;
    ObjString* name;
//> Methods and Initializers class-methods
    Table methods;
//< Methods and Initializers class-methods
} ObjClass;


typedef struct {
    Obj obj;
    ObjClass* klass;
    Table fields; // [fields]
} ObjInstance;

typedef struct {
    Obj obj;
    Value receiver;
    ObjClosure* method;
} ObjBoundMethod;

ObjBoundMethod* newBoundMethod(Value receiver,
                               ObjClosure* method);

ObjClass* newClass(ObjString* name);

ObjClosure* newClosure(ObjFunction* function);

ObjFunction* newFunction();

ObjInstance* newInstance(ObjClass* klass);

ObjNative* newNative(NativeFn function);

ObjString* takeString(char* chars, int length);

ObjString* copyString(const char* chars, int length);

ObjUpvalue* newUpvalue(Value* slot);

void printObject(Value value);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}



#endif //ASSEMBLY_DO_OBJECT_H
