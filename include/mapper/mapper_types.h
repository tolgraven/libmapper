#ifndef __MAPPER_TYPES_H__
#define __MAPPER_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

/*! This file defines opaque types that are used internally in libmapper. */

/*! An internal structure defining a mapper device. */
typedef void *mapper_device;

//! An internal structure defining a mapper signal.
typedef void *mapper_signal;

//! An internal structure defining a network connection between 2 devices.
typedef void *mapper_link;

//! An internal structure defining a mapping between a set of signals.
typedef void *mapper_map;

//! An internal structure defining a map endpoint.
typedef void *mapper_slot;

//! An internal structure defining an object to handle libmapper networking.
typedef void *mapper_network;

//! An internal structure to handle network database.
//! This can be retrieved by calling mapper_network_db() or mapper_device_db().
typedef void *mapper_database;

//! An internal data structure defining a mapper queue
//! Used to handle a queue of mapper signals
typedef void *mapper_queue;

//! An internal structure defining a grouping of mapper signals.
typedef int mapper_signal_group;

#ifdef __cplusplus
}
#endif

#endif // __MAPPER_TYPES_H__
