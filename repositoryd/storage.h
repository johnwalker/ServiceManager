#ifndef _STORAGE_H_
#define _STORAGE_H_

#include "uthash.h"

typedef struct entry_s
{
    enum
    {
        SVC,
        SVCI,
        PROP,
    } type;
    union
    {
        struct svc_s * svc;
        struct svc_instance_s * svci;
        struct property_s * prop;
    };
    UT_hash_handle hh;
} entry_t;

typedef struct svc_s
{
    unsigned int id;
    char * name;
} svc_t;

typedef struct svc_instance_s
{
    unsigned int id;
    unsigned int svc_id;
    char * name;
} svc_instance_t;

typedef struct property_s
{
    unsigned int id;
    unsigned int parent_id;
    enum
    {
        NUMBER,
        STRING
    } type;
    union
    {
        int i;
        char * s;
    } val;
} property_t;

#endif