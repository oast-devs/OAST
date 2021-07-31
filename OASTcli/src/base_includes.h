#ifndef BASE_INCLUDES_H
#define BASE_INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data/oast_basic_types.h"
#include "data/oast_item_types.h"
#include "data/oast_output_types.h"

typedef struct oast_scenario {
	oast_object_t 		header;
	timestamp_t 		creation_date;
	oast_scenario_item_t *	scenario_item_list;
	oast_scenario_out_t *	output_list;
} oast_scenario_t;

#endif
