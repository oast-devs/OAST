#ifndef OAST_BASIC_TYPES_H
#define OAST_BASIC_TYPES_H

#include "../base_includes.h"

typedef uint64_t timestamp_t;
typedef uint16_t oast_id_t

typedef struct oast_header {
	oast_id_t 		id;
	char			name[256];
	uint8_t 		oast_version;
	uint8_t 		api_version;
} oast_header_t;

typedef enum oast_coordinates_type {
	SPHERICAL_EARTH_CENTERED,
	SPHERICAL_SUN_CENTERED,
	LATLONHEIGHT
} oast_coordinates_type_t

typedef struct oast_coordinates {
	oast_coordinates_type_t coordinate_system;
	union {
		struct { 
			double rho;
			double theta;
			double r;
		} spherical;
		struct {
			double lat;
			double lon;
			double h;
		} latlon;
		uint8_t raw[3*sizeof(double)];
	} coordinates;
} oast_coordinates_t

#define GENERATE_SUN_SPHERICAL_COORD(name, rho, theta, r) \
	oast_coordinates_t (name) { \
		.coordinate_system = SPHERICAL_SUN_CENTERED, \
		.coordinates = {.rho=(rho), .theta=(theta), .r=(r)}\
	}

#define GENERATE_EARTH_SPHERICAL_COORD(name, rho, theta, r) \
	oast_coordinates_t (name) { \
		.coordinate_system = SPHERICAL_EARTH_CENTERED, \
		.coordinates = {.rho=(rho), .theta=(theta), .r=(r)}\
	}

#define GENERATE_LATLON_COORD(name, lat, lon, height) \
	oast_coordinates_t (name) { \
		.coordinate_system = LATLONHEIGHT, \
		.coordinates = {.lat=(lat), .lon=(lon), .h=(height)}\
	}

#endif

