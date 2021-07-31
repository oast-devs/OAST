#ifndef OAST_ITEMS_TYPES_H
#define OAST_ITEMS_TYPES_H

#include "../base_includes.h"

typedef char * item_args_t;

typedef enum oast_item_type {
	SATELLITE,
	PLANE,
	PLANET,
	GENERIC
} oast_item_type_t;

typedef struct oast_scenario_item {
	oast_item_type_t	item_type;
	item_args_t		item_args;
} oast_scenario_item_t;

#endif

